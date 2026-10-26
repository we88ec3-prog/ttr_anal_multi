
void FUN_00650160(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  float local_1c;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919f66;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00744640(param_1,param_2);
  if (*(int *)(in_ECX + 0x24) == 0) {
    ExceptionList = local_10;
    return;
  }
  iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))(uVar3);
  if (iVar4 == 0) {
    iVar4 = *(int *)(DAT_00fba838 + 0x40);
    if (iVar4 == 0) {
      local_14 = 0.0;
      local_1c = 0.0;
    }
    else {
      local_14 = *(float *)(iVar4 + 0x15c);
      local_1c = *(float *)(iVar4 + 0x15c);
    }
    piVar6 = *(int **)(in_ECX + 0xac);
    if (*piVar6 == 0) goto LAB_0065028f;
    piVar5 = (int *)FUN_0056f7a0(local_1c * 0.5,local_14 * 0.5);
  }
  else {
    piVar6 = *(int **)(in_ECX + 0xac);
    if (*piVar6 == 0) goto LAB_0065028f;
    piVar5 = (int *)FUN_0056f7a0(*(undefined4 *)(iVar4 + 0xa0),*(undefined4 *)(iVar4 + 0xa4));
  }
  piVar6[5] = *piVar5;
  piVar6[6] = piVar5[1];
LAB_0065028f:
  iVar4 = *(int *)(in_ECX + 0xac);
  *(undefined4 *)(iVar4 + 0xc) = param_1;
  *(undefined4 *)(iVar4 + 0x10) = param_2;
  iVar4 = *(int *)(in_ECX + 0x14);
  iVar1 = *(int *)(in_ECX + 0xc);
  iVar2 = *(int *)(in_ECX + 0xac);
  uVar3 = DAT_00fcde40 & 1;
  *(int *)(iVar2 + 4) = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
  *(int *)(iVar2 + 8) = iVar4 - iVar1;
  if (uVar3 == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fcde28 + 0x20))(DAT_00fcde28,0);
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 1;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fcde2c + 0x114))(DAT_00fcde2c,0,1,4);
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 2;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fcde2c + 0x114))(DAT_00fcde2c,0,2,4);
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 3;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fcde2c + 0x114))(DAT_00fcde2c,0,4,0);
  FUN_00570dd0();
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 4;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fcde28 + 0x2c))(DAT_00fcde28);
  ExceptionList = local_10;
  return;
}

