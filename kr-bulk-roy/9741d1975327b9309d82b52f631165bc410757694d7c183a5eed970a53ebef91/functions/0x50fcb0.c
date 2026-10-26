
undefined4 * FUN_0050fcb0(char *param_1)

{
  undefined4 *puVar1;
  uint uStack_40;
  undefined **local_2c [3];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009104f1;
  local_10 = ExceptionList;
  uStack_40 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_40;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x4c);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = DAT_00fe17c4;
    puVar1[1] = DAT_00fe17c4;
    puVar1[2] = DAT_00fe17c4;
    local_20 = puVar1 + 3;
    *(undefined2 *)(puVar1 + 0x12) = 0;
    local_8 = 1;
    if (local_20 != (undefined4 *)0x0) {
      local_1c = local_20;
      FUN_00510350(local_20,param_1);
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

