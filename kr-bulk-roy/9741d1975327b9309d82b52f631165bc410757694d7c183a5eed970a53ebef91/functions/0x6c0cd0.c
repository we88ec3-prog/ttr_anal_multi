
void FUN_006c0cd0(int param_1)

{
  undefined4 *puVar1;
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093aa0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) == 0x387) {
    puVar1 = (undefined4 *)FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf4350;
      *puVar1 = FoxUI::FXUIEventP1::vftable;
      puVar1[5] = in_ECX;
    }
    FUN_004072a0();
  }
  if (*(int *)(param_1 + 0x10) == 0x68) {
    if ((DAT_00fc1b14 & 1) == 0) {
      DAT_00fc1b14 = DAT_00fc1b14 | 1;
      local_8 = 0;
      FUN_0055ee90();
      _atexit((_func_4879 *)&LAB_00bcdf90);
      local_8 = 0xffffffff;
    }
    FUN_0055f960();
  }
  ExceptionList = local_10;
  return;
}

