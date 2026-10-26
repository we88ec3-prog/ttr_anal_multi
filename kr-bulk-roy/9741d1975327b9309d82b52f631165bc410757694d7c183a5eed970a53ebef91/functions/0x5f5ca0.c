
void FUN_005f5ca0(int param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  
  if (*(int *)(unaff_ESI[0x3b] + 0xcc) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)(unaff_ESI[0x3b] + 0xcc) + 0xa4);
  }
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x2d0) = param_1;
  }
  iVar1 = (**(code **)(*unaff_ESI + 0x198))();
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      *(int *)(*(int *)(unaff_ESI[0x3d] + iVar1 * 4) + 0x2d0) = param_1;
      iVar1 = iVar1 + 1;
      iVar2 = (**(code **)(*unaff_ESI + 0x198))();
    } while (iVar1 < iVar2);
  }
  unaff_ESI[0x3c] = param_1;
  return;
}

