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

float height = 75.0f;

void printFace(Face face, float center);

// Point A it's going to be modified
void rotatePoint(Point& pointB, Point& pointA, float angle);

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

        Point e = {500.0f, 650.0f};
        Point f = {550.0f, 650.0f};
        Point g = {500.0f, 600.0f};
        Point h = {550.0f, 600.0f};

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

        Face faceUP = {
            line[2],
            line2[2],
            line3[2],
            line4[2]
        };

        Vertex line5[] = {
            Vertex(Vector2f(e.x, e.y)),
            Vertex(Vector2f(f.x, f.y))
        };

        Vertex line6[] = {
            Vertex(Vector2f(g.x, g.y)),
            Vertex(Vector2f(h.x, h.y))
        };

        Vertex line7[] = {
            Vertex(Vector2f(e.x, e.y)),
            Vertex(Vector2f(g.x, g.y))
        };
        Vertex line8[] = {
            Vertex(Vector2f(e.x, e.y)),
            Vertex(Vector2f(g.x, g.y))
        };

        Face faceBottom = {
            line5[2],
            line6[2],
            line7[2],
            line8[2]
        };

        Vertex line9[] = {
            Vertex(Vector2f(e.x, e.y)),
            Vertex(Vector2f(a.x, a.y))
        };

        Vertex line10[] = {
            Vertex(Vector2f(g.x, g.y)),
            Vertex(Vector2f(b.x, b.y))
        };

        Vertex line11[] = {
            Vertex(Vector2f(e.x, e.y)),
            Vertex(Vector2f(c.x, c.y))
        };
        Vertex line12[] = {
            Vertex(Vector2f(e.x, e.y)),
            Vertex(Vector2f(d.x, d.y))
        };

        Face FrontBackFaces = {
            line9[2],
            line10[2],
            line11[2],
            line12[2]
        };

        while(true){
            window.clear();

            angleA += 2.0f;
            angleB += 2.0f;
            angleC += 2.0f;
            angleD += 2.0f;

            //std::cout << cos(getRadians(angleA)) << std::endl;

            Point centerTopFace = {center.x, center.y - height};
            Point centerBottomFace = {center.x, center.y + height};

            rotatePoint(a, centerTopFace, getRadians(angleA));
            rotatePoint(b, centerTopFace, getRadians(angleB));
            rotatePoint(c, centerTopFace, getRadians(angleC));
            rotatePoint(d, centerTopFace, getRadians(angleD));

            rotatePoint(e, centerBottomFace, getRadians(angleA));
            rotatePoint(f, centerBottomFace, getRadians(angleB));
            rotatePoint(g, centerBottomFace, getRadians(angleC));
            rotatePoint(h, centerBottomFace, getRadians(angleD));

            faceUP.l1[0] = Vertex(Vector2f(a.x, a.y));
            faceUP.l1[1] = Vertex(Vector2f(b.x, b.y));

            faceUP.l2[0] = Vertex(Vector2f(c.x, c.y));
            faceUP.l2[1] = Vertex(Vector2f(d.x, d.y));

            faceUP.l3[0] = Vertex(Vector2f(a.x, a.y));
            faceUP.l3[1] = Vertex(Vector2f(d.x, d.y));

            faceUP.l4[0] = Vertex(Vector2f(b.x, b.y)); 
            faceUP.l4[1] = Vertex(Vector2f(c.x, c.y));   

            faceBottom.l1[0] = Vertex(Vector2f(e.x, e.y));
            faceBottom.l1[1] = Vertex(Vector2f(f.x, f.y));

            faceBottom.l2[0] = Vertex(Vector2f(g.x, g.y));
            faceBottom.l2[1] = Vertex(Vector2f(h.x, h.y));

            faceBottom.l3[0] = Vertex(Vector2f(e.x, e.y));
            faceBottom.l3[1] = Vertex(Vector2f(h.x, h.y));

            faceBottom.l4[0] = Vertex(Vector2f(f.x, f.y)); 
            faceBottom.l4[1] = Vertex(Vector2f(g.x, g.y)); 

            FrontBackFaces.l1[0] = Vertex(Vector2f(e.x, e.y));
            FrontBackFaces.l1[1] = Vertex(Vector2f(a.x, a.y));

            FrontBackFaces.l2[0] = Vertex(Vector2f(g.x, g.y));
            FrontBackFaces.l2[1] = Vertex(Vector2f(c.x, c.y));

            FrontBackFaces.l3[0] = Vertex(Vector2f(h.x, h.y));
            FrontBackFaces.l3[1] = Vertex(Vector2f(d.x, d.y));

            FrontBackFaces.l4[0] = Vertex(Vector2f(f.x, f.y)); 
            FrontBackFaces.l4[1] = Vertex(Vector2f(b.x, b.y)); 

            window.draw(faceUP.l1, 2, Lines);
            window.draw(faceUP.l2, 2, Lines);
            window.draw(faceUP.l3, 2, Lines);
            window.draw(faceUP.l4, 2, Lines);

            window.draw(faceBottom.l1, 2, Lines);
            window.draw(faceBottom.l2, 2, Lines);
            window.draw(faceBottom.l3, 2, Lines);
            window.draw(faceBottom.l4, 2, Lines);

            window.draw(FrontBackFaces.l1, 2, Lines);
            window.draw(FrontBackFaces.l2, 2, Lines);
            window.draw(FrontBackFaces.l3, 2, Lines);
            window.draw(FrontBackFaces.l4, 2, Lines);

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

// Point A it's going to be modified
void rotatePoint(Point& pointB, Point& pointA, float angle){
    float xNew = 100 * cos(angle) + pointA.x;
    float yNew = 100 / 2 * sin(angle) + pointA.y;
    pointB.x = xNew;
    pointB.y = yNew;
    //std::cout << pointB.x << " " << pointB.y << std::endl;
}

void printFace(){
    
}