
int FUN_00706ac0(int param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  int local_10 [3];
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    FUN_006f5da0(1);
  }
  local_10[0] = *(int *)(param_1 + 8) -
                (*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) & 0xfffffff0U);
  local_10[1] = 0xffffffff;
  iVar3 = FUN_006fe770(FUN_006f5a50,local_10,local_10[0] - *(int *)(param_1 + 0x20));
  if (*(uint *)(*(int *)(param_1 + 0x14) + 8) <= *(uint *)(param_1 + 8)) {
    *(uint *)(*(int *)(param_1 + 0x14) + 8) = *(uint *)(param_1 + 8);
  }
  puVar2 = *(uint **)(param_1 + 8);
  puVar2[2] = 1;
  *puVar2 = (uint)(iVar3 == 0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f52b0();
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
}

