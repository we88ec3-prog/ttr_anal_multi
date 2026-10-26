
void FUN_0058b0a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091698c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  uVar2 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = param_1;
    *puVar1 = FoxUI::FXUIEventI1::vftable;
    puVar1[5] = param_2;
  }
  if ((DAT_00faafd4 & 1) == 0) {
    DAT_00faafd4 = DAT_00faafd4 | 1;
    local_8 = 0;
    FUN_0044dfb0();
    _atexit(FUN_00bccd10);
    local_8 = 0xffffffff;
  }
  local_14 = 0xef;
  FUN_0082ef00(&local_14);
  if (local_18 != (undefined4 *)DAT_00faafe0) {
    uVar2 = *(undefined4 *)((int)local_18 + 0x10);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  local_1c = uVar2;
  local_18 = puVar1;
  FUN_007b6e80(&local_1c);
  ExceptionList = local_10;
  return;
}

