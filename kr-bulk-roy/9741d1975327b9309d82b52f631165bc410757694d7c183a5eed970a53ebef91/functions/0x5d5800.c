
undefined4 * FUN_005d5800(void)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911d18;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = _malloc(0xf8);
  local_8 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0075bb00(uVar1);
    *puVar2 = FUI::CExpBar::vftable;
    puVar2[0x3c] = 7;
    puVar2[0x3b] = 0;
    *(undefined2 *)(puVar2 + 0x37) = 0;
    ExceptionList = local_10;
    return puVar2;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

