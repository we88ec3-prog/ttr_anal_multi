
undefined4 FUN_00547f90(void)

{
  undefined4 uVar1;
  int in_ECX;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094779e;
  local_10 = ExceptionList;
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  ExceptionList = &local_10;
  uVar1 = FUN_005452c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_8 = 0xffffffff;
  }
  uVar2 = (uint)(DAT_00fb9011 == '\x01');
  FUN_00434250(uVar2);
  FUN_00544a00(uVar2);
  ExceptionList = local_10;
  return uVar1;
}

