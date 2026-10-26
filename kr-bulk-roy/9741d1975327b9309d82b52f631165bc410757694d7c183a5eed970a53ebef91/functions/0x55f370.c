
void FUN_0055f370(void)

{
  short sVar1;
  uint uVar2;
  LPCSTR lpMultiByteStr;
  short *psVar3;
  undefined4 uVar4;
  short *psVar5;
  int unaff_EDI;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b2e6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpMultiByteStr = (LPCSTR)(*(int *)(unaff_EDI + 0x24) + 0x1c);
  if (0xf < *(uint *)(*(int *)(unaff_EDI + 0x24) + 0x30)) {
    lpMultiByteStr = *(LPCSTR *)lpMultiByteStr;
  }
  local_14 = uVar2;
  if (lpMultiByteStr == (LPCSTR)0x0) {
    psVar5 = &DAT_00bed1fc;
  }
  else {
    MultiByteToWideChar(0,0,lpMultiByteStr,-1,&DAT_00fe1f40,0x400);
    psVar5 = &DAT_00fe1f40;
  }
  local_30 = (uint)local_30._2_2_ << 0x10;
  local_1c = 7;
  local_20 = 0;
  psVar3 = psVar5;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar3 - (int)(psVar5 + 1) >> 1);
  local_8 = 0;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00736880(uVar2);
    _atexit(FUN_00bce6f0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  uVar4 = FUN_00736b00(&local_30);
  *(undefined4 *)(unaff_EDI + 8) = uVar4;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

