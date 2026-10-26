
void FUN_00654070(int param_1,undefined4 param_2)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009164bc;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((char)param_2 == '\0') {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    param_2 = 0x15a;
    FUN_005740f0(&param_2);
    if (param_1 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = 0xffffffff;
    param_2 = 0x159;
    FUN_005740f0(&param_2);
    if (param_1 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  FUN_00757710(uVar3);
  (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
  if (((*(char *)(*(int *)(param_1 + 0x108) + 0xa4) != '\0') &&
      (piVar1 = *(int **)(*(int *)(param_1 + 0x108) + 0x94), piVar1 != (int *)0x0)) &&
     (iVar4 = (**(code **)(*piVar1 + 4))(), iVar4 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  ExceptionList = local_10;
  return;
}

