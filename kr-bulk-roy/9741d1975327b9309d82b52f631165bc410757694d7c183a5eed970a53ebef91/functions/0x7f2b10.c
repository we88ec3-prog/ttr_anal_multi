
int FUN_007f2b10(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091869e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = in_ECX + 2;
  *piVar1 = *piVar1 + -1;
  iVar3 = in_ECX[2];
  if (*piVar1 == 0) {
    if (in_ECX[1] != 0) {
      (**(code **)(*in_ECX + 8))(uVar2);
      if ((DAT_00fe324c & 1) == 0) {
        DAT_00fe324c = DAT_00fe324c | 1;
        local_8 = 0;
        FUN_007cdeb0();
        _atexit((_func_4879 *)&LAB_00bd09b0);
        local_8 = 0xffffffff;
      }
      FUN_007cf480();
    }
    iVar3 = in_ECX[2];
  }
  ExceptionList = local_10;
  return iVar3;
}

