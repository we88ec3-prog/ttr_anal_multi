
/* WARNING: Removing unreachable block (ram,0x004de076) */

undefined4 FUN_004de020(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249de;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_2 < 4) {
    uVar2 = 0;
  }
  else {
    uVar2 = (param_2 - 4) / 5;
  }
  if (*(int *)(in_ECX + 0x5ed8) != *(int *)(in_ECX + 0x5edc)) {
    *(int *)(in_ECX + 0x5edc) = *(int *)(in_ECX + 0x5ed8);
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    FUN_004de9c0(uVar1);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4261);
  ExceptionList = local_10;
  return 0;
}

