
int FUN_00706b70(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_10 [3];
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((*(undefined4 **)(param_1 + 8) <= puVar2) || (puVar2 == &DAT_00c0bfc8)) ||
     (*(int *)(*(int *)(param_1 + 0xc) + 0x18) == -1)) {
    FUN_006f5da0(2);
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x20;
  FUN_006f52b0();
  local_10[0] = *(int *)(param_1 + 8) + -0x10;
  local_10[1] = 0xffffffff;
  iVar3 = FUN_006fe770(FUN_006f5a50,local_10,local_10[0] - *(int *)(param_1 + 0x20));
  if (*(uint *)(*(int *)(param_1 + 0x14) + 8) <= *(uint *)(param_1 + 8)) {
    *(uint *)(*(int *)(param_1 + 0x14) + 8) = *(uint *)(param_1 + 8);
  }
  puVar1 = *(uint **)(param_1 + 8);
  puVar1[2] = 1;
  *puVar1 = (uint)(iVar3 == 0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar2 = *(undefined4 **)(param_1 + 8);
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  if (puVar2 <= puVar4) {
    puVar4 = &DAT_00c0bfc8;
  }
  *puVar4 = puVar2[-4];
  puVar4[1] = puVar2[-3];
  puVar4[2] = puVar2[-2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
}

