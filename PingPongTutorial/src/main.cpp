#include <Windows.h>
#include <easyx.h>
#include "../inc/Message.h"
#include "../inc/Globals.h"
#include "../inc/ui/Application.h"
#include "../inc/ui/Interface.h"
#include "../inc/utils/Random.h"

void Init();
void ClearUp();

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

    ClearUp();

    return 0;
}

void Init()
{
    SetRandomSeed();

    initgraph(1000, 560);
    setbkcolor(WHITE);
    settextcolor(BLACK);
    
    Application* app = GetApplication();
    app->RegisterInterface(new MainInterface())
        ->RegisterInterface(new GameInterface());

    BeginBatchDraw();
}

void ClearUp()
{
    EndBatchDraw();
    closegraph();
}