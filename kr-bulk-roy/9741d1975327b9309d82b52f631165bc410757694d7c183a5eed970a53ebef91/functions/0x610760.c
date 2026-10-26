
void FUN_00610760(void)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d6fc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  iVar1 = DAT_00f943f0;
  local_8 = 0xffffffff;
  if (DAT_00f943f0 != 0) {
    local_14 = (uint)*(byte *)(unaff_EDI + 0x15c) * 10000 + (uint)*(byte *)(unaff_EDI + 0x15d);
    FUN_0082ef00(&local_14);
    if ((local_18 != *(int *)(iVar1 + 0xc)) && (*(int *)(local_18 + 0x10) != 0)) goto LAB_00610832;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
LAB_00610832:
  FUN_00745060();
  ExceptionList = local_10;
  return;
}

