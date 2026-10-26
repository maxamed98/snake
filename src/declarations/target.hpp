#pragma once

#include <raylib.h>

#include <cstdlib>

class Target {

    public:
    Target();
    void generateRandomPosition();
    void render();
    Vector2 getPosition();
    Vector2 position;
    int numberOfCellsXAxis = 52;
    int numberOfCellsYAxis = 36;
    
    private:
    float cellSize = 25;
    int xAxisOffset = 200;
    Color green = {0, 80, 40, 255};

};