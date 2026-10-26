
void FUN_004f07f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  uint uVar4;
  undefined **local_14 [3];
  char *local_8;
  
  if (((*(byte *)(unaff_ESI + 0xc) & 3) == 0) &&
     (*(uint *)(unaff_ESI + 8) <= *(int *)(unaff_ESI + 0x10) + 4U >> 2)) {
    FUN_00636f70(unaff_ESI);
  }
  iVar2 = *(int *)(unaff_ESI + 0xc);
  if (iVar2 == 0) {
    iVar2 = *(int *)(unaff_ESI + 8) * 4;
  }
  uVar3 = iVar2 - 1;
  uVar4 = uVar3 >> 2;
  if (*(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) == 0) {
    iVar2 = FUN_00891268(0x10);
    if (iVar2 == 0) {
      local_8 = (char *)0x0;
      std::exception::exception((exception *)local_14,&local_8);
      local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_14,&DAT_00c857a8);
    }
    *(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) = iVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(unaff_ESI + 4) + uVar4 * 4) + (uVar3 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 1;
  *(uint *)(unaff_ESI + 0xc) = uVar3;
  return;
}

