
void FUN_0064be40(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a04c;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00744640(param_1,param_2);
  if (*(int *)(in_ECX + 0x24) != 0) {
    (**(code **)(*DAT_00fba7a4 + 0x20))(uVar5);
    FUN_0064bfb0();
    piVar1 = *(int **)(in_ECX + 0xa8);
    if (*piVar1 != 0) {
      piVar6 = (int *)FUN_0056f7a0(*(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0xb0));
      piVar1[5] = *piVar6;
      piVar1[6] = piVar6[1];
    }
    iVar2 = *(int *)(in_ECX + 0xa8);
    *(undefined4 *)(iVar2 + 0xc) = param_1;
    *(undefined4 *)(iVar2 + 0x10) = param_2;
    iVar2 = *(int *)(in_ECX + 0x14);
    iVar3 = *(int *)(in_ECX + 0xc);
    iVar4 = *(int *)(in_ECX + 0xa8);
    uVar5 = DAT_00fcde40 & 1;
    *(int *)(iVar4 + 4) = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
    *(int *)(iVar4 + 8) = iVar2 - iVar3;
    if (uVar5 == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_8 = 0;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fcde28 + 0x20))(DAT_00fcde28,0);
    FUN_00570dd0();
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_8 = 1;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fcde28 + 0x2c))(DAT_00fcde28);
  }
  ExceptionList = local_10;
  return;
}

