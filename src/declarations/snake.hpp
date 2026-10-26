#pragma once

#include <deque>
#include <raylib.h>
#include <raymath.h>

class Snake {

    public:
    Snake();
    void calculateChanges(Vector2 targetPosition);
    void render();
    std::deque<Vector2> getDequeWithoutHead();
    std::deque<Vector2> body = {
                                    {10, 10},
                                    {9, 10},
                                    {8, 10},
                                };
    Vector2 movementDirection = {1, 0};
    void resetBody();
    int score = 0;



    private:
    Color darkPurple = {59, 2, 78, 255};
    float cellSize = 25;
    int xAxisOffset = 200;
    Vector2 moveRight = {1, 0};
    Vector2 moveLeft = {-1, 0};
    Vector2 moveUp = {0, -1};
    Vector2 moveDown = {0, 1};
    double timeLog = 0;
    double timeDelay = 0.08;
    bool isGrowing = false;
    


};