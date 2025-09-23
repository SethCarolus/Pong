#include "Paddle.h"
#include "../vendor/raylib/include/raylib.h"
#include <stdint.h>


struct Paddle create_paddle(const int x, const int y, const int width, const int height, const Color color, const int up_key, const int down_key) {

    struct Paddle paddle = { {x, y, width, height}, color, up_key, down_key };
    return paddle;
}

void draw_paddle(const struct Paddle* paddle) {
    DrawRectangle(paddle->rect.x, paddle->rect.y, paddle->rect.width, paddle->rect.height, paddle->color);
}

void on_update_paddle(struct Paddle* paddle) {
    float dt = GetFrameTime();
    int height = GetScreenHeight();

    if (IsKeyDown(paddle->up_key)) {
        paddle->rect.y -= PADDLE_SPEED * dt;
    }
    if (IsKeyDown(paddle->down_key)) {
        paddle->rect.y += PADDLE_SPEED * dt;
    }

    // Clamp paddle position
    if (paddle->rect.y < 0) paddle->rect.y = 0;
    if (paddle->rect.y + paddle->rect.height > height)
        paddle->rect.y = height - paddle->rect.height;
}