#pragma once
#include "../vendor/raylib/include/raylib.h"

#define PADDLE_SPEED 600.0f

struct Paddle {
    Rectangle rect;
    Color color;
    int up_key;
    int down_key;
    int score;
};

struct Paddle create_paddle(const int x, const int y, const int width, const int height, const Color color, const int up_key, const int down_key);
void draw_paddle(const struct Paddle* paddle);
void on_update_paddle(struct Paddle* paddle);