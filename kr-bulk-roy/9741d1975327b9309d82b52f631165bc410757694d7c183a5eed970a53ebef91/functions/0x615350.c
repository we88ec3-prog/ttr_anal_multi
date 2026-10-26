
void FUN_00615350(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  wchar_t *lpText;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = 0x9c42;
  do {
    if ((param_1 == iVar4) && (param_3 != (int *)0x0)) {
      if (*param_3 == 0) {
        if (param_2 == 0x12d) {
          pvVar2 = _malloc(0x254);
          local_8 = 0;
          if (pvVar2 == (void *)0x0) {
            local_8 = 0xffffffff;
            *param_3 = 0;
          }
          else {
            iVar3 = FUN_0060b500(uVar1);
            local_8 = 0xffffffff;
            *param_3 = iVar3;
          }
          goto LAB_006153f8;
        }
        lpText = L"Failed DataExchange! Different ClassID.";
      }
      else {
        lpText = L"Failed DataExchange! Already Exchanged.";
      }
      MessageBoxW((HWND)0x0,lpText,L"Error",0);
    }
LAB_006153f8:
    iVar4 = iVar4 + 100;
    if (0x9efd < iVar4) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

