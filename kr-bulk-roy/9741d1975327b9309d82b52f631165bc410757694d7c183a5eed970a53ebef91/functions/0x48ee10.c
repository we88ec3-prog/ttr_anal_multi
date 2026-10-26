
void FUN_0048ee10(HWND param_1)

{
  HWND pHVar1;
  DWORD idAttachTo;
  DWORD idAttach;
  BOOL BVar2;
  
  pHVar1 = GetForegroundWindow();
  if ((pHVar1 != param_1) && (pHVar1 = GetForegroundWindow(), pHVar1 != (HWND)0x0)) {
    idAttachTo = GetWindowThreadProcessId(pHVar1,(LPDWORD)0x0);
    idAttach = GetCurrentThreadId();
    if ((idAttach != idAttachTo) && (BVar2 = AttachThreadInput(idAttach,idAttachTo,1), BVar2 != 0))
    {
      BringWindowToTop(param_1);
      AttachThreadInput(idAttach,idAttachTo,0);
    }
  }
  return;
}

