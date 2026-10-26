
void FUN_00a99680(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  iVar1 = FUN_00891268(0xa4);
  if (iVar1 != 0) {
    DAT_00fbaae8 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fbaae8 + 4) = DAT_00fbaae8;
    *(int *)(DAT_00fbaae8 + 8) = DAT_00fbaae8;
    *(undefined1 *)(DAT_00fbaae8 + 0xa0) = 1;
    *(undefined1 *)(DAT_00fbaae8 + 0xa1) = 1;
    _atexit(FUN_00bceb90);
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

