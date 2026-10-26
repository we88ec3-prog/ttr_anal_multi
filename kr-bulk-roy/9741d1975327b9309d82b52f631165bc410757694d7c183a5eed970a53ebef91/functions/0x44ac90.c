
void FUN_0044ac90(void)

{
  int iVar1;
  undefined1 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_ESI = 6;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  iVar1 = FUN_00891268(0x14);
  if (iVar1 != 0) {
    *(int *)(unaff_ESI + 8) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)(unaff_ESI + 8) + 4) = *(int *)(unaff_ESI + 8);
    *(int *)(*(int *)(unaff_ESI + 8) + 8) = *(int *)(unaff_ESI + 8);
    *(undefined1 *)(*(int *)(unaff_ESI + 8) + 0x10) = 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 8) + 0x11) = 1;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

