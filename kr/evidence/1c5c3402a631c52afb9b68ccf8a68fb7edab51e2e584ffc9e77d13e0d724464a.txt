
void FUN_0082f470(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_ESI = 0;
  unaff_ESI[0x49] = 0;
  iVar1 = FUN_00891268(0x20);
  if (iVar1 != 0) {
    unaff_ESI[0x48] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(unaff_ESI[0x48] + 4) = unaff_ESI[0x48];
    *(undefined4 *)(unaff_ESI[0x48] + 8) = unaff_ESI[0x48];
    *(undefined1 *)(unaff_ESI[0x48] + 0x1c) = 1;
    *(undefined1 *)(unaff_ESI[0x48] + 0x1d) = 1;
    unaff_ESI[0x4b] = 0;
    puVar2 = unaff_ESI + 0x27;
    iVar1 = 0x20;
    do {
      puVar2[-0x20] = 0;
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    unaff_ESI[0x4d] = 0;
    unaff_ESI[0x4c] = 0;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

