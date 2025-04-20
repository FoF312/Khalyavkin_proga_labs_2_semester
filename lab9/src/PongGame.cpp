#include "PongGame.h"
#include <iostream>

PongGame::PongGame()
    : mWindow(sf::VideoMode(800, 600), "SFML Pong")
    , mLeftPaddle(sf::Vector2f(20.f, 100.f))
    , mRightPaddle(sf::Vector2f(20.f, 100.f))
    , mBall(10.f)
{
    // Настройка платформ
    mLeftPaddle.setFillColor(sf::Color::Blue);
    mLeftPaddle.setPosition(50.f, 250.f);
    
    mRightPaddle.setFillColor(sf::Color::Red);
    mRightPaddle.setPosition(730.f, 250.f);
    
    // Настройка мяча
    mBall.setFillColor(sf::Color::White);
    resetBall();
    
    // Настройка текста
    bool fontLoaded = false;
    if (!mFont.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Failed to load font from resources, trying system font..." << std::endl;
        if (!mFont.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
            std::cerr << "Failed to load system font" << std::endl;
        } else {
            fontLoaded = true;
            std::cout << "System font loaded successfully" << std::endl;
        }
    } else {
        fontLoaded = true;
        std::cout << "Resource font loaded successfully" << std::endl;
    }
    
    if (fontLoaded) {
        mLeftScoreText.setFont(mFont);
        mLeftScoreText.setString("0");
        mLeftScoreText.setCharacterSize(30);
        mLeftScoreText.setPosition(200.f, 20.f);
        mLeftScoreText.setFillColor(sf::Color::White);
        
        mRightScoreText.setFont(mFont);
        mRightScoreText.setString("0");
        mRightScoreText.setCharacterSize(30);
        mRightScoreText.setPosition(600.f, 20.f);
        mRightScoreText.setFillColor(sf::Color::White);
        
        std::cout << "Score text initialized" << std::endl;
    } else {
        std::cerr << "Failed to initialize score text - font not loaded" << std::endl;
    }
}

void PongGame::run() {
    sf::Clock clock;
    while (mWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void PongGame::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                if (mBallPaused) {
                    mBallPaused = false;
                    resetBall();
                }
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
        }
    }
}

void PongGame::update(sf::Time deltaTime) {
    // Движение левой платформы (игрок)
    sf::Vector2f leftMovement(0.f, 0.f);
    if (mIsLeftPaddleUp)
        leftMovement.y -= mPaddleSpeed;
    if (mIsLeftPaddleDown)
        leftMovement.y += mPaddleSpeed;
    mLeftPaddle.move(leftMovement * deltaTime.asSeconds());
    
    // ИИ правой платформы (простой компьютер)
    if (!mBallPaused) {  // ИИ двигается только если мяч не на паузе
        if (mRightPaddle.getPosition().y + 50 > mBall.getPosition().y && 
            mRightPaddle.getPosition().y > 0) {
            mRightPaddle.move(0.f, -mPaddleSpeed * 0.7f * deltaTime.asSeconds());
        }
        if (mRightPaddle.getPosition().y + 50 < mBall.getPosition().y && 
            mRightPaddle.getPosition().y + 100 < mWindow.getSize().y) {
            mRightPaddle.move(0.f, mPaddleSpeed * 0.7f * deltaTime.asSeconds());
        }
    }
    
    // Ограничение платформ в пределах экрана
    auto clampPaddle = [this](sf::RectangleShape& paddle) {
        if (paddle.getPosition().y < 0)
            paddle.setPosition(paddle.getPosition().x, 0.f);
        if (paddle.getPosition().y + paddle.getSize().y > mWindow.getSize().y)
            paddle.setPosition(paddle.getPosition().x, mWindow.getSize().y - paddle.getSize().y);
    };
    
    clampPaddle(mLeftPaddle);
    clampPaddle(mRightPaddle);
    
    // Движение мяча только если он не на паузе
    if (!mBallPaused) {
        mBall.move(mBallVelocity * deltaTime.asSeconds());
        
        // Столкновение с верхом и низом
        if (mBall.getPosition().y <= 0 || mBall.getPosition().y + mBall.getRadius()*2 >= mWindow.getSize().y)
            mBallVelocity.y = -mBallVelocity.y;
        
        // Столкновение с платформами
        if (mBall.getGlobalBounds().intersects(mLeftPaddle.getGlobalBounds())) {
            mBallVelocity.x = std::abs(mBallVelocity.x);
            float hitPosition = (mBall.getPosition().y - mLeftPaddle.getPosition().y) / 100.f - 0.5f;
            mBallVelocity.y = hitPosition * mBallSpeed * 0.7f;
        }
        
        if (mBall.getGlobalBounds().intersects(mRightPaddle.getGlobalBounds())) {
            mBallVelocity.x = -std::abs(mBallVelocity.x);
            float hitPosition = (mBall.getPosition().y - mRightPaddle.getPosition().y) / 100.f - 0.5f;
            mBallVelocity.y = hitPosition * mBallSpeed * 0.7f;
        }
    }
    
    // Гол забит
    if (mBall.getPosition().x < 0) {
        mRightScore++;
        std::string scoreStr = std::to_string(mRightScore);
        mRightScoreText.setString(scoreStr);
        std::cout << "Right score updated to: " << scoreStr << std::endl;
        mBallPaused = true;  // Ставим мяч на паузу
        mBall.setPosition(400.f, 300.f);  // Возвращаем мяч в центр
        mBallVelocity = sf::Vector2f(0.f, 0.f);  // Останавливаем мяч
    }
    
    if (mBall.getPosition().x > mWindow.getSize().x) {
        mLeftScore++;
        std::string scoreStr = std::to_string(mLeftScore);
        mLeftScoreText.setString(scoreStr);
        std::cout << "Left score updated to: " << scoreStr << std::endl;
        mBallPaused = true;  // Ставим мяч на паузу
        mBall.setPosition(400.f, 300.f);  // Возвращаем мяч в центр
        mBallVelocity = sf::Vector2f(0.f, 0.f);  // Останавливаем мяч
    }
}

void PongGame::render() {
    mWindow.clear(sf::Color::Black);
    
    // Центральная линия
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(400.f, 0.f);
    line[1].position = sf::Vector2f(400.f, 600.f);
    line[0].color = sf::Color(70, 70, 70);
    line[1].color = sf::Color(70, 70, 70);
    mWindow.draw(line);
    
    mWindow.draw(mLeftPaddle);
    mWindow.draw(mRightPaddle);
    mWindow.draw(mBall);
    
    // Проверяем, что текст счета инициализирован
    if (mLeftScoreText.getFont() != nullptr) {
        mWindow.draw(mLeftScoreText);
    }
    if (mRightScoreText.getFont() != nullptr) {
        mWindow.draw(mRightScoreText);
    }
    
    mWindow.display();
}

void PongGame::resetBall() {
    mBall.setPosition(400.f, 300.f);
    // Случайное направление
    float angle = (std::rand() % 60 - 30) * 3.14159f / 180.f;
    mBallVelocity = sf::Vector2f(std::cos(angle), std::sin(angle)) * mBallSpeed;
    // Случайное направление влево или вправо
    if (std::rand() % 2 == 0)
        mBallVelocity.x = -mBallVelocity.x;
    mBallPaused = false;  // Снимаем паузу при сбросе мяча
}

void PongGame::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        mIsLeftPaddleUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsLeftPaddleDown = isPressed;
    else if (key == sf::Keyboard::Escape)
        mWindow.close();
}