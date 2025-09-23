#include <stdlib.h>


struct Application 
{
    char* name;
};

struct Application* create_application(const char* name);
void run_application(struct Application* application);
void destroy_application(struct Application* application);