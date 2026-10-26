
float10 FUN_004c9ab0(void)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  
  iVar2 = *(int *)(unaff_ESI + 0x15c);
  if (((iVar2 != 0) && (*(int *)(unaff_ESI + 0x370) != 0)) && (*(int *)(iVar2 + 0xac) != 0)) {
    fVar3 = (float10)(**(code **)(**(int **)(iVar2 + 0xac) + 0xc))();
    if ((float)fVar3 != 0.0) {
      iVar2 = *(int *)(unaff_ESI + 0x15c);
      fVar1 = *(float *)(iVar2 + 0xb4);
      if (*(int *)(iVar2 + 0xac) != 0) {
        fVar3 = (float10)(**(code **)(**(int **)(iVar2 + 0xac) + 0xc))();
        return (float10)(fVar1 / (float)fVar3);
      }
      return (float10)(fVar1 / 0.0);
    }
  }
  return (float10)1;
}

