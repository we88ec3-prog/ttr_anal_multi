
void FUN_00608dc0(void)

{
  uint uVar1;
  undefined4 *puVar2;
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
      if (*(int *)(unaff_EDI + 4) == 0x12d) {
        puVar2 = _malloc(0x298);
        local_8 = 0;
        if (puVar2 != (undefined4 *)0x0) {
          FUN_005d6dd0(uVar1);
          *puVar2 = FUI::CItemSlotShopConsumption3::vftable;
          **(undefined4 **)(unaff_EDI + 8) = puVar2;
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

