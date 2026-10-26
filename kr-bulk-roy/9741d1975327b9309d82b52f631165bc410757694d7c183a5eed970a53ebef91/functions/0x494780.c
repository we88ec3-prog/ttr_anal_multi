
undefined4 FUN_00494780(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  DAT_00f93934 = DAT_00f93934 + -1;
  DVar1 = timeGetTime();
  uVar2 = DVar1 - *(int *)(in_ECX + 0xbf6c) >> 1;
  if (2000 < uVar2) {
    ExceptionList = local_14;
    return 0x80004005;
  }
  *(uint *)(in_ECX + 0xbf74) = uVar2;
  iVar4 = *(int *)(param_1 + 2) + uVar2;
  iVar3 = FUN_00404ba0();
  *(int *)(iVar3 + 0x5f5c) = iVar4;
  *(int *)(iVar3 + 0x5f64) = iVar4;
  DVar1 = timeGetTime();
  *(DWORD *)(iVar3 + 0x5f60) = DVar1;
  ExceptionList = local_14;
  return 0;
}

