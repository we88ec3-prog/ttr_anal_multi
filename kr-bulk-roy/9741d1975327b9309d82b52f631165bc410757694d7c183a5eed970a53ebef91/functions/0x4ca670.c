
void FUN_004ca670(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  undefined2 *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  puVar1 = (undefined4 *)FUN_00891268(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(unaff_ESI + 4);
    puVar1[1] = *(undefined4 *)(unaff_ESI + 4);
    puVar1[2] = *(undefined4 *)(unaff_ESI + 4);
    *(undefined2 *)(puVar1 + 5) = 0;
    if (puVar1 + 3 != (undefined4 *)0x0) {
      *(undefined2 *)(puVar1 + 3) = *unaff_EDI;
      puVar1[4] = *(undefined4 *)(unaff_EDI + 2);
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

