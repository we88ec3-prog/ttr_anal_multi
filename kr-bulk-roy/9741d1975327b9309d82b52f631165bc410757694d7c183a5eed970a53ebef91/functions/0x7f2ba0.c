
undefined4 * FUN_007f2ba0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c549;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x88,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_007e9bf0(in_ECX + 0x30);
    *puVar1 = IS3D::CEffectElementParticle::vftable;
    puVar1[0x21] = 0;
  }
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 1;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_007cf850();
  puVar1[0x21] = uVar2;
  puVar1[0x1c] = *(undefined4 *)(in_ECX + 0x70);
  ExceptionList = local_10;
  return puVar1;
}

