
void FUN_005e1d10(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d8b6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (in_ECX < 7) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    local_38 = 0x14f;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = FUN_004ed610(uVar2);
    local_8 = 1;
    FUN_00402800(uVar3);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

