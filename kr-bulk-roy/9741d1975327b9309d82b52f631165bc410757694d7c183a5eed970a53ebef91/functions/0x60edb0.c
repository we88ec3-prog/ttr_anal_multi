
undefined4 * FUN_0060edb0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090cd7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  local_8 = 0xffffffff;
  psVar2 = (short *)FUN_00530160();
  psVar3 = psVar2;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
  FUN_00404300(&DAT_00bfb894,1);
  psVar2 = (short *)FUN_005301d0();
  psVar3 = psVar2;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
  FUN_004041f0(param_1 + 0x1d0,0,0xffffffff);
  if (7 < (uint)param_3[5]) {
    ExceptionList = local_10;
    return (undefined4 *)*param_3;
  }
  ExceptionList = local_10;
  return param_3;
}

