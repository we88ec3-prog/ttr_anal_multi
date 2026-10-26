
void FUN_006a9a90(void)

{
  int unaff_EDI;
  byte bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b76e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = (*(uint *)(*(int *)(unaff_EDI + 0xf4) + 0x28) >> 9 & 1) != 0;
  if ((*(uint *)(*(int *)(unaff_EDI + 0xf8) + 0x28) >> 9 & 1) != 0) {
    bVar1 = bVar1 | 2;
  }
  if ((*(uint *)(*(int *)(unaff_EDI + 0xfc) + 0x28) >> 9 & 1) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  local_8 = 0xffffffff;
  FUN_004ed1f0(*(undefined4 *)(unaff_EDI + 0x108),bVar1);
  ExceptionList = local_10;
  return;
}

