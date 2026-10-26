
void FUN_00714b50(void)

{
  int iVar1;
  void *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *(undefined4 *)((int)unaff_ESI + 0x100) = 0;
  *(undefined4 *)((int)unaff_ESI + 0x108) = 0;
  iVar1 = FUN_00891268(0x118);
  if (iVar1 != 0) {
    *(int *)((int)unaff_ESI + 0x104) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)((int)unaff_ESI + 0x104) + 4) = *(int *)((int)unaff_ESI + 0x104);
    _memset(unaff_ESI,0,0x100);
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

