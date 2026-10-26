
/* WARNING: Removing unreachable block (ram,0x007dc4d0) */

void FUN_007dc480(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)**(int **)(param_1 + 4);
  piVar1 = (int *)(param_1 + 4);
  if (piVar3 != *(int **)(param_1 + 4)) {
    do {
      if ((undefined4 *)piVar3[9] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar3[9])(1);
        piVar3[9] = 0;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*piVar1);
  }
  iVar2 = param_1;
  FUN_00552640(piVar1);
  param_1 = *piVar1;
  if (*(int *)(iVar2 + 0x10) != *(int *)(iVar2 + 0x14)) {
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x10);
  }
  FUN_007dcc90(*(undefined4 *)(iVar2 + 0x10),&param_1);
  *(undefined4 *)(iVar2 + 0x20) = 7;
  *(undefined4 *)(iVar2 + 0x24) = 8;
  return;
}

