
int FUN_006de8b0(void)

{
  int iVar1;
  uint in_ECX;
  char *local_10;
  undefined **local_c [3];
  
  if (in_ECX == 0) {
    return 0;
  }
  if ((in_ECX < 0x40000000) && (iVar1 = FUN_00891268(in_ECX * 4), iVar1 != 0)) {
    return iVar1;
  }
  local_10 = (char *)0x0;
  std::exception::exception((exception *)local_c,&local_10);
  local_c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_c,&DAT_00c857a8);
}

