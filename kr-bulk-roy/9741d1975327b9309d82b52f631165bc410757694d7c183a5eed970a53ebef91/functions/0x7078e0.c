
undefined4 FUN_007078e0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    FUN_006f5da0(1);
  }
  piVar3 = *(int **)(param_1 + 0xc);
  if (*(int **)(param_1 + 8) <= piVar3) {
    piVar3 = &DAT_00c0bfc8;
  }
  if (piVar3[2] == 2) {
    piVar3 = (int *)*piVar3;
  }
  else if (piVar3[2] == 7) {
    piVar3 = (int *)(*piVar3 + 0x18);
  }
  else {
    piVar3 = (int *)0x0;
  }
  iVar2 = *(int *)(param_1 + 0x10);
  local_18[0] = FUN_006fec70(param_1,"FILE*",5);
  local_10 = 4;
  FUN_006fb850(param_1,iVar2 + 0x60,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if (piVar3 != (int *)0x0) {
    iVar2 = FUN_006f56e0();
    if (((iVar2 != 0) && (*(undefined **)(param_1 + 8) != &UNK_00c0bfe8)) &&
       (*(undefined **)(param_1 + 8) != &DAT_00c0bfd8)) {
      iVar2 = FUN_006f7710();
      if (iVar2 != 0) {
        if (*piVar3 == 0) {
          FUN_006f54d0("closed file",0xb);
          return 1;
        }
        FUN_006f54d0(&DAT_00c1a980,4);
        return 1;
      }
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

