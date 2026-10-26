
undefined4 FUN_0056e6e0(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b1ee;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x3c) != 0) {
    FUN_004a47d0(*(int *)(in_ECX + 0x3c));
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  *(undefined4 *)(in_ECX + 0x40) = 0;
  FUN_00402a70("Map/Minimap/minimapSymbols.eif",0x1e);
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880(uVar1);
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  FUN_0056fd00();
  ExceptionList = local_10;
  return 1;
}

