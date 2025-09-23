#include "Ball.h"
#include "../vendor/raylib/include/raylib.h"
#include "Paddle.h"

void draw_ball(const struct Ball* ball) {
    DrawRectangle(ball->rect.x, ball->rect.y, ball->rect.width, ball->rect.height, ball->color);
}

struct Ball create_ball(const int x, const int y, const int width, const int height, const Color color, const int velocity) {
    struct Ball ball = { {x, y, width, height}, color, velocity, velocity};
    return ball;
}

void on_update_ball(struct Ball* ball, const struct Paddle* player, const struct Paddle* opponent) {
    float dt = GetFrameTime();

    if (CheckCollisionRecs(ball->rect, player->rect)) {
        if (ball->rect.x < player->rect.x) {
            ball->rect.x = player->rect.x + 1;
        }
        ball->velocity_x *= -1;
    }

    if (CheckCollisionRecs(ball->rect, opponent->rect)) {
        if (ball->rect.x > opponent->rect.x) {
            ball->rect.x = opponent->rect.x - 1;
        }
        ball->velocity_x *= -1;
    }


    if (ball->rect.y  + ball->rect.height >= GetScreenHeight() || ball->rect.y <= 0) ball->velocity_y *= -1;

    ball->rect.x += ball->velocity_x * dt;
    ball->rect.y += ball->velocity_y * dt;

    // Top and Bottom Clamping
    if (ball->rect.y <  0) ball->rect.y = 0;
    if (ball->rect.y + ball->rect.height > GetScreenHeight()) ball->rect.y = GetScreenHeight() - ball->rect.height;


    if (ball->rect.x < 0 || ball->rect.x > GetScreenWidth()) {
        ball->rect.x = GetScreenWidth() / 2;
        ball->rect.y = GetScreenHeight() / 2;
    }

}
