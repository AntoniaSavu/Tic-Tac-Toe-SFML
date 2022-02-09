#include "initializer.h"
#include <iostream>
#include <cstring>
#define window_height 900
#define window_width 1100
#define length 300
int matrix[10][10], playerTurn, k, l, ok, winner = -1, z;
int main()
{
    sf::Texture restart = Atestat::createTexture("reset.png", true);
    sf::Texture exit = Atestat::createTexture("exit.jpg", true);
    sf::Texture whites = Atestat::createTexture("white.jpg", true);
    sf::Texture xwin = Atestat::createTexture("wins.png", true);
    sf::Texture zero = Atestat::createTexture("zero.png", true);
    sf::Texture texture = Atestat::createTexture("X.png", true);
    sf::Texture texture1 = Atestat::createTexture("0.png", true);

    sf::RenderWindow window(sf::VideoMode(window_height, window_width), "X si 0!");

    sf::RectangleShape shapes[9];
    Atestat::createShapes(shapes);

    sf::RectangleShape reset = Atestat::createRectangle(0, window_height, restart);
    sf::RectangleShape exit1 = Atestat::createRectangle(window_height / 2, window_height, exit);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {

                int row = event.mouseButton.x / length;
                int column = event.mouseButton.y / length;

                if (matrix[column][row] == 0 && winner == -1)
                {
                    matrix[column][row] = playerTurn % 2 + 1;
                    if (playerTurn % 2)
                        shapes[row * 3 + column].setTexture(&texture1);
                    else
                        shapes[row * 3 + column].setTexture(&texture);
                    playerTurn++;
                }

                if (event.mouseButton.x <= 449 && event.mouseButton.x >= 0 && event.mouseButton.y <= 1099 && event.mouseButton.y >= 900)
                {
                    for (int i = 0; i < 9; i++)
                        shapes[i].setTexture(&whites);
                    for (k = 0; k < 3; k++)
                        for (l = 0; l < 3; l++)
                            matrix[k][l] = 0;
                    playerTurn = 0;
                    winner = -1;
                }

                if (event.mouseButton.x <= 899 && event.mouseButton.x >= 450 && event.mouseButton.y <= 1099 && event.mouseButton.y >= 900)
                    return 1;
            }
        }
        for (k = 0; k < 3; k++)
        {
            ok = 1;
            if (matrix[k][0])
            {
                z = matrix[k][0];
                for (l = 1; l < 3; l++)
                    if (z != matrix[k][l])
                        ok = 0;
                if (ok == 1 && winner == -1)
                {
                    winner = z;
                    if (winner == 1)
                        for (l = 0; l < 3; l++)
                            shapes[l * 3 + k].setTexture(&xwin);
                    else
                        for (l = 0; l < 3; l++)
                            shapes[l * 3 + k].setTexture(&zero);

                    break;
                }
            }
        }
        for (k = 0; k < 3; k++)
        {
            ok = 1;
            if (matrix[0][k])
            {
                z = matrix[0][k];
                for (l = 1; l < 3; l++)
                    if (z != matrix[l][k])
                        ok = 0;
                if (ok == 1 && winner == -1)
                {
                    winner = z;
                    if (winner == 1)
                        for (l = 0; l < 3; l++)
                            shapes[k * 3 + l].setTexture(&xwin);
                    else
                        for (l = 0; l < 3; l++)
                            shapes[k * 3 + l].setTexture(&zero);

                    break;
                }
            }
        }

        ok = 1;
        for (k = 1; k < 3; k++)
        {

            if (matrix[k][k] != matrix[0][0] || !matrix[k][k])
            {
                ok = 0;
                break;
            }
        }

        for (k = 1; k < 3; k++)
        {
            if (ok == 1 && winner == -1)
            {
                winner = matrix[k][k];
                if (winner == 1)
                    for (l = 0; l < 3; l++)
                        shapes[l * 4].setTexture(&xwin);
                else
                    for (l = 0; l < 3; l++)
                        shapes[l * 4].setTexture(&zero);

                break;
            }
        }

        ok = 1;
        for (k = 1; k < 3; k++)
        {

            if (matrix[k][3 - k - 1] != matrix[0][2] || matrix[k][3 - k - 1] == 0)
            {
                ok = 0;
                break;
            }
        }

        for (k = 1; k < 3; k++)
        {
            if (ok == 1 && winner == -1)
            {
                winner = matrix[0][2];
                if (winner == 1)
                    for (l = 0; l < 3; l++)
                        shapes[l * 2 + 2].setTexture(&xwin);
                else
                    for (l = 0; l < 3; l++)
                        shapes[l * 2 + 2].setTexture(&zero);

                break;
            }
        }

        window.clear();
        Atestat::drawShapes(window, shapes);
        window.draw(reset);
        window.draw(exit1);
        window.display();
    }
    return 0;
}
