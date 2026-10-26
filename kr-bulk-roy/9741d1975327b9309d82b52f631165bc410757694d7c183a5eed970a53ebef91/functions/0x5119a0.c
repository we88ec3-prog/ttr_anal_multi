
undefined4 * FUN_005119a0(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  bVar1 = true;
  piVar4 = DAT_00fe3714;
  if (*(char *)(DAT_00fe3714[1] + 0x15) == '\0') {
    piVar2 = (int *)DAT_00fe3714[1];
    do {
      piVar4 = piVar2;
      bVar1 = *(int *)(param_2 + 0xc) < piVar4[3];
      if (bVar1) {
        piVar2 = (int *)*piVar4;
      }
      else {
        piVar2 = (int *)piVar4[2];
      }
    } while (*(char *)((int)piVar2 + 0x15) == '\0');
  }
  if (bVar1) {
    if (piVar4 == (int *)*DAT_00fe3714) {
      puVar3 = (undefined4 *)FUN_00511a70(&param_2,1);
      *param_1 = *puVar3;
      *(undefined1 *)(param_1 + 1) = 1;
      return param_1;
    }
    FUN_0053f8a0();
  }
  if (piVar4[3] < *(int *)(param_2 + 0xc)) {
    puVar3 = (undefined4 *)FUN_00511a70(&param_2,bVar1);
    *param_1 = *puVar3;
    *(undefined1 *)(param_1 + 1) = 1;
    return param_1;
  }
  FUN_0089120c(param_2);
  *param_1 = piVar4;
  *(undefined1 *)(param_1 + 1) = 0;
  return param_1;
}

