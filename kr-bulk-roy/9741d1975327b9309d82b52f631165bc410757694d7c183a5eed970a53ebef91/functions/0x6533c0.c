
void FUN_006533c0(void)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int unaff_EDI;
  wchar_t *lpText;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911d18;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int **)(unaff_EDI + 8) != (int *)0x0) {
    if (**(int **)(unaff_EDI + 8) == 0) {
      if (*(int *)(unaff_EDI + 4) == 900) {
        pvVar2 = _malloc(0x130);
        local_8 = 0;
        if (pvVar2 != (void *)0x0) {
          uVar3 = FUN_00652c80(uVar1);
          **(undefined4 **)(unaff_EDI + 8) = uVar3;
          ExceptionList = local_10;
          return;
        }
        **(undefined4 **)(unaff_EDI + 8) = 0;
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

