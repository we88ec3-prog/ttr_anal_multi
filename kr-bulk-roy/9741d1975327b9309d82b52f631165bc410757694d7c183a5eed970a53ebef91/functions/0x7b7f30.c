
/* WARNING: Removing unreachable block (ram,0x007b7f86) */

void FUN_007b7f30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar2 = param_1;
  piVar3 = *(int **)param_1[2];
  if (piVar3 != (int *)param_1[2]) {
    do {
      iVar1 = piVar3[9];
      if (iVar1 != 0) {
        FUN_007dcf40();
        FUN_0089120c(iVar1);
        piVar3[9] = 0;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)puVar2[2]);
  }
  FUN_00552640(puVar2 + 2);
  param_1 = (undefined4 *)puVar2[2];
  if (puVar2[5] != puVar2[6]) {
    puVar2[6] = puVar2[5];
  }
  FUN_007dcc90(puVar2[5],&param_1);
  puVar2[9] = 7;
  puVar2[10] = 8;
  FUN_007dc480(*puVar2);
  return;
}

