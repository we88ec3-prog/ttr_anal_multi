
void FUN_005653c0(undefined4 param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int in_ECX;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093632e;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0082ef00(&param_1);
  if ((local_14 != *(int *)(in_ECX + 0x1c)) && (*(int **)(local_14 + 0x10) != (int *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(**(int **)(local_14 + 0x10) + 0x4c))(uVar4);
    fVar1 = (float)puVar5[2];
    uVar2 = *puVar5;
    uVar3 = puVar5[1];
    if ((DAT_00fd93f0 & 1) == 0) {
      DAT_00fd93f0 = DAT_00fd93f0 | 1;
      local_8 = 0;
      FUN_007ab4e0();
      _atexit((_func_4879 *)&LAB_00bce6a0);
      local_8 = 0xffffffff;
    }
    FUN_007ac030(&DAT_00fd92a0,uVar2,uVar3,fVar1 + 7.0);
  }
  ExceptionList = local_10;
  return;
}

