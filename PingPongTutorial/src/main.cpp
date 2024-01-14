#include <Windows.h>
#include <easyx.h>
#include "../inc/Message.h"
#include "../inc/Globals.h"
#include "../inc/ui/Application.h"
#include "../inc/ui/Interface.h"
#include "../inc/utils/Random.h"

void Init();

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    // initialization
    Init();

    Application* app = GetApplication();
    while (isRunning)
    {
        cleardevice();

        // process input
        PeekMouseMessage();
        
        // update game
        app->Update();

        //draw
        app->Draw();
        FlushBatchDraw();

        Sleep(15);
    }
 
    EndBatchDraw();
    closegraph();
    return 0;
}

void Init()
{
    Application* app = GetApplication();
    app->RegisterInterface(new MainInterface())
        ->RegisterInterface(new GameInterface());

}