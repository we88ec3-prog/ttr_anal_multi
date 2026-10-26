
int FUN_00706740(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < (int)puVar1[2])) {
    FUN_006f6210(param_1);
  }
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0xc);
  iVar4 = FUN_006f6e60();
  if (iVar4 != 0) {
    FUN_006f8ad0();
  }
  FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x10,0xffffffff);
  if (*(uint *)(*(int *)(param_1 + 0x14) + 8) <= *(uint *)(param_1 + 8)) {
    *(uint *)(*(int *)(param_1 + 0x14) + 8) = *(uint *)(param_1 + 8);
  }
  return (*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) - (iVar2 - iVar3 >> 4);
}

