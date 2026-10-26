
void FUN_00736800(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined **local_14 [3];
  char *local_8;
  
  puVar1 = (undefined4 *)FUN_00891268(100);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(in_ECX + 4);
    puVar1[1] = *(undefined4 *)(in_ECX + 4);
    puVar1[2] = *(undefined4 *)(in_ECX + 4);
    *(undefined2 *)(puVar1 + 0x18) = 0;
    if (puVar1 + 3 != (undefined4 *)0x0) {
      puVar1[3] = *in_EAX;
      puVar1 = puVar1 + 4;
      for (iVar2 = 0x14; in_EAX = in_EAX + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar1 = *in_EAX;
        puVar1 = puVar1 + 1;
      }
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

