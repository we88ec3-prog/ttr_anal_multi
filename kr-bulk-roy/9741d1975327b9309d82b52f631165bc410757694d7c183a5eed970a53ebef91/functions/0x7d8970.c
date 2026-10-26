
void FUN_007d8970(void)

{
  int iVar1;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x60) - *(int *)(unaff_ESI + 0x5c) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x5c) + uVar2 * 4);
      (**(code **)(**(int **)(iVar1 + 8) + 0x1c))(iVar1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x60) - *(int *)(unaff_ESI + 0x5c) >> 2));
  }
  return;
}

