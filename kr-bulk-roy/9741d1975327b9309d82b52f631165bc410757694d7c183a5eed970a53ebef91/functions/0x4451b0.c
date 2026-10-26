
void FUN_004451b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 in_ECX;
  int unaff_ESI;
  undefined4 unaff_EDI;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092a19e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_ESI + 0x29c) = param_4;
  *(undefined4 *)(unaff_ESI + 0x2a0) = in_ECX;
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_8 = 0;
    FUN_00822000(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  local_8 = 0xffffffff;
  FUN_008438c0(&stack0x00000010);
  if (local_14 == DAT_00fb9374) {
    uVar1 = 0;
  }
  else {
    uVar1 = (undefined2)*(undefined4 *)(local_14 + 0x10);
  }
  *(undefined2 *)(unaff_ESI + 0x298) = uVar1;
  FUN_005d7240(unaff_EDI,param_1,param_2,param_3);
  ExceptionList = local_10;
  return;
}

