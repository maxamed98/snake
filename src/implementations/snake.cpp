#include "../declarations/snake.hpp"


Snake::Snake() {

}


void Snake::calculateChanges(Vector2 targetPosition) {

    if(GetTime() - timeLog >= timeDelay){
        timeLog = GetTime();
            
        body.pop_back();
        body.push_front(Vector2Add(body[0], movementDirection));
        
        if(IsKeyDown(KEY_RIGHT) && (movementDirection != Vector2{-1, 0}) ) {
            movementDirection = moveRight;
        }

        if(IsKeyDown(KEY_LEFT) && (movementDirection != Vector2{1, 0}) ) {
            movementDirection = moveLeft;
        }

        if(IsKeyDown(KEY_UP) && (movementDirection != Vector2{0, 1}) ) {
            movementDirection = moveUp;
        }

        if(IsKeyDown(KEY_DOWN) && (movementDirection != Vector2{0, -1}) ) {
            movementDirection = moveDown;
        }

    }

}


std::deque<Vector2> Snake::getDequeWithoutHead() {
    std::deque<Vector2> withoutHead = body;
    withoutHead.pop_front();
    return withoutHead;
}

void Snake::resetBody() {
    body.clear();
    body.push_back({10, 10});
    body.push_back({9, 10});
    body.push_back({8, 10});
}

void Snake::render() {

    for(auto vector : body) {
        DrawRectangleRounded(
                                {
                                    xAxisOffset + (vector.x * cellSize),
                                    vector.y * cellSize,
                                    cellSize,
                                    cellSize
                                },
                                 1, 
                                 20, 
                                 darkPurple
                            );
    }

}