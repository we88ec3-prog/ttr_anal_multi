
void FUN_00604d50(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946cfe;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar4 = &DAT_00fc7bb0;
  iVar5 = 1;
  while( true ) {
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 0;
      FUN_004fdac0(uVar2);
      _atexit(FUN_00bce150);
    }
    local_8 = 0xffffffff;
    iVar1 = iVar5 >> 0x1f;
    iVar3 = iVar5 / 7 + iVar1;
    if (((iVar3 == iVar1) && (piVar4 != (int *)0x0)) && (*piVar4 == iVar3 - iVar1)) break;
    piVar4 = piVar4 + 0x10;
    iVar5 = iVar5 + 1;
    if (0xfc7d2f < (int)piVar4) {
      ExceptionList = local_10;
      return;
    }
  }
  if (0 < iVar5) {
    FUN_00604e20(param_1,iVar5);
  }
  ExceptionList = local_10;
  return;
}

