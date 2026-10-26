
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b4000(void)

{
  int iVar1;
  int unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *(undefined4 *)(unaff_ESI + 8) = 0;
  iVar1 = FUN_00891268(0x28);
  if (iVar1 != 0) {
    *(int *)(unaff_ESI + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);
    *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0x24) = 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0x25) = 1;
    *(undefined4 *)(unaff_ESI + 0x1c) = 0x42200000;
    *(undefined4 *)(unaff_ESI + 0x20) = 0x41200000;
    *(undefined4 *)(unaff_ESI + 0x24) = 0;
    *(undefined4 *)(unaff_ESI + 0x28) = 0;
    *(undefined4 *)(unaff_ESI + 0x2c) = 0;
    if ((_DAT_00fe49f8 & 1) == 0) {
      _DAT_00fe49f8 = _DAT_00fe49f8 | 1;
      FUN_007b3f50();
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

