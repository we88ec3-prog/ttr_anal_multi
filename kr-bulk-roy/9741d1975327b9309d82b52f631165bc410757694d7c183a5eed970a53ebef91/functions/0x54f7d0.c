
void FUN_0054f7d0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *unaff_EDI;
  undefined **local_14 [3];
  char *local_8;
  
  puVar1 = (undefined4 *)FUN_00891268(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(in_EAX + 4);
    puVar1[1] = *(undefined4 *)(in_EAX + 4);
    puVar1[2] = *(undefined4 *)(in_EAX + 4);
    *(undefined2 *)(puVar1 + 8) = 0;
    if (puVar1 + 3 != (undefined4 *)0x0) {
      puVar1[3] = *unaff_EDI;
      puVar1[4] = unaff_EDI[1];
      puVar1[5] = unaff_EDI[2];
      puVar1[6] = unaff_EDI[3];
      puVar1[7] = unaff_EDI[4];
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

