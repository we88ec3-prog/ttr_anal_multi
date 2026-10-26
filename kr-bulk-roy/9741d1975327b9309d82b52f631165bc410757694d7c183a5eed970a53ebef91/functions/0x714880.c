
undefined4 * FUN_00714880(char *param_1,char *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uStack_34;
  undefined **local_24 [3];
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ce11;
  local_10 = ExceptionList;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x24);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    param_1 = (char *)(puVar1 + 2);
    puVar1[1] = param_2;
    local_8 = 1;
    if (param_1 != (char *)0x0) {
      puVar1[6] = 0;
      puVar1[7] = 0xf;
      *param_1 = '\0';
      param_2 = param_1;
      FUN_00403040(param_3,0,0xffffffff);
    }
    ExceptionList = local_10;
    return puVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_24,&param_1);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

