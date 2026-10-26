
void FUN_00558eb0(void)

{
  ATOM AVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  HWND hWnd;
  int in_ECX;
  int local_6c;
  int local_68;
  undefined1 local_64 [4];
  int local_60;
  int local_5c;
  tagMSG local_4c;
  WNDCLASSW local_30;
  
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hInstance = (HINSTANCE)0x0;
  local_30.hIcon = (HICON)0x0;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = (HBRUSH)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpszClassName = (LPCWSTR)0x0;
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_00558c10;
  local_30.hInstance = GetModuleHandleW((LPCWSTR)0x0);
  local_30.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f8a);
  local_30.hbrBackground = (HBRUSH)0x6;
  local_30.lpszClassName = L"SplashWnd";
  local_30.hIcon = LoadIconW(local_30.hInstance,(LPCWSTR)0x7f00);
  AVar1 = RegisterClassW(&local_30);
  if ((AVar1 == 0) && (DVar2 = GetLastError(), DVar2 != 0x582)) {
    OutputDebugStringW(L"Unable to register class SplashWnd\n");
    return;
  }
  iVar3 = GetSystemMetrics(0);
  iVar4 = GetSystemMetrics(1);
  hWnd = CreateWindowExW(0x80000,L"SplashWnd",L"",0x8000000e,(iVar3 + -0x200) / 2,
                         (iVar4 + -0x180) / 2,0x200,0x180,(HWND)0x0,(HMENU)0x0,local_30.hInstance,
                         (LPVOID)0x0);
  *(HWND *)(in_ECX + 0xc) = hWnd;
  SetWindowLongW(hWnd,-0x15,in_ECX);
  iVar3 = FUN_00558ab0(&local_6c);
  if (iVar3 != 0) {
    FUN_00558d40(local_6c);
    GetObjectW(*(HANDLE *)(in_ECX + 0x10),0x18,local_64);
    local_68 = local_60;
    local_6c = local_5c;
    iVar3 = GetSystemMetrics(0);
    iVar4 = GetSystemMetrics(1);
    MoveWindow(*(HWND *)(in_ECX + 0xc),(iVar3 - local_60) / 2,(iVar4 - local_6c) / 2,local_68,
               local_6c,0);
    GetWindowLongW(*(HWND *)(in_ECX + 0xc),-0x10);
    FUN_00558e00();
    SetWindowPos(*(HWND *)(in_ECX + 0xc),(HWND)0x0,0,0,0,0,0x43);
    ShowWindow(*(HWND *)(in_ECX + 0xc),1);
    PeekMessageW(&local_4c,(HWND)0x0,0,0,0);
    PostMessageW(*(HWND *)(in_ECX + 0xc),6,2,0);
    iVar3 = GetMessageW(&local_4c,(HWND)0x0,0,0);
    while ((iVar3 != 0 && ((local_4c.message != 0x12 || (local_4c.lParam != 100))))) {
      if (iVar3 != -1) {
        TranslateMessage(&local_4c);
        DispatchMessageW(&local_4c);
      }
      iVar3 = GetMessageW(&local_4c,(HWND)0x0,0,0);
    }
  }
  DestroyWindow(*(HWND *)(in_ECX + 0xc));
  DeleteObject(*(HGDIOBJ *)(in_ECX + 0x10));
  UnregisterClassW(L"SplashWnd",(HINSTANCE)0x0);
  return;
}

