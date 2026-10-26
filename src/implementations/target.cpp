#include "../declarations/target.hpp"


Target::Target() {
    generateRandomPosition();
}

void Target::generateRandomPosition() {

    float x = GetRandomValue(0, numberOfCellsXAxis - 1);
    float y = GetRandomValue(0, numberOfCellsYAxis - 1);
    position = {x, y};

}

Vector2 Target::getPosition() {
    return position;
}

void Target::render() {

    DrawRectangleRounded(
                            {
                                (xAxisOffset + (position.x * cellSize) ),
                                (position.y * cellSize),
                                cellSize,
                                cellSize
                            },
                            0.5, 
                            8, 
                            green
                        );

}