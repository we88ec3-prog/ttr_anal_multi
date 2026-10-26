
void FUN_00483e20(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  wchar_t *lpText;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f548;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    if (**(int **)(param_1 + 8) == 0) {
      if (*(int *)(param_1 + 4) == 0x12d) {
        puVar2 = _malloc(0x2a0);
        local_8 = 0;
        if (puVar2 != (undefined4 *)0x0) {
          FUN_005d6dd0(uVar1);
          *puVar2 = FUI::CItemSlotShopShapeRestore::vftable;
          puVar2[0xa6] = 0;
          **(undefined4 **)(param_1 + 8) = puVar2;
          ExceptionList = local_10;
          return;
        }
        **(undefined4 **)(param_1 + 8) = 0;
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

