
undefined4 * FUN_0053f610(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  bool bVar4;
  
  bVar4 = true;
  piVar3 = DAT_00fe188c;
  if (*(char *)(DAT_00fe188c[1] + 0x15) == '\0') {
    piVar1 = (int *)DAT_00fe188c[1];
    do {
      piVar3 = piVar1;
      bVar4 = *(uint *)(param_2 + 0xc) < (uint)piVar3[3];
      if (bVar4) {
        piVar1 = (int *)*piVar3;
      }
      else {
        piVar1 = (int *)piVar3[2];
      }
    } while (*(char *)((int)piVar1 + 0x15) == '\0');
  }
  if (bVar4) {
    if (piVar3 == (int *)*DAT_00fe188c) {
      puVar2 = (undefined4 *)FUN_0053f6e0(&param_2,1);
      *param_1 = *puVar2;
      *(undefined1 *)(param_1 + 1) = 1;
      return param_1;
    }
    FUN_0053f8a0();
  }
  if ((uint)piVar3[3] < *(uint *)(param_2 + 0xc)) {
    puVar2 = (undefined4 *)FUN_0053f6e0(&param_2,bVar4);
    *param_1 = *puVar2;
    *(undefined1 *)(param_1 + 1) = 1;
    return param_1;
  }
  FUN_0089120c(param_2);
  *param_1 = piVar3;
  *(undefined1 *)(param_1 + 1) = 0;
  return param_1;
}

