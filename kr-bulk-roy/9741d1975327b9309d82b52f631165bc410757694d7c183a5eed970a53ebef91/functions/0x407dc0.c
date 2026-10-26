
int FUN_00407dc0(void)

{
  int iVar1;
  int in_ECX;
  undefined **local_14 [3];
  char *local_8;
  
  iVar1 = 0;
  if ((in_ECX != 0) && (iVar1 = FUN_00891268(), iVar1 == 0)) {
    local_8 = (char *)0x0;
    std::exception::exception((exception *)local_14,&local_8);
    local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_14,&DAT_00c857a8);
  }
  return iVar1;
}

