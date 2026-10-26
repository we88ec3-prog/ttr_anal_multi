
undefined4 FUN_004bded0(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int in_ECX;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924e9a;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar3);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0(0xf4262);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480(uVar3);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  local_14 = (undefined4 *)FUN_00891268(0x20);
  if (local_14 == (undefined4 *)0x0) {
    local_14 = (undefined4 *)0x0;
  }
  else {
    bVar1 = *(byte *)(in_ECX + 8);
    bVar2 = *(byte *)(in_ECX + 7);
    local_14[5] = *(undefined4 *)(in_ECX + 3);
    local_14[1] = 0xffffffff;
    local_14[2] = 0xffffffff;
    local_14[3] = 0;
    local_14[4] = 0xf4299;
    *local_14 = FoxUI::FXUIEventI3::vftable;
    local_14[6] = (uint)bVar2;
    local_14[7] = (uint)bVar1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_00804260(&local_14);
  ExceptionList = local_10;
  return 0;
}

