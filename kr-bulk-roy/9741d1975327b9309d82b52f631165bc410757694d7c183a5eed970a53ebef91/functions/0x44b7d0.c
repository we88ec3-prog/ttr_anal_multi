
int FUN_0044b7d0(char *param_1)

{
  int iVar1;
  undefined **local_10 [3];
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if ((param_1 < (char *)0x80000000) && (iVar1 = FUN_00891268((int)param_1 * 2), iVar1 != 0)) {
    return iVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_00c857a8);
}

