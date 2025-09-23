#include "Application.h"
#include "../vendor/raylib/include/raylib.h"

struct Application* create_application(const char* name) {
    struct Application* application = (struct Application*) malloc(sizeof(struct Application));
    return application;
}

void run_application(struct Application* application) {
    InitWindow(1000, 800, "Pong");

    while (!WindowShouldClose())
    {
        loop();
    }

    CloseWindow();

}

void loop() {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Pong Game", 0, 0, 20, WHITE);
        EndDrawing();
}

void destroy_application(struct Application* application) {
    free(application);
}