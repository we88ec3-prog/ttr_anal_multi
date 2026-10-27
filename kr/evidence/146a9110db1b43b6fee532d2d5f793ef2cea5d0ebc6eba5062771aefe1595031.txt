
void FUN_006a4080(int param_1)

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
      if (*(int *)(param_1 + 4) == 0xc41a) {
        puVar2 = _malloc(0xd8);
        local_8 = 0;
        if (puVar2 != (undefined4 *)0x0) {
          FUN_0075af30(uVar1);
          *puVar2 = FUI::CHelpInsideClient::vftable;
          puVar2[0x33] = 4;
          puVar2[0x34] = 0;
          puVar2[0x35] = 0;
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

