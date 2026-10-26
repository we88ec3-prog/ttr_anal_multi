
undefined * FUN_005292c0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fab23c = 0;
  iVar1 = FUN_00891268(0x50);
  if (iVar1 != 0) {
    DAT_00fab238 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fab238 + 4) = DAT_00fab238;
    *(int *)(DAT_00fab238 + 8) = DAT_00fab238;
    *(undefined1 *)(DAT_00fab238 + 0x4c) = 1;
    *(undefined1 *)(DAT_00fab238 + 0x4d) = 1;
    return &DAT_00fab234;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

