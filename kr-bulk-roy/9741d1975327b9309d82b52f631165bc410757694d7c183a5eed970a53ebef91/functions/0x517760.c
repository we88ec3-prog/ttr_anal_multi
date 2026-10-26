
undefined4 * FUN_00517760(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  bool bVar4;
  
  bVar4 = true;
  piVar3 = DAT_00fe3014;
  if (*(char *)(DAT_00fe3014[1] + 0x19) == '\0') {
    piVar1 = (int *)DAT_00fe3014[1];
    do {
      piVar3 = piVar1;
      bVar4 = *(uint *)(param_2 + 0xc) < (uint)piVar3[3];
      if (bVar4) {
        piVar1 = (int *)*piVar3;
      }
      else {
        piVar1 = (int *)piVar3[2];
      }
    } while (*(char *)((int)piVar1 + 0x19) == '\0');
  }
  if (bVar4) {
    if (piVar3 == (int *)*DAT_00fe3014) {
      puVar2 = (undefined4 *)FUN_00517cc0(&param_2,1);
      *param_1 = *puVar2;
      *(undefined1 *)(param_1 + 1) = 1;
      return param_1;
    }
    FUN_0081a1b0();
  }
  if ((uint)piVar3[3] < *(uint *)(param_2 + 0xc)) {
    puVar2 = (undefined4 *)FUN_00517cc0(&param_2,bVar4);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = 1;
    return param_1;
  }
  FUN_0089120c(param_2);
  *param_1 = piVar3;
  *(undefined1 *)(param_1 + 1) = 0;
  return param_1;
}

