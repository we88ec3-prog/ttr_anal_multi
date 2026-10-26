
int FUN_007072d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  if (*(char *)(iVar3 + 7) == '\0') {
    puVar2 = &DAT_00c0bfc8;
  }
  else {
    puVar2 = (undefined4 *)(iVar3 + 0x18);
  }
  if (puVar2[2] == 8) {
    uVar4 = *puVar2;
  }
  else {
    uVar4 = 0;
  }
  iVar3 = FUN_00707110(param_1,uVar4,*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4);
  if (iVar3 < 0) {
    if ((*(undefined **)(param_1 + 8) != &DAT_00c0bfd8) &&
       ((iVar1 = *(int *)(*(undefined **)(param_1 + 8) + -8), iVar1 == 4 || (iVar1 == 3)))) {
      FUN_006f5e90();
      FUN_006f52b0();
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      FUN_006fc080(param_1,2,(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
    }
    FUN_006f8ad0();
  }
  return iVar3;
}

