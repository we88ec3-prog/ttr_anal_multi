
void FUN_00483b40(void)

{
  int *piVar1;
  float fVar2;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x10c);
  if (((uint)piVar1[10] >> 8 & 1) != 0) {
    if ((float)piVar1[0x20] <= 0.0) {
      (**(code **)(*piVar1 + 0x94))(0);
    }
    else {
      fVar2 = (float)piVar1[0x20] - 0.011666667;
      if (fVar2 <= 0.0) {
        fVar2 = 0.0;
      }
      (**(code **)(*piVar1 + 0xd8))(fVar2);
      (**(code **)(**(int **)(unaff_ESI + 0x10c) + 200))();
    }
  }
  (**(code **)(**(int **)(unaff_ESI + 0x108) + 0x90))
            (*(int *)(*(int *)(unaff_ESI + 0xf8) + 0x250) != -1);
  return;
}

