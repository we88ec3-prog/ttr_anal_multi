
void FUN_004057b0(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  wchar_t *lpText;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = 0;
  do {
    if ((param_1 == (uVar4 % 7 + 1) * 100 + (uVar4 / 7) * 10000 + 0x2711) && (param_3 != (int *)0x0)
       ) {
      if (*param_3 == 0) {
        if (param_2 == 0x12d) {
          pvVar2 = _malloc(0x284);
          local_8 = 0;
          if (pvVar2 == (void *)0x0) {
            local_8 = 0xffffffff;
            *param_3 = 0;
          }
          else {
            iVar3 = FUN_00403580(uVar1);
            local_8 = 0xffffffff;
            *param_3 = iVar3;
          }
          goto LAB_00405889;
        }
        lpText = L"Failed DataExchange! Different ClassID.";
      }
      else {
        lpText = L"Failed DataExchange! Already Exchanged.";
      }
      MessageBoxW((HWND)0x0,lpText,L"Error",0);
    }
LAB_00405889:
    uVar4 = uVar4 + 1;
    if (0x1b < (int)uVar4) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

