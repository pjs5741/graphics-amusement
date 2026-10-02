#pragma once

#include "Common/DXSampleHelper.h"
#include "Platform/Win32Application.h"

class DXSample
{
public:
    DXSample(UINT width, UINT height, std::wstring name);
    virtual ~DXSample();

    void ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);

    UINT GetWidth()const { return m_width; }
    UINT GetHeight() const { return m_height; }
    const WCHAR* GetTitle() const { return m_title.c_str(); }

    virtual void OnInit() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnRender() = 0;
    virtual void OnDestroy() = 0;

    virtual void OnKeyDown(UINT8) {}
    virtual void OnKeyUp(UINT8) {}


protected:
    std::wstring GetAssetFullPath(LPCWSTR assetName);

    void GetHardwareAdapter(
        _In_ IDXGIFactory1* pFactory,
        _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
        bool requestHighPerformanceAdapter = false);
    UINT m_width;
    UINT m_height;
    float m_aspectRatio;
    bool m_useWarpDevice;
   
private:
    std::wstring m_title;
    std::wstring m_assetsPath;
};