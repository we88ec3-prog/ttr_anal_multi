
undefined4 FUN_007081e0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = (int *)FUN_006f6140("FILE*");
  if (*piVar2 == 0) {
    FUN_006f5f30(param_1,"attempt to use a closed file");
  }
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 <= puVar3) {
    puVar3 = &DAT_00c0bfc8;
  }
  *puVar1 = *puVar3;
  puVar1[1] = puVar3[1];
  puVar1[2] = puVar3[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar3 = *(undefined4 **)(param_1 + 8);
  *puVar3 = 0;
  puVar3[2] = 1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f55b0(FUN_00708980,2);
  return 1;
}

