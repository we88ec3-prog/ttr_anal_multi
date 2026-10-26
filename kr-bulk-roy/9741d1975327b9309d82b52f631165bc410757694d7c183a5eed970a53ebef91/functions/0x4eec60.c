
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004eec60(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  _DAT_00fb7458 = 0;
  iVar1 = FUN_00891268(0x14);
  if (iVar1 != 0) {
    DAT_00fb7454 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fb7454 + 4) = DAT_00fb7454;
    *(int *)(DAT_00fb7454 + 8) = DAT_00fb7454;
    *(undefined1 *)(DAT_00fb7454 + 0x12) = 1;
    *(undefined1 *)(DAT_00fb7454 + 0x13) = 1;
    return &DAT_00fb7450;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

