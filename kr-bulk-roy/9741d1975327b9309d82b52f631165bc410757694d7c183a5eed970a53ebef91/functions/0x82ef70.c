
void FUN_0082ef70(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_ESI = 0;
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 != (undefined4 *)0x0) {
    *unaff_ESI = puVar1;
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined4 **)*unaff_ESI = unaff_ESI;
    unaff_ESI[1] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

