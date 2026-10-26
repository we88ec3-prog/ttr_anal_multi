
void FUN_007b9300(void)

{
  int iVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bc8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = 0;
  if (*(int *)(unaff_ESI + 0x48) - *(int *)(unaff_ESI + 0x44) >> 2 != 0) {
    iVar1 = **(int **)(unaff_ESI + 0x44);
  }
  if ((DAT_00fb76e8 != 0) && (iVar1 != 0)) {
    FUN_00798370();
  }
  ExceptionList = local_10;
  return;
}

