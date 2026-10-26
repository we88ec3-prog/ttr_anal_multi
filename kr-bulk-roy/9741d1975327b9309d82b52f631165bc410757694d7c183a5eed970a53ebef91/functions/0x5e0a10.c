
void FUN_005e0a10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  void *pvVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  FUN_005d7240(param_1,param_2,param_3,param_4);
  if ((*(uint *)(in_ECX + 0x28) & 8) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 8;
  }
  FUN_005e0cc0(param_3,param_4);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (((*(uint *)(in_ECX + 0x298) < 10) &&
      (iVar2 = DAT_00f94304 + *(uint *)(in_ECX + 0x298) * 0x210, *(int *)(iVar2 + 0x5c) != 0)) &&
     (iVar2 != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x2a4) + 0xa0))
              ((*(uint *)(iVar2 + 0xf8) & 1 << ((byte)*(undefined4 *)(in_ECX + 0x29c) & 0x1f)) == 0)
    ;
    (**(code **)(**(int **)(in_ECX + 0x2a4) + 200))();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x2a4) + 0xa0))(0);
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x2a4) + 0x28) >> 9 & 1) == 0) {
    pvVar3 = (void *)0x3f000000;
  }
  else {
    pvVar3 = (void *)0x3f800000;
  }
  (**(code **)(**(int **)(in_ECX + 0x264) + 0xd8))(pvVar3);
  *(undefined1 *)(in_ECX + 0x2a8) = 0;
  (**(code **)(**(int **)(in_ECX + 0x2a4) + 0x90))(1);
  ExceptionList = pvVar3;
  return;
}

