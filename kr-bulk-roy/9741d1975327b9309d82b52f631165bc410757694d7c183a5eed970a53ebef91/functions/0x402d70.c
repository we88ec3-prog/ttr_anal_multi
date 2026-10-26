
int FUN_00402d70(char *param_1)

{
  int iVar1;
  undefined **local_10 [3];
  
  iVar1 = 0;
  if ((param_1 != (char *)0x0) && (iVar1 = FUN_00891268(param_1), iVar1 == 0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_10,&param_1);
    local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_10,&DAT_00c857a8);
  }
  return iVar1;
}

