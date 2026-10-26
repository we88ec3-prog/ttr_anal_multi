
void FUN_0048a440(void)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093119a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 0;
    FUN_004d4d10(uVar1);
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  DAT_00fb1308 = DAT_00fb1308 + -1;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 1;
    FUN_004d4d10(uVar1);
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  if (DAT_00fb1308 == 0) {
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 2;
      FUN_004d4d10(uVar1);
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = 0xffffffff;
    FUN_004d4fa0();
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4366;
    }
    FUN_004072a0();
  }
  ExceptionList = local_10;
  return;
}

