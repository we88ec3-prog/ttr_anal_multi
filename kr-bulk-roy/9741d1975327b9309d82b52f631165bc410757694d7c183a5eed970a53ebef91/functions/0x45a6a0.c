
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045a6a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b4d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0045a5f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fc0c7c & 1) == 0) {
    DAT_00fc0c7c = DAT_00fc0c7c | 1;
    local_8 = 0;
    FUN_00823e10();
    local_8 = CONCAT31(local_8._1_3_,1);
    _DAT_00fc0c80 = CCubeSystemMgr::vftable;
    FUN_0044be70();
    _atexit((_func_4879 *)&LAB_00bcd780);
    local_8 = 0xffffffff;
  }
  param_1 = param_2;
  FUN_008438c0(&param_1);
  if (param_2 == DAT_00fc0c88) {
    param_1 = 0;
  }
  else {
    param_1 = *(int *)(param_2 + 0x10);
  }
  iVar3 = 0;
  if (0 < param_1) {
    do {
      iVar1 = *(int *)(*(int *)(iVar2 + 0xf0) + iVar3 * 4);
      *(undefined1 *)(iVar1 + 0x2a4) = 0;
      (**(code **)(**(int **)(iVar1 + 0x2a0) + 0x94))(0);
      (**(code **)(**(int **)(iVar1 + 0x2a0) + 200))();
      (**(code **)(**(int **)(*(int *)(iVar2 + 0xf0) + iVar3 * 4) + 200))();
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1);
  }
  ExceptionList = local_10;
  return;
}

