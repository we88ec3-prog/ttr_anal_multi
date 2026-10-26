
void FUN_0065d360(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  undefined1 auStack_20 [4];
  float local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (unaff_ESI[0x30] == 0) {
    (**(code **)(*unaff_ESI + 0x94))(0,DAT_00d61f20 ^ (uint)auStack_20);
    ExceptionList = pvStack_18;
    return;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  local_1c = (float)(unaff_ESI[0x30] - DAT_00f93944);
  if ((-1 < (int)local_1c) && (local_1c != 0.0)) {
    local_1c = (float)(int)local_1c;
    iVar1 = FUN_008fed10();
    iVar1 = iVar1 % 100;
    iVar2 = FUN_008fed10(iVar1);
    iVar2 = iVar2 % 0x3c;
    iVar3 = FUN_008fed10(iVar2);
    FUN_0065d080(unaff_ESI,iVar3 % 100,iVar2,iVar1);
    ExceptionList = local_14;
    return;
  }
  (**(code **)(*unaff_ESI + 0xd4))();
  ExceptionList = local_14;
  return;
}

