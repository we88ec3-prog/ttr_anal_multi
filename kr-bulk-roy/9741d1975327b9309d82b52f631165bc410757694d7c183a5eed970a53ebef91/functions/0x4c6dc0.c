
void FUN_004c6dc0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined2 *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  puVar1 = (undefined4 *)FUN_00891268(0x2c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(in_EAX + 4);
    puVar1[1] = *(undefined4 *)(in_EAX + 4);
    puVar1[2] = *(undefined4 *)(in_EAX + 4);
    *(undefined2 *)(puVar1 + 10) = 0;
    if (puVar1 + 3 != (undefined4 *)0x0) {
      *(undefined2 *)(puVar1 + 3) = *unaff_EDI;
      puVar1[4] = *(undefined4 *)(unaff_EDI + 2);
      puVar1[5] = *(undefined4 *)(unaff_EDI + 4);
      puVar1[6] = *(undefined4 *)(unaff_EDI + 6);
      puVar1[7] = *(undefined4 *)(unaff_EDI + 8);
      puVar1[8] = *(undefined4 *)(unaff_EDI + 10);
      puVar1[9] = *(undefined4 *)(unaff_EDI + 0xc);
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

