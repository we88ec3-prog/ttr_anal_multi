
void FUN_005a3f90(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int *in_ECX;
  short *psVar4;
  undefined4 local_2c;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009291a6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0x105b9) goto LAB_005a3fe0;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005a3fe0:
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  psVar3 = (short *)FUN_004f6a30(in_ECX[5]);
  local_2c = (uint)local_2c._2_2_ << 0x10;
  local_18 = 7;
  local_1c = 0;
  psVar4 = psVar3;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
  local_8 = 1;
  FUN_004026e0(&local_2c,0,0xffffffff);
  if (7 < local_18) {
    FUN_0089120c(local_2c);
  }
  ExceptionList = local_10;
  return;
}

