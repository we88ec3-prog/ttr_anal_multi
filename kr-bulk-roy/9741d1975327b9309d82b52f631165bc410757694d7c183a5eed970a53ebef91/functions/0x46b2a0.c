
void FUN_0046b2a0(void)

{
  undefined4 *puVar1;
  int unaff_EDI;
  wchar_t *lpText;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911d18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int **)(unaff_EDI + 8) != (int *)0x0) {
    if (**(int **)(unaff_EDI + 8) == 0) {
      if (*(int *)(unaff_EDI + 4) == 0x12d) {
        puVar1 = _malloc(0x260);
        local_8 = 0;
        if (puVar1 != (undefined4 *)0x0) {
          FUN_00468270(puVar1);
          *puVar1 = FUI::CTelecomListItem::vftable;
          **(undefined4 **)(unaff_EDI + 8) = puVar1;
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

