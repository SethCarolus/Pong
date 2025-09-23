#pragma once
#include <stdlib.h>


#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1000

struct Application 
{
    char* name;
};

struct Application* create_application(const char* name);
void run_application(struct Application* application);
void destroy_application(struct Application* application);