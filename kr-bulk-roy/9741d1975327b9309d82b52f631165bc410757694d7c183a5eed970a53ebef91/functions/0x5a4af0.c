
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_005a4af0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093614e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = *(uint *)(in_ECX + 0x144);
  if ((*(uint *)(uVar2 + 0x28) >> 8 & 1) == 0) {
    uVar2 = FUN_005a51e0();
    ExceptionList = local_10;
    return uVar2;
  }
  uVar1 = *(undefined4 *)(uVar2 + 0x138);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    uVar2 = _atexit((_func_4879 *)&LAB_00bccc70);
  }
  _DAT_00f95bec = uVar1;
  DAT_00f95be9 = 1;
  ExceptionList = local_10;
  return uVar2 & 0xffffff00;
}

