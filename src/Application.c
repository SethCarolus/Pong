#include "Application.h"
#include "../vendor/raylib/include/raylib.h"
#include "Paddle.h"
#include "Ball.h"

struct Application* create_application(const char* name) {
    struct Application* application = (struct Application*) malloc(sizeof(struct Application));
    return application;
}

void run_application(struct Application* application) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong");

    struct Paddle player = create_paddle(10, 400, 20, 100, WHITE, KEY_W, KEY_S);
    struct Paddle opponent = create_paddle(970, 400, 20, 100, GREEN, KEY_UP, KEY_DOWN);
    struct Ball ball = create_ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 20, 20, RED, 350);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);

            on_update_paddle(&player);
            on_update_paddle(&opponent);

            draw_paddle(&player);
            draw_paddle(&opponent);

            on_update_ball(&ball, &player, &opponent);
        
            draw_ball(&ball);
        EndDrawing();
    }

    CloseWindow();

}

void destroy_application(struct Application* application) {
    free(application);
}