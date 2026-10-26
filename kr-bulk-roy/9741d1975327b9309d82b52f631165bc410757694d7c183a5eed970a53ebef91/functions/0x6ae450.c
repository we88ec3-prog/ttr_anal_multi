
void FUN_006ae450(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  puStack_c = &LAB_0092b49e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  param_1 = param_2;
  FUN_008438c0(&param_1);
  if (param_2 == DAT_00f8d91c) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_2 + 0x10);
  }
  iVar2 = *(int *)(*(int *)(iVar1 + 0xf4) + 0xcc);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00412c70(*(undefined4 *)(iVar2 + 0xe4));
  }
  (**(code **)(**(int **)(iVar2 + 0x248) + 0x1ac))
            (*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x1c),0,0,param_3);
  FUN_00757710();
  FUN_00749920(*(undefined4 *)(iVar1 + 0xf4));
  (**(code **)(**(int **)(iVar1 + 0xf4) + 200))();
  ExceptionList = local_10;
  return;
}

