
void FUN_0066a500(void)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093276e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) {
    FUN_004067f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf4354);
    FUN_0066a5d0(in_ECX);
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf4352;
    }
    FUN_004072a0();
  }
  ExceptionList = local_10;
  return;
}

