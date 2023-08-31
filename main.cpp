#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <math.h>

using namespace sf;

struct Point{
    float x,y;
};

struct Face{
    Vertex l1[2];
    Vertex l2[2];
    Vertex l3[2];
    Vertex l4[2];
};


float height = 100.0f;

// Point A it's going to be modified
void rotatePoint(Point& pointB, Point& pointA, float angle){
    float xNew = 100 * cos(angle) + pointA.x;
    float yNew = 100 / 10 * sin(angle) + pointA.y;
    pointB.x = xNew;
    pointB.y = yNew;
    std::cout << pointB.x << " " << pointB.y << std::endl;
}

float getRadians(float angle){
    return angle * M_PI / 180.0f;
}

int main() {
    RenderWindow window(VideoMode(800, 600), "Cube Rotating");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        Point center = {400.0f, 300.0f};

        // Starting point
        Point a = {500.0f, 550.0f};
        Point b = {550.0f, 550.0f};
        Point c = {500.0f, 500.0f};
        Point d = {550.0f, 500.0f};

        float length = 100.0f;
        
        float angleA = 90.0f;
        float angleB = 0.0f;
        float angleC = -90.0f;
        float angleD = 180.0f;

        Vertex line[] = {
            Vertex(Vector2f(a.x, a.y)),
            Vertex(Vector2f(b.x, b.y))
        };

        Vertex line2[] = {
            Vertex(Vector2f(c.x, c.y)),
            Vertex(Vector2f(d.x, d.y))
        };

        Vertex line3[] = {
            Vertex(Vector2f(a.x, a.y)),
            Vertex(Vector2f(c.x, c.y))
        };
        Vertex line4[] = {
            Vertex(Vector2f(a.x, a.y)),
            Vertex(Vector2f(c.x, c.y))
        };

        Face face = {
            line[2],
            line2[2],
            line3[2],
            line4[2]
        };

        while(true){
            window.clear();

            angleA += 2.0f;
            angleB += 2.0f;
            angleC += 2.0f;
            angleD += 2.0f;

            //std::cout << cos(getRadians(angleA)) << std::endl;

            Point centerTopFace = {center.x, center.y - height};

            rotatePoint(a, centerTopFace, getRadians(angleA));
            rotatePoint(b, centerTopFace, getRadians(angleB));

            rotatePoint(c, centerTopFace, getRadians(angleC));
            rotatePoint(d, centerTopFace, getRadians(angleD));

            face.l1[0] = Vertex(Vector2f(a.x, a.y));
            face.l1[1] = Vertex(Vector2f(b.x, b.y));

            face.l2[0] = Vertex(Vector2f(c.x, c.y));
            face.l2[1] = Vertex(Vector2f(d.x, d.y));

            face.l3[0] = Vertex(Vector2f(a.x, a.y));
            face.l3[1] = Vertex(Vector2f(d.x, d.y));

            face.l4[0] = Vertex(Vector2f(b.x, b.y)); 
            face.l4[1] = Vertex(Vector2f(c.x, c.y));       

            window.draw(face.l1, 2, Lines);
            window.draw(face.l2, 2, Lines);
            window.draw(face.l3, 2, Lines);
            window.draw(face.l4, 2, Lines);

            window.display();

            sleep(seconds(0.05f));
        }

        /*
        // Draw a square
        Vertex square[] = {
            Vertex(Vector2f(200, 200)),
            Vertex(Vector2f(300, 200)),
            Vertex(Vector2f(300, 300)),
            Vertex(Vector2f(200, 300))
        };

        // Change the color of the entire square
        for (int i = 0; i < 4; i++) {
            square[i].color = Color::Red;
        }

        window.draw(square, 4, Quads);
        */

    }

    return 0;
}