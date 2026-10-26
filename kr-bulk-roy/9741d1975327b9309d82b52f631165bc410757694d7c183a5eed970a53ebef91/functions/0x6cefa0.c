
undefined * FUN_006cefa0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fc1730 = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    DAT_00fc172c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fc172c + 4) = DAT_00fc172c;
    *(int *)(DAT_00fc172c + 8) = DAT_00fc172c;
    *(undefined1 *)(DAT_00fc172c + 0x2c) = 1;
    *(undefined1 *)(DAT_00fc172c + 0x2d) = 1;
    return &DAT_00fc1728;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

