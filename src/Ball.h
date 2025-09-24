#pragma once
#include "../vendor/raylib/include/raylib.h"
#include "Paddle.h"


struct Ball {
    Rectangle rect;
    Color color;
    int velocity_x;
    int velocity_y;
};

struct Ball create_ball(const int x, const int y, const int width, const int height, const Color color, const int velocity);
void draw_ball(const struct Ball* ball);
void on_update_ball(struct Ball* const ball, struct Paddle* const player, struct Paddle* const opponent);
