#include "Application.h"
#include "../vendor/raylib/include/raylib.h"
#include "Paddle.h"
#include "Ball.h"
#include "stdio.h"

void draw_score(struct Paddle* const player, struct Paddle* const opponent);
bool handle_win(const struct Paddle* player, const struct Paddle* opponent);

struct Application* create_application(const char* name) {
    struct Application* application = (struct Application*) malloc(sizeof(struct Application));
    return application;
}

void run_application(struct Application* application) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong");

    struct Paddle player = create_paddle(10, 400, 20, 100, WHITE, KEY_W, KEY_S);
    struct Paddle opponent = create_paddle(970, 400, 20, 100, GREEN, KEY_UP, KEY_DOWN);
    struct Ball ball = create_ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 20, 20, RED, 350);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

            // update
            on_update_paddle(&player);
            on_update_paddle(&opponent);
            on_update_ball(&ball, &player, &opponent);

            // draw
            draw_paddle(&player);
            draw_paddle(&opponent);
            draw_ball(&ball);

            draw_score(&player, &opponent);

        EndDrawing();

        if (handle_win(&player, &opponent)) {
            break;
        }
    }

    CloseWindow();

}

void draw_score(struct Paddle* const player, struct Paddle* const opponent) {
    const char* player_score = malloc(2);
    const char* opponent_score = malloc(2);

    sprintf(player_score, "%d", player->score);
    sprintf(opponent_score, "%d", opponent->score);

    DrawText(player_score,0, 0, 20, player->color);
    DrawText(":",25, 0, 20, PURPLE);
    DrawText(opponent_score,45, 0, 20, opponent->color);
}

bool handle_win(const struct Paddle* const player, const struct Paddle* const opponent) {
    const struct Paddle* winner = NULL;
    if (player->score >= 10) {
        winner = player;
    }
    else if (opponent-> score >= 10) {
        winner = opponent;
    }

    if (winner != NULL) {
        while (GetKeyPressed() != KEY_SPACE) {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Congrats You WIN", 0, 0, 50, player->color);
            EndDrawing();
        }
        return true;
    }
    return false;

}

void destroy_application(struct Application* application) {
    free(application);
}