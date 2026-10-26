
void FUN_0066b120(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a93e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(*param_1 + 0xd0))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  FUN_004f6a30(param_2);
  iVar1 = param_1[0x3f];
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  (**(code **)(*(int *)param_1[0x3f] + 200))();
  ExceptionList = local_10;
  return;
}

