
undefined4 * FUN_00743e70(char *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined **local_10 [3];
  
  pcVar1 = param_1;
  puVar2 = (undefined4 *)FUN_00891268(0x2820);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *(undefined4 *)(unaff_EDI + 4);
    puVar2[1] = *(undefined4 *)(unaff_EDI + 4);
    puVar2[2] = *(undefined4 *)(unaff_EDI + 4);
    *(undefined2 *)(puVar2 + 0xa06) = 0;
    if (puVar2 + 4 != (undefined4 *)0x0) {
      puVar2[4] = *(undefined4 *)pcVar1;
      puVar2[5] = *(undefined4 *)(pcVar1 + 4);
      FID_conflict__memcpy(puVar2 + 6,pcVar1 + 8,0x2800);
    }
    return puVar2;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_00c857a8);
}

