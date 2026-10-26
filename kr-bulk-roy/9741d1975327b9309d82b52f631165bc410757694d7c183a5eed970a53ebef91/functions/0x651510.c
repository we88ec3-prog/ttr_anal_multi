
void FUN_00651510(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  wchar_t *lpText;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920d88;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0x2cf6;
  do {
    if ((param_1 == local_14) && (param_3 != (int *)0x0)) {
      if (*param_3 == 0) {
        if (param_2 == 0x12d) {
          puVar2 = _malloc(0x2a8);
          local_8 = 0;
          if (puVar2 == (undefined4 *)0x0) {
            local_8 = 0xffffffff;
            *param_3 = 0;
          }
          else {
            FUN_005d6dd0(uVar1);
            puVar2[0xa6] = 0;
            *puVar2 = FUI::CItemSlotContinue::vftable;
            puVar2[0xa8] = 0;
            local_8 = 0xffffffff;
            *param_3 = (int)puVar2;
          }
          goto LAB_006515de;
        }
        lpText = L"Failed DataExchange! Different ClassID.";
      }
      else {
        lpText = L"Failed DataExchange! Already Exchanged.";
      }
      MessageBoxW((HWND)0x0,lpText,L"Error",0);
    }
LAB_006515de:
    local_14 = local_14 + 100;
    if (0x2e85 < local_14) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

