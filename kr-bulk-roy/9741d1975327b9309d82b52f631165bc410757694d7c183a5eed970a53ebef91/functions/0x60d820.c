
/* WARNING: Removing unreachable block (ram,0x0060d92a) */

void FUN_0060d820(undefined4 param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e576;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0060f9d0(uVar2);
  uVar1 = DAT_00fc1094 & 1;
  *(undefined4 *)(in_ECX + 0x15c) = param_1;
  *(undefined1 *)(in_ECX + 0x160) = param_2;
  if (uVar1 == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0();
    _atexit((_func_4879 *)&LAB_00bcdc80);
    local_8 = 0xffffffff;
  }
  FUN_0060f120(in_ECX);
  FUN_0060d960();
  FUN_0060dac0();
  FUN_0060db90();
  FUN_0060dc30(in_ECX);
  FUN_0060de10();
  local_8 = 1;
  FUN_00530260();
  FUN_0060dfd0();
  FUN_00757710();
  FUN_0060e690(*(undefined4 *)(in_ECX + 0x15c),param_2);
  FUN_0060e920(in_ECX,*(undefined4 *)(in_ECX + 0x15c));
  FUN_0060dcf0(param_2);
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

