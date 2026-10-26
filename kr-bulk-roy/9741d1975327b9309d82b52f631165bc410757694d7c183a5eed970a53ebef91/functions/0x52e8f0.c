
void FUN_0052e8f0(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  puVar1 = (undefined4 *)FUN_00891268(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(unaff_EDI + 4);
    puVar1[1] = *(undefined4 *)(unaff_EDI + 4);
    puVar1[2] = *(undefined4 *)(unaff_EDI + 4);
    *(undefined2 *)(puVar1 + 0xe) = 0;
    if (puVar1 + 4 != (undefined4 *)0x0) {
      puVar1[4] = *unaff_ESI;
      puVar1[6] = unaff_ESI[2];
      *(undefined2 *)(puVar1 + 7) = *(undefined2 *)(unaff_ESI + 3);
      puVar1[8] = unaff_ESI[4];
      puVar1[9] = unaff_ESI[5];
      puVar1[10] = unaff_ESI[6];
      puVar1[0xb] = unaff_ESI[7];
      puVar1[0xc] = unaff_ESI[8];
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

