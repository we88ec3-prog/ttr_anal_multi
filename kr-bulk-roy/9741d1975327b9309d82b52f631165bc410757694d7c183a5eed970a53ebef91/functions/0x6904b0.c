
void FUN_006904b0(undefined4 param_1)

{
  uint uVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009472de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(uint *)(*(int *)(unaff_ESI + 0xf8) + 0x28);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  FUN_0053b890(param_1,*(undefined4 *)(unaff_ESI + 0x208),*(undefined4 *)(unaff_ESI + 0x20c),
               (byte)(uVar1 >> 9) & 1);
  ExceptionList = local_10;
  return;
}

