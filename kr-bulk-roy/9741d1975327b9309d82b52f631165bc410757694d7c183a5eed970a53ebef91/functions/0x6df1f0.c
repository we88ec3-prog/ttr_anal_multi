
void FUN_006df1f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    puVar2 = *(undefined4 **)(*(int *)(unaff_ESI + 4) + *(int *)(unaff_ESI + 0xc) * 4);
    if (0xf < (uint)puVar2[5]) {
      FUN_0089120c(*puVar2);
    }
    puVar2[5] = 0xf;
    puVar2[4] = 0;
    *(undefined1 *)puVar2 = 0;
    *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;
    if (*(uint *)(unaff_ESI + 8) <= *(uint *)(unaff_ESI + 0xc)) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    piVar1 = (int *)(unaff_ESI + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
  }
  return;
}

