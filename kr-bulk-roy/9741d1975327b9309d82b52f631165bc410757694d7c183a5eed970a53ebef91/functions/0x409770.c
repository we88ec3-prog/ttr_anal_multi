
void FUN_00409770(void)

{
  int iVar1;
  float fVar2;
  uint in_EAX;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x100);
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0xf4) - *(int *)(iVar1 + 0xf0);
    uVar4 = 0;
    in_EAX = iVar3 >> 2;
    if (in_EAX != 0) {
      piVar5 = *(int **)(iVar1 + 0xf0);
      do {
        if (*(int *)(*piVar5 + 0x25c) != 0) {
          uVar4 = CONCAT31((int3)(iVar3 >> 10),1);
          goto LAB_004097b5;
        }
        uVar4 = uVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar4 < in_EAX);
    }
  }
  uVar4 = in_EAX & 0xffffff00;
LAB_004097b5:
  (**(code **)(**(int **)(unaff_ESI + 0xf8) + 0x90))(uVar4);
  piVar5 = *(int **)(unaff_ESI + 0xfc);
  if (((uint)piVar5[10] >> 8 & 1) != 0) {
    if (0.0 < (float)piVar5[0x20]) {
      fVar2 = (float)piVar5[0x20] - 0.011666667;
      if (fVar2 <= 0.0) {
        fVar2 = 0.0;
      }
      (**(code **)(*piVar5 + 0xd8))(fVar2);
      (**(code **)(**(int **)(unaff_ESI + 0xfc) + 200))();
      return;
    }
    (**(code **)(*piVar5 + 0x94))(0);
  }
  return;
}

