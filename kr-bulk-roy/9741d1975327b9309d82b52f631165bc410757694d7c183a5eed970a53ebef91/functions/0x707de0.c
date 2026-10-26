
undefined4 FUN_00707de0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)FUN_006f6140("FILE*");
  if (*piVar2 == 0) {
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar1 = *(undefined4 **)(param_1 + 8);
    uVar3 = FUN_006fec70(param_1,"file (closed)",0xd);
    *puVar1 = uVar3;
    puVar1[2] = 4;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  FUN_006f5580(param_1,"file (%p)",*piVar2);
  return 1;
}

