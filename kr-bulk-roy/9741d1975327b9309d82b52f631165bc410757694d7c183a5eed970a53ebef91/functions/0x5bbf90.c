
void FUN_005bbf90(void)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  int unaff_ESI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009471ba;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar2 = DAT_00f94390 & 1;
  *(undefined1 *)(*(int *)(unaff_ESI + 0x2d0) + 0x100) = DAT_00f942d9;
  if (uVar2 == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar3 = DAT_00f942da;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar1 = *(int *)(unaff_ESI + 0x2cc);
  *(undefined1 *)(iVar1 + 0x10d) = DAT_00f942d9;
  *(undefined1 *)(iVar1 + 0x10c) = uVar3;
  if ((*(uint *)(*(int *)(unaff_ESI + 0x2cc) + 0x28) >> 8 & 1) != 0) {
    FUN_004261e0();
  }
  ExceptionList = local_14;
  return;
}

