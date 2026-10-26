
void FUN_00518f20(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(unaff_ESI + 4);
    puVar1[1] = *(undefined4 *)(unaff_ESI + 4);
    puVar1[2] = *(undefined4 *)(unaff_ESI + 4);
    *(undefined2 *)((int)puVar1 + 0x12) = 0;
    if (puVar1 + 3 != (undefined4 *)0x0) {
      *(undefined1 *)(puVar1 + 3) = *unaff_EDI;
      *(undefined4 *)((int)puVar1 + 0xe) = *(undefined4 *)(unaff_EDI + 2);
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

