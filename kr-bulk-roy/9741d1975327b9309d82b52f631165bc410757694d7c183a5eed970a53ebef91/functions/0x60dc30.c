
/* WARNING: Removing unreachable block (ram,0x0060dcbf) */

void FUN_0060dc30(int param_1)

{
  uint uVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x15c) != -1) {
    local_8 = 0;
    uVar2 = uVar1;
    FUN_0060e410(*(int *)(param_1 + 0x15c));
    FUN_00757710(uVar2);
    FUN_0060e550(*(undefined4 *)(param_1 + 0x15c));
    FUN_00757710();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

