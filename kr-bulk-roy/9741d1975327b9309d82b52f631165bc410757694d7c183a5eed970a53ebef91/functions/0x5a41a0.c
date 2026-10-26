
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a41a0(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  short *psVar4;
  undefined4 *puVar5;
  int *in_ECX;
  short *psVar6;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936194;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar3 == 0x105b9) goto LAB_005a41f5;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005a41f5:
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  psVar4 = (short *)FUN_004f6a30(in_ECX[5]);
  local_34 = (undefined4 *)((uint)local_34._2_2_ << 0x10);
  local_20 = 7;
  local_24 = 0;
  psVar6 = psVar4;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
  local_8 = 1;
  puVar5 = local_34;
  if (local_20 < 8) {
    puVar5 = &local_34;
  }
  FUN_00642e60(1,puVar5,1);
  local_8 = 0xffffffff;
  if (7 < local_20) {
    FUN_0089120c(local_34);
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = (undefined4 *)((uint)local_34 & 0xffff0000);
  FUN_005a51e0();
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x144) + 0x138);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  DAT_00f95be9 = 1;
  _DAT_00f95bec = uVar2;
  ExceptionList = local_10;
  return;
}

