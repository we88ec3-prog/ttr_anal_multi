
int FUN_007b2250(void)

{
  int iVar1;
  uint in_ECX;
  undefined **local_14 [3];
  char *local_8;
  
  if (in_ECX == 0) {
    return 0;
  }
  if ((in_ECX < 0x2762763) && (iVar1 = FUN_00891268(in_ECX * 0x68), iVar1 != 0)) {
    return iVar1;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

