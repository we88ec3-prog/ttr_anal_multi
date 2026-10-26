
void FUN_006de910(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  uint uVar4;
  char *local_10;
  undefined **local_c [3];
  
  if (((*(int *)(unaff_ESI + 0xc) + *(int *)(unaff_ESI + 0x10) & 3U) == 0) &&
     (*(uint *)(unaff_ESI + 8) <= *(int *)(unaff_ESI + 0x10) + 4U >> 2)) {
    FUN_006de750(unaff_ESI);
  }
  uVar3 = *(int *)(unaff_ESI + 0xc) + *(int *)(unaff_ESI + 0x10);
  uVar4 = uVar3 >> 2;
  if (*(uint *)(unaff_ESI + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(unaff_ESI + 8);
  }
  if (*(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) == 0) {
    iVar2 = FUN_00891268(0x10);
    if (iVar2 == 0) {
      local_10 = (char *)0x0;
      std::exception::exception((exception *)local_c,&local_10);
      local_c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_c,&DAT_00c857a8);
    }
    *(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) = iVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) + (uVar3 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 1;
  return;
}

