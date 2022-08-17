#include "raylib.h"

int main()
{
    // window dimensions
    int width{800}, height{450};
    const char * title = "Harry's Window";
    InitWindow(width,height,title);

    // circle stuff

    // coordinates
    int circleX { 200 }, circleY { 200 }, circleRadius { 25 };
    // edges
    int leftCircleXEdge { circleX - circleRadius }, rightCircleXEdge { circleX + circleRadius },
        upperCircleYEdge { circleY - circleRadius }, bottomCircleYEdge { circleY + circleRadius }; 
    // movement
    int circleSpeed{5};

    // axe Stuff

    // coordinates
    int axeX { 400 }, axeY { 0 }, axeLength { 50 };
    // edges
    int leftAxeXEdge { axeX }, rightAxeXEdge { axeX + axeLength },
        upperAxeYEdge { axeY }, bottomAxeYEdge {axeY + axeLength };
    // movement
    int direction{10};

    // game stuff
    bool collisionWithAxe = 
                            (bottomAxeYEdge >= upperCircleYEdge) &&
                            (upperAxeYEdge <= bottomCircleYEdge) &&
                            (leftAxeXEdge <= rightCircleXEdge) &&
                            (rightAxeXEdge >= leftCircleXEdge);

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
     
        ClearBackground(WHITE);

        if(collisionWithAxe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
        // Game logic begins

        // update the edges
        leftCircleXEdge = circleX - circleRadius; rightCircleXEdge = circleX + circleRadius;
        upperCircleYEdge = circleY - circleRadius; bottomCircleYEdge = circleY + circleRadius;

        leftAxeXEdge = axeX; rightAxeXEdge = axeX + axeLength;
        upperAxeYEdge = axeY; bottomAxeYEdge = axeY + axeLength;

        // update collision with axe
        collisionWithAxe = 
                        (bottomAxeYEdge >= upperCircleYEdge) &&
                        (upperAxeYEdge <= bottomCircleYEdge) &&
                        (leftAxeXEdge <= rightCircleXEdge) &&
                        (rightAxeXEdge >= leftCircleXEdge);
     
        DrawCircle(circleX, circleY, circleRadius, BLUE);
        DrawRectangle(axeX,axeY, axeLength, axeLength, RED);

        // move the axe
        axeY += direction;
        if(axeY > height-50 || axeY < 0 ){ direction = - direction; }

        if(IsKeyDown(KEY_W) && (circleY > circleRadius)) { circleY -= circleSpeed; }                // UP
        if(IsKeyDown(KEY_A) && (circleX > circleRadius)) { circleX -= circleSpeed; }                // LEFT
        if(IsKeyDown(KEY_S) && (circleY < (height - circleRadius))) { circleY += circleSpeed; }     // DOWN
        if(IsKeyDown(KEY_D) && (circleX < (width - circleRadius))) { circleX += circleSpeed; }      // RIGHT

        // Game logic ends
        }
        EndDrawing();
    }
}