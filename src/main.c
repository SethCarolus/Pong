#include "Application.h"

int main(void)
{
    struct Application* application = create_application("Pong");
    run_application(application);
    destroy_application(application);
    return 0;
}