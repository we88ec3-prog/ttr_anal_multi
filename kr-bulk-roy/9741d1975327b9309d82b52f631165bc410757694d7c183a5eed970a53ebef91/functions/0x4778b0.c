
void FUN_004778b0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  int unaff_EDI;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941310;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_38;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0xf4) + 0x298);
  uVar3 = (uint)DAT_00f942c8;
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0xf8) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0xfc) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0x100) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0x104) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0x108) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0x10c) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0x110) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0x114) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EDI + 0x118) + 0x298);
  if (uVar1 != 0) {
    uVar3 = uVar3 + uVar1;
  }
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 1;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  if ((DAT_00fb936c <= uVar3) && ((DAT_00fb9368 & 1) == 0)) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 2;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 3;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  local_c = 0xffffffff;
  uVar2 = FUN_0040e460(&DAT_00bf2bf8);
  local_c = 4;
  FUN_00757800(uVar2);
  local_c = 0xffffffff;
  if (7 < local_24) {
    FUN_0089120c(local_38[0]);
  }
  local_38[0] = local_38[0] & 0xffff0000;
  local_24 = 7;
  local_28 = 0;
  (**(code **)(**(int **)(unaff_EDI + 0x154) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_38);
  return;
}

