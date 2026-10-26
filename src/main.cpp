#include <raylib.h>

#include "./declarations/target.hpp"
#include "./declarations/snake.hpp"


int main() 
{

    char* current_window = "start";

    Vector2 mousePosition = GetMousePosition();
    Color playButtonColor = DARKGRAY;
    Color aboutButtonColor = DARKGRAY;
    Color backButtonColor = DARKPURPLE;
    Color playAgainButtonColor = DARKGRAY;

    Rectangle playButton = {575, 200, 300, 120};
    Rectangle aboutButton = {575, 400, 300, 120};
    Rectangle backButton = {20, 20, 300, 80};
    Rectangle playAgainButton = {515, 400, 450, 120};

    
    int screenWidth = 1500;
    int screenHeight = 900;

    Color purple = {134, 16, 175, 255};
    Color plum = {73, 2, 62, 255};

    // grid starts @ 200 x-axis, 0 y-axis
    // x-axis: 1300px (make sure to offset the x-axis by 200px)
    // y-axis: 900px

    // cell size
    // 25 (width & height are 25px)

    // number of cells
    // 52 in the x-axis (52 * 25 = 1300px)
    // 36 in the y-axis (36 * 25 = 900px)
    
    
    Target target = Target();
    Snake snake;
    
    InitWindow(screenWidth, screenHeight, "Snake");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();

        if(current_window == "start") {
            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                    current_window = "game";

                }

                if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                    current_window = "about";
                }
            }
            
            if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                playButtonColor = GRAY;
            }
            else {
                playButtonColor = DARKGRAY;
            }

            

            if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                aboutButtonColor = GRAY;
            }
            else {
                aboutButtonColor = DARKGRAY;
            }

            DrawRectangleRounded(playButton, 1, 0, playButtonColor);
            DrawText("PLAY", 670, 245, 40, BLACK);

            DrawRectangleRounded(aboutButton, 1, 0, aboutButtonColor);
            DrawText("ABOUT", 660, 445, 40, BLACK);

        }
        
        if(current_window == "about") {

            ClearBackground(LIGHTGRAY);
            
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                    current_window = "start";

                }

            }

            if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                backButtonColor = PURPLE;
            }
            else {
                backButtonColor = DARKPURPLE;
            }

            DrawText("Created By Mohamed Dahir.", 550, 400, 30, BLACK);
            DrawText("© MMXXVI", 675, 450, 30, BLACK);

            DrawRectangleRounded(backButton, 1, 0, backButtonColor);
            DrawText("BACK", 115, 45, 40, BLACK);

        }

        if(current_window == "game"){

            ClearBackground(purple);
            DrawRectangleV({0,0}, {200, GetScreenHeight()}, plum);

            snake.calculateChanges(target.position);

            if(Vector2Equals(snake.body[0], target.position) ) {
                snake.body.push_front(Vector2Add(snake.body[0], snake.movementDirection));


                target.generateRandomPosition();
                snake.score++;
            }

            if(snake.body[0].x == target.numberOfCellsXAxis || snake.body[0].x == -1) {
                current_window = "game_over";
                snake.resetBody();
                snake.movementDirection = {1,0};
                snake.score = 0;
            }

            if(snake.body[0].y == target.numberOfCellsYAxis || snake.body[0].y == -1) {
                current_window = "game_over";
                snake.resetBody();
                snake.movementDirection = {1,0};
                snake.score = 0;
            }

            for(auto elment : snake.getDequeWithoutHead()) {
                if(Vector2Equals(elment, snake.body[0])) {
                    current_window = "game_over";
                    snake.resetBody();
                    snake.movementDirection = {1,0};
                    snake.score = 0;
                }
            }

            target.render();
            snake.render();

            DrawText("Score", 25, ((GetScreenHeight() / 2) - 150), 50, WHITE);
            DrawText(TextFormat("%i", snake.score), 80, ((GetScreenHeight() / 2) - 50), 60, WHITE);
            
        }

         if(current_window == "game_over") {

            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){


                if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                    current_window = "game";
                }

            }
            
                        
            if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                playAgainButtonColor = GRAY;
            }
            else {
                playAgainButtonColor = DARKGRAY;
            }


            DrawText("Game Over", 550, 245, 75, BLACK);

            DrawRectangleRounded(playAgainButton, 1, 0, playAgainButtonColor);
            DrawText("PLAY AGAIN", 620, 445, 40, BLACK);

        }

        EndDrawing();

    }
    
    CloseWindow();
}