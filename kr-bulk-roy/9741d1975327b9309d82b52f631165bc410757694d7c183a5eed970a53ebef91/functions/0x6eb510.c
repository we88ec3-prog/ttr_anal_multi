
float10 FUN_006eb510(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  uint local_c;
  int iStack_8;
  
  iVar1 = *(int *)(unaff_ESI + 0x14);
  uVar2 = *(uint *)(unaff_ESI + 0x10);
  if (*(uint *)(unaff_ESI + 0x10) == 0 && *(int *)(unaff_ESI + 0x14) == 0) {
    FUN_006eb3c0(&local_c);
    iVar1 = iStack_8;
    uVar2 = local_c;
  }
  return (float10)CONCAT44((iVar1 - *(int *)(unaff_ESI + 0x24)) -
                           (uint)(uVar2 < *(uint *)(unaff_ESI + 0x20)),
                           uVar2 - *(uint *)(unaff_ESI + 0x20)) /
         (float10)*(longlong *)(unaff_ESI + 8);
}

