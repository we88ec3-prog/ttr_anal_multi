
void FUN_004547a0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f63e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  sVar3 = (short)param_2;
  if ((short)param_2 == -1) {
    iVar5 = *(int *)(param_1 + 0x24c);
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
    iVar5 = FUN_005c7190();
    if (iVar5 != 0) {
      param_2 = (int)sVar3;
      FUN_0082ef00(&param_2);
    }
    FUN_00745060();
  }
  ExceptionList = local_10;
  return;
}

