
void FUN_0045b090(void)

{
  int *piVar1;
  float fVar2;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0xf4);
  if (((uint)piVar1[10] >> 8 & 1) != 0) {
    if (0.0 < (float)piVar1[0x20]) {
      fVar2 = (float)piVar1[0x20] - 0.011666667;
      if (fVar2 <= 0.0) {
        fVar2 = 0.0;
      }
      (**(code **)(*piVar1 + 0xd8))(fVar2);
      (**(code **)(**(int **)(unaff_ESI + 0xf4) + 200))();
      return;
    }
    (**(code **)(*piVar1 + 0x94))(0);
  }
  return;
}

