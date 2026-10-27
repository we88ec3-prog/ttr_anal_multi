
bool FUN_00545f30(undefined4 param_1,float param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00938a0e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  uVar3 = DAT_00fb7c18;
  if (DAT_00fab1d0 != 0) {
    if (param_2 == 0.0) {
      iVar1 = FUN_0082cdf0();
      ExceptionList = local_14;
      return iVar1 == 0;
    }
    if ((DAT_00fb7c18 & 1) == 0) {
      uVar3 = DAT_00fb7c18 | 1;
      DAT_00fb7c18 = uVar3;
      FUN_004449d0();
    }
    iVar1 = 0;
    while (iVar2 = FUN_0082cdf0(), iVar2 != 0) {
      if ((uVar3 & 1) == 0) {
        uVar3 = uVar3 | 1;
        FUN_004449d0();
      }
      iVar1 = iVar1 + 1;
      if (2 < iVar1) {
        DAT_00fb7c18 = uVar3;
        ExceptionList = local_14;
        return false;
      }
    }
  }
  DAT_00fb7c18 = uVar3;
  ExceptionList = local_14;
  return true;
}

