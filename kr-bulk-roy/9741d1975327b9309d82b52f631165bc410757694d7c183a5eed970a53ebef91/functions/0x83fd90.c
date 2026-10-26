
void FUN_0083fd90(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  uint in_stack_0000001c;
  int local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00914150;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_38 = 0;
  uVar2 = FUN_00840910(&param_2,&local_38,local_14);
  local_8._0_1_ = 1;
  uVar2 = FUN_0077e100(uVar2);
  FUN_007e2910(in_ECX,&local_3c,uVar2);
  cVar1 = (char)local_38;
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_20) {
    FUN_0089120c(local_34);
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = local_34 & 0xffffff00;
  if (cVar1 != '\0') {
    FUN_00840590(in_ECX + 0x10,local_3c + 0x28);
  }
  *param_1 = *(undefined4 *)(local_3c + 0x28);
  if (0xf < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

