
void FUN_0053f900(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  puVar1 = (undefined4 *)FUN_00891268(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = DAT_00fe188c;
    puVar1[1] = DAT_00fe188c;
    puVar1[2] = DAT_00fe188c;
    *(undefined2 *)(puVar1 + 5) = 0;
    if (puVar1 + 3 != (undefined4 *)0x0) {
      puVar1[3] = *unaff_ESI;
      puVar1[4] = unaff_ESI[1];
    }
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

