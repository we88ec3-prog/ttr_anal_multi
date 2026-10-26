
void FUN_00820120(void)

{
  uint in_EAX;
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  if (in_EAX < 0x924924a) {
    iVar1 = FUN_00891268(in_EAX * 0x1c);
    if (iVar1 != 0) {
      return;
    }
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

