
void FUN_004362d0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar1 = *(undefined4 *)((int)param_1 + 0x15c);
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf4346;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = uVar1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  param_1 = puVar2;
  FUN_00804260(&param_1);
  ExceptionList = local_10;
  return;
}

