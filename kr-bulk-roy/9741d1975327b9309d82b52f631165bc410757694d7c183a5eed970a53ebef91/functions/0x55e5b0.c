
void FUN_0055e5b0(char *param_1)

{
  undefined4 *puVar1;
  int unaff_ESI;
  undefined **local_10 [3];
  
  puVar1 = (undefined4 *)FUN_00891268(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(unaff_ESI + 4);
    puVar1[1] = *(undefined4 *)(unaff_ESI + 4);
    puVar1[2] = *(undefined4 *)(unaff_ESI + 4);
    *(undefined2 *)((int)puVar1 + 0xe) = 0;
    if (puVar1 + 3 != (undefined4 *)0x0) {
      *(undefined2 *)(puVar1 + 3) = *(undefined2 *)param_1;
    }
    return;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_10,&param_1);
  local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_00c857a8);
}

