
void FUN_007c4040(void)

{
  int iVar1;
  int unaff_ESI;
  uint uVar2;
  uint local_8;
  
  local_8 = 0;
  if (*(int *)(unaff_ESI + 0xa8) - *(int *)(unaff_ESI + 0xa4) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0xa4) + local_8 * 4);
      uVar2 = 0;
      if (*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20) >> 2 != 0) {
        do {
          iVar1 = *(int *)(*(int *)(iVar1 + 0x20) + uVar2 * 4);
          if ((*(int *)(iVar1 + 0x58) == 0) && (*(short *)(iVar1 + 0x54) != 0)) {
            FUN_006edb10(&DAT_00c4fdc4);
            FUN_007c5840(unaff_ESI,*(undefined4 *)(*(int *)(unaff_ESI + 0xa4) + local_8 * 4));
          }
          iVar1 = *(int *)(*(int *)(unaff_ESI + 0xa4) + local_8 * 4);
          uVar2 = uVar2 + 1;
        } while (uVar2 < (uint)(*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20) >> 2));
      }
      local_8 = local_8 + 1;
    } while (local_8 < (uint)(*(int *)(unaff_ESI + 0xa8) - *(int *)(unaff_ESI + 0xa4) >> 2));
  }
  return;
}

