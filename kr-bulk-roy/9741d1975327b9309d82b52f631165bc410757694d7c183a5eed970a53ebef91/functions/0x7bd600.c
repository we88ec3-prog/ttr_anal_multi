
void FUN_007bd600(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_1;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      if (0xf < (uint)piVar2[0x11]) {
        FUN_0089120c(piVar2[0xc]);
      }
      piVar2[0x11] = 0xf;
      piVar2[0x10] = 0;
      *(undefined1 *)(piVar2 + 0xc) = 0;
      if (0xf < (uint)piVar2[10]) {
        FUN_0089120c(piVar2[5]);
      }
      piVar2[10] = 0xf;
      piVar2[9] = 0;
      *(undefined1 *)(piVar2 + 5) = 0;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  return;
}

