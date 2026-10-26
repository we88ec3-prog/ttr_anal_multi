
void FUN_005f6130(undefined1 param_1)

{
  int iVar1;
  int *unaff_ESI;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = (**(code **)(*unaff_ESI + 0x198))();
  if (0 < iVar1) {
    do {
      *(undefined1 *)(*(int *)(unaff_ESI[0x3d] + iVar2 * 4) + 0x2a0) = param_1;
      iVar2 = iVar2 + 1;
      iVar1 = (**(code **)(*unaff_ESI + 0x198))();
    } while (iVar2 < iVar1);
  }
  return;
}

