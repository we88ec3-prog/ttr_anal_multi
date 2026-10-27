
undefined4 * FUN_007f6f50(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091eb49;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 0;
    FUN_007b7da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce790);
  }
  local_8 = 0xffffffff;
  uVar1 = FUN_007b8180();
  puVar2 = (undefined4 *)FUN_00891268(0x30);
  local_8 = 1;
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = FUN_007dcfb0(uVar1);
    puVar2[1] = 0;
    *puVar2 = IS3D::CFieldObjectInstanceEffect::vftable;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = uVar1;
    ExceptionList = local_10;
    return puVar2;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

