#include <SFML/Graphics.hpp>
#define window_height 900
#define window_width 1100
#define length 300

namespace Atestat{
    void createShapes(sf::RectangleShape shapes[])
    {
        for(int i = 1;i<=3;i++)
        {
            for(int j = 1;j<=3;j++)
            {
                shapes[(i-1)*3 + (j-1)] = sf::RectangleShape(sf::Vector2f(length,length));
                shapes[(i-1)*3 + (j-1)].setPosition(sf::Vector2f((i-1)*length,(j-1)*length));
                shapes[(i-1)*3 + (j-1)].setFillColor(sf::Color::White);
                shapes[(i-1)*3 + (j-1)].setOutlineColor(sf::Color::Black);
                shapes[(i-1)*3 + (j-1)].setOutlineThickness(1);
            }
        }
    }

    void drawShapes(sf::RenderWindow &window, sf::RectangleShape shapes[])
    {
        for(int i = 0;i<9;i++)
        {
            window.draw(shapes[i]);
        }
    }

    sf::Texture createTexture(std::string name, bool q)
    {
        sf::Texture texture;
        texture.setSmooth(q);
        texture.loadFromFile(name);
        return texture;
    }
    sf::RectangleShape createRectangle (int z,int w,sf::Texture &texture)
    {
        sf::RectangleShape rectangle(sf::Vector2f(window_height/2,length-100));
        rectangle.setPosition(sf::Vector2f(z,w));
        rectangle.setOutlineThickness(1);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setTexture(&texture);

        return rectangle;

    }
}
