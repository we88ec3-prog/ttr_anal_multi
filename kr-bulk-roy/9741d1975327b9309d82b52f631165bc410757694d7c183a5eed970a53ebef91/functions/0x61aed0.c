
void FUN_0061aed0(undefined1 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 in_EDX;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092dd96;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_005300f0();
  if (iVar2 != 0) {
    uVar3 = FUN_00498f10(iVar2);
    local_8 = 1;
    FUN_00757800(uVar3);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(in_ECX + 0x24c) + 200))();
  }
  (**(code **)(**(int **)(in_ECX + 0x248) + 0x19c))(in_EDX,param_1,0xffffffff);
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

