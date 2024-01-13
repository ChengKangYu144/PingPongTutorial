#include <Windows.h>
#include <easyx.h>
#include "../inc/Message.h"

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    initgraph(640, 480);
    
    Coordinate mouse;
    while (true)
    {
        PeekInputMessage();
        if (IsKeyDown(VK_Q))
        {
            break;
        }
        mouse = GetMouseCoordinate();

        circle((int)mouse.x, (int)mouse.y, 10);
    }
 
    closegraph();
    return 0;
}