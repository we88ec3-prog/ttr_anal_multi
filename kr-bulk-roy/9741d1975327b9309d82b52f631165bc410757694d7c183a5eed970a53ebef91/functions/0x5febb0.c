
void FUN_005febb0(void)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int unaff_ESI;
  wchar_t *lpText;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d9c8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int **)(unaff_ESI + 8) != (int *)0x0) {
    if (**(int **)(unaff_ESI + 8) == 0) {
      if (*(int *)(unaff_ESI + 4) == 0x12d) {
        pvVar2 = _malloc(0x248);
        local_8 = 0;
        if (pvVar2 != (void *)0x0) {
          uVar3 = FUN_005faac0(uVar1,pvVar2);
          **(undefined4 **)(unaff_ESI + 8) = uVar3;
          ExceptionList = local_10;
          return;
        }
        **(undefined4 **)(unaff_ESI + 8) = 0;
        ExceptionList = local_10;
        return;
      }
      lpText = L"Failed DataExchange! Different ClassID.";
    }
    else {
      lpText = L"Failed DataExchange! Already Exchanged.";
    }
    MessageBoxW((HWND)0x0,lpText,L"Error",0);
  }
  ExceptionList = local_10;
  return;
}

