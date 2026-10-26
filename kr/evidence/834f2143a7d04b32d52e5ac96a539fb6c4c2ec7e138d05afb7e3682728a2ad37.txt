
void FUN_004cabe0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *in_ECX;
  float local_20;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fab1d0 != 0) {
    fVar1 = *param_1;
    fVar2 = (float)in_ECX[0x28];
    fVar3 = (float)in_ECX[0x29];
    fVar4 = param_1[1];
    local_20 = fVar1 + fVar2;
    local_1c = fVar3 + fVar4;
    iVar5 = FUN_0082cdf0();
    if (iVar5 != 0) {
      local_20 = fVar1 + fVar2;
      local_1c = fVar3 + fVar4;
      (**(code **)(*in_ECX + 0x44))(&local_20,1);
    }
  }
  ExceptionList = local_14;
  return;
}

