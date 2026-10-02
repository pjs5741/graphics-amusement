#include "stdafx.h"
#include "Samples/D3D12HelloWindow.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    D3D12HelloWindow sample(1920, 1080, L"D3D12 Hello Window");
    return Win32Application::Run(&sample, hInstance, nCmdShow);
}