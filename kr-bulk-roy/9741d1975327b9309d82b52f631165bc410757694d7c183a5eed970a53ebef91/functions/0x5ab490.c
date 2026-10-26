
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ab490(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  undefined2 local_1a [3];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_1a[0] = 0x33;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,local_1a,2,uVar2);
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if ((1 < (uint)(*(int *)(DAT_00fab130 + 0x5ebc) - *(int *)(DAT_00fab130 + 0x5eb8) >> 3)) &&
     (iVar3 = *(int *)(DAT_00fab130 + 0x5edc) - *(int *)(DAT_00fab130 + 0x5ed8),
     iVar1 = iVar3 >> 0x1f, iVar3 / 5 + iVar1 != iVar1)) {
    FUN_00656c30();
    (**(code **)(**(int **)(in_ECX + 0x164) + 0xd0))();
  }
  ExceptionList = local_14;
  return;
}

