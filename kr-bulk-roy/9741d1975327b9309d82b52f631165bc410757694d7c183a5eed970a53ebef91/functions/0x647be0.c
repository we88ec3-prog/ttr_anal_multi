
void FUN_00647be0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a0bc;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *(undefined4 *)(unaff_EDI + 8);
  uVar2 = *(undefined4 *)(unaff_EDI + 0xc);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(uVar3);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058ee60(&DAT_00faaf80);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 1;
    FUN_0058d410(uVar3);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ee60(&DAT_00faaf80);
  *(undefined4 *)(unaff_EDI + 8) = uVar1;
  *(undefined4 *)(unaff_EDI + 0xc) = uVar2;
  ExceptionList = local_10;
  return;
}

