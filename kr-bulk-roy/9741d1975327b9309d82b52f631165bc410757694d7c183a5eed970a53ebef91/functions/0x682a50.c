
undefined4 FUN_00682a50(undefined4 param_1,undefined4 param_2,char *param_3)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_30 [4];
  char *local_2c;
  undefined4 local_28;
  undefined **local_20 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093846a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xd4) = param_3;
  local_28 = 0;
  local_2c = (char *)FUN_00891268(0x24,uVar1);
  if (local_2c == (char *)0x0) {
    param_3 = (char *)0x0;
    std::exception::exception((exception *)local_20,&param_3);
    local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_00c857a8);
  }
  *(char **)local_2c = local_2c;
  *(char **)(local_2c + 4) = local_2c;
  *(char **)(local_2c + 8) = local_2c;
  local_2c[0x20] = '\x01';
  local_2c[0x21] = '\x01';
  local_8 = 0;
  FUN_004fc250(DAT_00fe1db4,param_1,param_2,local_30,0);
  FUN_00835c70((undefined4 *)(in_ECX + 0xd4));
  if (param_3 != local_2c) {
    local_8 = 1;
    FUN_0085e680(*(undefined4 *)local_2c,local_2c);
    FUN_0089120c(local_2c);
    ExceptionList = local_10;
    return 1;
  }
  local_8 = 2;
  FUN_0085e680(*(undefined4 *)local_2c,local_2c);
  FUN_0089120c(local_2c);
  ExceptionList = local_10;
  return 0;
}

