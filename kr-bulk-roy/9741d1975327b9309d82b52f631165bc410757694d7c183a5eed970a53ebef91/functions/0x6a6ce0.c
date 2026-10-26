
void FUN_006a6ce0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  void *pvVar4;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c474;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar2 = DAT_00f93930;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 1;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  if (iVar2 == DAT_00fc0be0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 2;
      FUN_004e1590(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    (**(code **)(**(int **)(param_1 + 0xf0) + 0x90))(param_2 != DAT_00f93930);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      puStack_10 = (undefined1 *)0x3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    (**(code **)(**(int **)(param_1 + 0xfc) + 0x90))(param_2 != DAT_00f93930);
    ExceptionList = local_1c;
    return;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 4;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (param_2 != DAT_00f93930) {
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_c = 5;
      FUN_004e8010();
      _atexit((_func_4879 *)&LAB_00bcd6b0);
    }
    local_c = 0xffffffff;
    if (param_2 != DAT_00fc0be0) {
      iVar2 = FUN_0044fd50();
      if (((*(int *)(iVar2 + 0x5ec0) == 0) || (iVar2 = *(int *)(iVar2 + 0x5ebc), iVar2 == 0)) ||
         ((local_1c = (void *)CONCAT31(local_1c._1_3_,1), *(char *)(iVar2 + 0x12) == '\0' &&
          ((*(byte *)(iVar2 + 0x14) & 2) == 0)))) {
        local_1c = (void *)((uint)local_1c & 0xffffff00);
      }
      pcVar3 = *(code **)(**(int **)(param_1 + 0xfc) + 0x90);
      pvVar4 = local_1c;
      goto LAB_006a6eed;
    }
  }
  local_c = 0xffffffff;
  pcVar3 = *(code **)(**(int **)(param_1 + 0xfc) + 0x90);
  pvVar4 = (void *)0x0;
LAB_006a6eed:
  (*pcVar3)(pvVar4);
  (**(code **)(**(int **)(param_1 + 0xf0) + 0x90))(0);
  ExceptionList = local_1c;
  return;
}

