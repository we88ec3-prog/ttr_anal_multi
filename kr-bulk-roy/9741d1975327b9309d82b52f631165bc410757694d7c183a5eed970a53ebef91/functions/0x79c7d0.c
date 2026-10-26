
void FUN_0079c7d0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009355e5;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_14 = DAT_00fb76a8;
  if (*(uint *)(param_1 + 0x30) < 0x10) {
    iVar4 = param_1 + 0x1c;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x1c);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  FUN_0079be00(iVar4);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  piVar5 = DAT_00fb76b4;
  if (DAT_00fb76b4 != (int *)0x0) {
    if (DAT_00fb76b4[0x37] - DAT_00fb76b4[0x36] >> 2 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)DAT_00fb76b4[0x36];
    }
    iVar1 = *(int *)(iVar4 + 0x74);
    *(undefined4 *)(iVar1 + 0x24) = 0;
    iVar3 = (**(code **)(*piVar5 + 0xc))();
    *(undefined4 *)(iVar4 + 0x24) = 1;
    *(undefined4 *)(iVar1 + 0x24) = 1;
    FUN_0077f030(0,0,0);
    if (*(int *)(iVar3 + 0xdc) - (int)*(int **)(iVar3 + 0xd8) >> 2 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = **(int **)(iVar3 + 0xd8);
    }
    iVar4 = *(int *)(iVar4 + 0x74);
    *(undefined4 *)(iVar4 + 0x1cc) = 0x3f333333;
    (**(code **)(*local_14 + 0xa0))(&local_18,"CircleShadow");
    if (local_18 != 0) {
      *(int *)(iVar4 + 0x164) = local_18;
    }
    iVar4 = FUN_00843ef0();
    *(undefined4 *)(iVar4 + 0xb8) = local_1c;
    iVar4 = FUN_00891268(0xe8);
    local_8 = 3;
    if (iVar4 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0077ebb0();
    }
    local_8 = 0xffffffff;
    *(int **)(param_1 + 4) = piVar5;
    (**(code **)(*piVar5 + 0x40))(iVar3);
  }
  ExceptionList = local_10;
  return;
}

