
void FUN_00690550(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_ECX;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009472de;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_ESI + 0x208) = param_2;
  *(undefined4 *)(unaff_ESI + 0x20c) = in_ECX;
  uVar1 = *(uint *)(*(int *)(unaff_ESI + 0xf8) + 0x28);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(uVar2);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  FUN_0053b890(param_1,*(undefined4 *)(unaff_ESI + 0x208),*(undefined4 *)(unaff_ESI + 0x20c),
               (byte)(uVar1 >> 9) & 1);
  ExceptionList = local_10;
  return;
}

