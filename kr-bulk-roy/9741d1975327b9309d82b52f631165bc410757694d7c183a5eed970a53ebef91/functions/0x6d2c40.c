
void FUN_006d2c40(void)

{
  int iVar1;
  int in_ECX;
  undefined **local_14 [3];
  char *local_8;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  iVar1 = FUN_00891268(0x24);
  if (iVar1 != 0) {
    *(int *)(in_ECX + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *(undefined1 *)(*(int *)(in_ECX + 4) + 0x20) = 1;
    *(undefined1 *)(*(int *)(in_ECX + 4) + 0x21) = 1;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

