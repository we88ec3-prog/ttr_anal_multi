
undefined4 FUN_007f2ee0(float param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int *piVar4;
  
  iVar1 = *(int *)(in_ECX + 0x84);
  if (iVar1 == 0) {
    return 1;
  }
  if (param_1 < *(float *)(iVar1 + 0x70)) {
    return 0;
  }
  piVar4 = *(int **)(iVar1 + 0x5c);
  uVar2 = *(int *)(iVar1 + 0x60) - (int)piVar4 >> 2;
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      if (*(int *)(*piVar4 + 0x88) != 0) {
        return 0;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < uVar2);
  }
  return 1;
}

