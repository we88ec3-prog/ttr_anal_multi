
undefined4 FUN_005db200(int *param_1)

{
  int iVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1[1] != 0) {
    if ((*param_1 == 100) &&
       (iVar1 = (**(code **)(*(int *)param_1[1] + 8))(DAT_00d61f20 ^ (uint)&stack0xffffffd8),
       iVar1 == 0xf4245)) {
      iVar1 = *(int *)(param_1[1] + 0x260);
      if ((iVar1 != 5) && ((iVar1 != 0xd && (iVar1 != 0x1a)))) {
        ExceptionList = local_14;
        return 0;
      }
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        uStack_c = 0;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        uStack_c = 0xffffffff;
      }
      FUN_0050c490(*(undefined4 *)(in_ECX + 0x2a0));
      ExceptionList = local_14;
      return 1;
    }
    if (((param_1[1] != 0) && (*param_1 == 100)) &&
       (iVar1 = (**(code **)(*(int *)param_1[1] + 8))(), iVar1 == 0xf4248)) {
      ExceptionList = local_14;
      return 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}

