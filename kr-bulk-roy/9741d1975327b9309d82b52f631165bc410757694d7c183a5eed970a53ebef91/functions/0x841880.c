
undefined4 * FUN_00841880(char *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uStack_3c;
  undefined **local_2c [3];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906d61;
  local_10 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x90);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(in_ECX + 4);
    puVar1[1] = *(undefined4 *)(in_ECX + 4);
    puVar1[2] = *(undefined4 *)(in_ECX + 4);
    local_20 = puVar1 + 4;
    *(undefined2 *)(puVar1 + 0x22) = 0;
    local_8 = 1;
    if (local_20 != (undefined4 *)0x0) {
      local_1c = local_20;
      FUN_00839330(local_20,param_1);
    }
    ExceptionList = local_10;
    return puVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&param_1);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_2c,&DAT_00c857a8);
}

