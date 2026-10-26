
void FUN_00707d20(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    *(undefined4 *)(param_1 + 0x58) =
         *(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0xc);
    *(undefined4 *)(param_1 + 0x60) = 5;
    puVar2 = (undefined4 *)FUN_006f9b70(2);
    puVar1 = *(undefined4 **)(param_1 + 8);
    *puVar1 = *puVar2;
    puVar1[1] = puVar2[1];
    puVar1[2] = puVar2[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  piVar3 = (int *)FUN_006f6140("FILE*");
  if (*piVar3 == 0) {
    FUN_006f5f30(param_1,"attempt to use a closed file");
  }
  FUN_00707ca0();
  return;
}

