
void FUN_007f2960(void)

{
  LPCSTR lpCaption;
  char cVar1;
  uint uVar2;
  char *pcVar3;
  LPCSTR pCVar4;
  int iVar5;
  int in_ECX;
  undefined4 *****pppppuVar6;
  undefined4 ****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928452;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ****)((uint)local_30[0] & 0xffffff00);
  pcVar3 = (char *)(in_ECX + 0x10);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70((char *)(in_ECX + 0x10),(int)pcVar3 - (in_ECX + 0x11));
  lpCaption = (LPCSTR)(in_ECX + 0x30);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  pCVar4 = lpCaption;
  do {
    cVar1 = *pCVar4;
    pCVar4 = pCVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(lpCaption,(int)pCVar4 - (in_ECX + 0x31));
  pppppuVar6 = (undefined4 *****)local_30[0];
  if (local_1c < 0x10) {
    pppppuVar6 = local_30;
  }
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8._0_1_ = 1;
    FUN_007cdeb0(uVar2);
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8._0_1_ = 0;
  }
  FUN_007ce0a0(&DAT_00fe3250,pppppuVar6);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8._0_1_ = 2;
    FUN_007cdeb0(uVar2);
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8._0_1_ = 0;
  }
  FUN_007cfa70(&DAT_00fe3250);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8._0_1_ = 3;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8._0_1_ = 0;
  }
  iVar5 = FUN_007cfba0();
  if (iVar5 == 0) {
    MessageBoxA((HWND)0x0,&DAT_00c50adc,lpCaption,0);
  }
  else {
    *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(iVar5 + 0x1c);
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

