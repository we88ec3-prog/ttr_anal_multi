
void FUN_00808150(void)

{
  int iVar1;
  int unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *(undefined4 *)(unaff_ESI + 8) = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    *(int *)(unaff_ESI + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);
    *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0x14) = 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0x15) = 1;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

