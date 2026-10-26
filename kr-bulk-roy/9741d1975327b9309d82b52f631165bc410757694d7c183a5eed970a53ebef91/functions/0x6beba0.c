
void FUN_006beba0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cedc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x174) == -1) {
    iVar5 = *(int *)(param_1 + 0x160);
    if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
       (iVar4 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar4 == 0xbf6b)) {
      iVar5 = *(int *)(iVar5 + 0x94);
      iVar4 = *(int *)(iVar5 + 0x10);
      if (iVar4 != 0) {
        piVar2 = *(int **)(iVar4 + 8);
        if (piVar2 != (int *)0x0) {
          piVar1 = piVar2 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 0x28))();
          }
        }
        *(undefined4 *)(iVar5 + 0x10) = 0;
        ExceptionList = local_10;
        return;
      }
    }
  }
  else {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    local_8 = 0xffffffff;
    uVar3 = *(undefined4 *)(param_1 + 0x174);
    iVar5 = FUN_005c7190();
    if ((((iVar5 == 0) ||
         (local_14 = uVar3, FUN_0082ef00(&local_14), local_18 == *(int *)(iVar5 + 0xc))) ||
        (*(int *)(local_18 + 0x10) == 0)) && ((DAT_00f94394 & 1) == 0)) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    FUN_00745060();
  }
  ExceptionList = local_10;
  return;
}

