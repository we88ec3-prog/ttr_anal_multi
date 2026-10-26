
void FUN_0071f670(void)

{
  undefined **local_14 [3];
  char *local_8;
  
  local_8 = "bad allocation";
  std::exception::exception((exception *)local_14,&local_8,1);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

