#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class PongGame {
public:
    PongGame();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void resetBall();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow mWindow;
    sf::RectangleShape mLeftPaddle;
    sf::RectangleShape mRightPaddle;
    sf::CircleShape mBall;
    sf::Font mFont;
    sf::Text mLeftScoreText;
    sf::Text mRightScoreText;
    
    int mLeftScore = 0;
    int mRightScore = 0;
    sf::Vector2f mBallVelocity;
    
    bool mIsLeftPaddleUp = false;
    bool mIsLeftPaddleDown = false;
    const float mPaddleSpeed = 400.f;
    const float mBallSpeed = 900.f;
    bool mBallPaused = false;
};