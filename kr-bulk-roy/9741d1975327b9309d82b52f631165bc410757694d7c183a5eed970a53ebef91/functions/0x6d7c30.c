
void FUN_006d7c30(void)

{
  int iVar1;
  int in_ECX;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092170e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xc) != -1) {
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8 = 0;
      FUN_00734ef0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    local_8 = 0xffffffff;
    local_14 = *(undefined4 *)(in_ECX + 0xc);
    FUN_00736180(&local_14);
    if (local_18 != DAT_00fb7b80) {
      iVar1 = (**(code **)(*DAT_00fb7b78 + 0x2c))(*(undefined4 *)(local_18 + 0xc));
      if (iVar1 != 0) {
        FUN_00735ed0(&DAT_00fb7b7c,&local_18,local_18);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

