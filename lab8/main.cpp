#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 2.6 Shapes Lab");
    
    // 1. Круг с градиентом (новая фича SFML 3.0)
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({100.f, 100.f});
    
    // 2. Прямоугольник с текстурой
    sf::RectangleShape rectangle({120.f, 60.f});
    
    // Создаем простую текстуру программно
    sf::Image img;
    img.create(120, 60, sf::Color::Blue);
    for (unsigned y = 0; y < 60; ++y) {
        for (unsigned x = 0; x < 120; ++x) {
            if ((x + y) % 20 < 10) {
                img.setPixel(x, y, sf::Color::Yellow);
            }
        }
    }
    
    sf::Texture texture;
    texture.loadFromImage(img);
    rectangle.setTexture(&texture);
    rectangle.setPosition({400.f, 300.f});
    rectangle.setRotation(45.f);
    
    // 3. Треугольник с outline (используем VertexArray)
    sf::VertexArray triangle(sf::Triangles, 3);
    triangle[0].position = {0.f, 0.f};
    triangle[1].position = {100.f, 0.f};
    triangle[2].position = {50.f, 100.f};
    
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Green;
    triangle[2].color = sf::Color::Blue;
    
    sf::Transform triangleTransform;
    triangleTransform.translate(600.f, 150.f).rotate(15.f);
    
    // Главный цикл
    while (window.isOpen()) {
        for (sf::Event event; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.clear();
        
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle, triangleTransform);
        
        window.display();
    }
}