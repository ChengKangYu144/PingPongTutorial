#include "../inc/Globals.h"

#include "../inc/ui/Application.h"

static Application application;

Application* GetApplication()
{
	return &application;
}

bool isRunning = true;

int gameMode = 0;

IMAGE batImage;
IMAGE ballImage;

FmodSound bounceSound;
FmodSound scoreSound;