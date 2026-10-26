
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00607310(undefined1 param_1)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  undefined2 local_1f;
  undefined4 local_1d;
  undefined1 local_19;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x10c) != 0) {
    FUN_0068a1b0(*(int *)(in_ECX + 0x10c),*(undefined4 *)(in_ECX + 0x118));
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_1d = *(undefined4 *)(in_ECX + 0x120);
  local_1f = 0x89;
  local_19 = param_1;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1f,7,uVar1);
  }
  if (*(int *)(in_ECX + 0x11c) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0x11c) + 0xf4;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    *(int *)(DAT_00f94300 + 0x50f0) = iVar2;
    ExceptionList = local_14;
    return;
  }
  *(int *)(DAT_00f94300 + 0x50f0) = iVar2;
  ExceptionList = local_14;
  return;
}

