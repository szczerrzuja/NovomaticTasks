// NovomaticTask3.cpp : Defines the entry point for the application.
//

#include "NovomaticTask3.h"
#include "UserInterface.h"

using namespace std;

void drawTriangle(triangle t, sf::Color color, sf::VertexArray& output)
{
 
    output[0].position = sf::Vector2f(t.points[0].x, t.points[0].y);
    output[1].position = sf::Vector2f(t.points[1].x, t.points[1].y);
    output[2].position = sf::Vector2f(t.points[2].x, t.points[2].y);
    output[0].color = color;
    output[1].color = color;
    output[2].color = color;
    


}


int main()
{
    triangle t1 = { vec2(8, 3) , vec2(9, 32) , vec2(24, 5) };

    triangle t2 = { vec2(9, 4) , vec2(16, 45) , vec2(32, 16) };
    triangle t3 = { vec2(100,100) , vec2(100, 200) , vec2(300, 100) };
    int t = isColliding(t1, t3);
    std::cout << t;

    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML works!");

    sf::VertexArray s1(sf::Triangles, 3);
    sf::VertexArray s2(sf::Triangles, 3);

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(50,50,50,255));
        drawTriangle(t1, sf::Color::Blue, s1);
        drawTriangle(t3, sf::Color::Green, s2);

        window.draw(s1);
        window.draw(s2);


        window.display();


    }

    return 0;
}
