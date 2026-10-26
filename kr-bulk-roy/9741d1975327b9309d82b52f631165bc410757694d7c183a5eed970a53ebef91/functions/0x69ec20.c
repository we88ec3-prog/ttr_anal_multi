
void FUN_0069ec20(void)

{
  undefined4 *puVar1;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924ddc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar1 = (undefined4 *)FUN_00891268(0x18);
  local_14 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = 0;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[4] = 0xf42b0;
    *puVar1 = FoxUI::FXUIEventB1::vftable;
    *(undefined1 *)(puVar1 + 5) = 1;
    local_14 = puVar1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_00804260(&local_14);
  ExceptionList = local_10;
  return;
}

