
void FUN_0064cab0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_ESI;
  wchar_t *lpText;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d9c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int **)(unaff_ESI + 8) != (int *)0x0) {
    if (**(int **)(unaff_ESI + 8) == 0) {
      if (*(int *)(unaff_ESI + 4) == 300) {
        pvVar1 = _malloc(0x194);
        local_8 = 0;
        if (pvVar1 != (void *)0x0) {
          uVar2 = FUN_0064ce10(pvVar1);
          **(undefined4 **)(unaff_ESI + 8) = uVar2;
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

