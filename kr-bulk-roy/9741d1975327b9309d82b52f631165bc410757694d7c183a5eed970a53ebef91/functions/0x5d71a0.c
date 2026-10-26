
void FUN_005d71a0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  iVar1 = DAT_00f95bfc;
  local_8 = 0xffffffff;
  if (DAT_00f95bfc != 0) {
    iVar2 = (**(code **)(*in_ECX + 0x58))();
    if (iVar2 == iVar1) {
      (**(code **)(*in_ECX + 0x54))();
      iVar1 = *in_ECX;
      uVar3 = (**(code **)(iVar1 + 0x1a0))();
      (**(code **)(iVar1 + 0x50))(uVar3);
    }
  }
  ExceptionList = local_10;
  return;
}

