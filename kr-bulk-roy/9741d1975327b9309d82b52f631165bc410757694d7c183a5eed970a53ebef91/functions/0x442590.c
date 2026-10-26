
void FUN_00442590(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0xf4) != 0) &&
     ((*(uint *)(*(int *)(unaff_ESI + 0xf4) + 0x28) >> 8 & 1) != 0)) {
    FUN_00441500();
  }
  piVar1 = *(int **)(unaff_ESI + 0x160);
  if (piVar1 == (int *)0x0) {
    return;
  }
  if (((uint)piVar1[10] >> 8 & 1) == 0) {
    return;
  }
  fVar2 = 0.7;
  if (*(char *)(unaff_ESI + 0x180) == '\0') {
    fVar3 = *(float *)(unaff_ESI + 0x17c) + 0.015;
    if (fVar3 < 0.7) goto LAB_004425f4;
  }
  else {
    fVar3 = 0.2;
    fVar2 = *(float *)(unaff_ESI + 0x17c) - 0.015;
    if (fVar2 <= 0.2) goto LAB_004425f4;
  }
  fVar3 = fVar2;
LAB_004425f4:
  *(float *)(unaff_ESI + 0x17c) = fVar3;
  (**(code **)(*piVar1 + 0xd8))(*(undefined4 *)(unaff_ESI + 0x17c));
  (**(code **)(**(int **)(unaff_ESI + 0x160) + 200))();
  if ((*(float *)(unaff_ESI + 0x17c) == 0.2) || (*(float *)(unaff_ESI + 0x17c) == 0.7)) {
    *(bool *)(unaff_ESI + 0x180) = *(char *)(unaff_ESI + 0x180) == '\0';
  }
  return;
}

