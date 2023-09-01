#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <math.h>

using namespace sf;

struct Point{
    float x,y;
};


float height = 100.0f;
float zAngle = 2.0f;
Point center = {400.0f, 300.0f};

Point* calculateCenter();

// Point A it's going to be modified
void rotatePoint(Point& pointB, Point& pointA, float angle);

void rotateAll(Point* vertices, Point* centers, float* angles);

void drawLines(RenderWindow& window, Vertex lines[][2]);

float getRadians(float angle);

void calculateLines(Vertex lines[][2]);

int main() {
    RenderWindow window(VideoMode(800, 600), "Cube Rotating");

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        Point* vertices = new Point[8];

        float length = 100.0f;

        float angles[4] = {
            90.0f,
            0.0f,
            -90.0f,
            180.f,
        };

        Vertex lines[12][2];

        while(true){
            window.clear();

            angles[0] += 2.0f;
            angles[1] += 2.0f;
            angles[2] += 2.0f;
            angles[3] += 2.0f;

            rotateAll(vertices, calculateCenter(), angles);

            calculateLines(lines);

            lines[2][0] = Vertex(Vector2f(vertices[0].x, vertices[0].y));
            lines[0][0] = Vertex(Vector2f(vertices[0].x, vertices[0].y));
            lines[8][1] = Vertex(Vector2f(vertices[0].x, vertices[0].y));

            lines[0][1] = Vertex(Vector2f(vertices[1].x, vertices[1].y));
            lines[3][0] = Vertex(Vector2f(vertices[1].x, vertices[1].y));
            lines[11][1] = Vertex(Vector2f(vertices[1].x, vertices[1].y));

            lines[3][1] = Vertex(Vector2f(vertices[2].x, vertices[2].y)); 
            lines[1][0] = Vertex(Vector2f(vertices[2].x, vertices[2].y));
            lines[9][1] = Vertex(Vector2f(vertices[2].x, vertices[2].y));

            lines[1][1] = Vertex(Vector2f(vertices[3].x, vertices[3].y));
            lines[2][1] = Vertex(Vector2f(vertices[3].x, vertices[3].y));
            lines[10][1] = Vertex(Vector2f(vertices[3].x, vertices[3].y));

            lines[6][0] = Vertex(Vector2f(vertices[4].x, vertices[4].y));
            lines[4][0] = Vertex(Vector2f(vertices[4].x, vertices[4].y));
            lines[8][0] = Vertex(Vector2f(vertices[4].x, vertices[4].y));

            lines[4][1] = Vertex(Vector2f(vertices[5].x, vertices[5].y));
            lines[7][0] = Vertex(Vector2f(vertices[5].x, vertices[5].y));
            lines[11][0] = Vertex(Vector2f(vertices[5].x, vertices[5].y));

            lines[7][1] = Vertex(Vector2f(vertices[6].x, vertices[6].y));  
            lines[5][0] = Vertex(Vector2f(vertices[6].x, vertices[6].y));
            lines[9][0] = Vertex(Vector2f(vertices[6].x, vertices[6].y));

            lines[5][1] = Vertex(Vector2f(vertices[7].x, vertices[7].y));
            lines[6][1] = Vertex(Vector2f(vertices[7].x, vertices[7].y));
            lines[10][0] = Vertex(Vector2f(vertices[7].x, vertices[7].y));    

            drawLines(window, lines);       

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
    float yNew = 100 / sin(zAngle) * sin(angle) + pointA.y;
    pointB.x = xNew;
    pointB.y = yNew;
}

void rotateAll(Point* vertices, Point* centers, float* angles){
    uint k = 0;
    for(uint i = 0; i < 8; i++){
        if(i>3){
            k = 1;
        }
        rotatePoint(vertices[i], centers[k], getRadians(angles[i%4]));
    }
}

Point* calculateCenter(){
    Point* centerTB = new Point[2];
    centerTB[0] = {center.x, center.y - height/2};
    centerTB[1] = {center.x, center.y + height};

    return centerTB;
}

void calculateLines(Vertex lines[][2]){
    
}

void drawLines(RenderWindow& window, Vertex lines[][2]){
    for(uint i = 0; i < 12; i++) window.draw(lines[i], 2, Lines);
}

float getRadians(float angle){
    return angle * M_PI / 180.0f;
}