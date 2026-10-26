
void FUN_00572b20(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int unaff_EDI;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916b98;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = FUN_00574940(&param_1,param_2,uVar2);
  local_8 = 0;
  uVar1 = *(undefined4 *)(unaff_EDI + 4);
  uVar3 = FUN_004f9b40(uVar3);
  FUN_00574ab0(uVar1,uVar3);
  if (0xf < local_1c) {
    FUN_0089120c(local_30);
  }
  *(undefined4 *)(unaff_EDI + 0x1c) = param_1;
  *(undefined4 *)(unaff_EDI + 0x48) = 1;
  *(undefined4 *)(unaff_EDI + 0x40) = 0;
  *(undefined4 *)(unaff_EDI + 0x44) = 0;
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

