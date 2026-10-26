
void FUN_0049d640(void)

{
  int iVar1;
  int *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  unaff_ESI[1] = 0;
  iVar1 = FUN_00891268(0xc);
  if (iVar1 != 0) {
    *unaff_ESI = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*unaff_ESI + 4) = *unaff_ESI;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

