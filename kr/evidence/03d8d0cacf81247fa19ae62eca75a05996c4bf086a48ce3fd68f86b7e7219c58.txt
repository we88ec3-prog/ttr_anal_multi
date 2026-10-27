
void FUN_004dffb0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = *in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (iVar1 == DAT_00f93930) {
    *(int **)(param_1 + 0xf8) = in_ECX;
  }
  uVar2 = FUN_0057ef20();
  FUN_0057e850(param_1 + 0x18,uVar2);
  ExceptionList = local_14;
  return;
}

