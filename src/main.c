#include "../vendor/raylib/include/raylib.h"

int main(void)
{
    InitWindow(1000, 800, "Pong");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Pong Game", 0, 0, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}