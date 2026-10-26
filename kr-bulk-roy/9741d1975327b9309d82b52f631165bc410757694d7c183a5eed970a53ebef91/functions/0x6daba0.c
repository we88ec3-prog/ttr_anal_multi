
undefined4 * FUN_006daba0(char *param_1,char *param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uStack_34;
  undefined **local_24 [3];
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912251;
  local_10 = ExceptionList;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268(0x40);
  local_18 = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    pcVar1 = (char *)(puVar2 + 2);
    *puVar2 = param_1;
    puVar2[1] = param_2;
    local_8 = 1;
    if (pcVar1 != (char *)0x0) {
      param_1 = pcVar1;
      param_2 = pcVar1;
      FUN_006dac60();
    }
    ExceptionList = local_10;
    return puVar2;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_24,&param_1);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

