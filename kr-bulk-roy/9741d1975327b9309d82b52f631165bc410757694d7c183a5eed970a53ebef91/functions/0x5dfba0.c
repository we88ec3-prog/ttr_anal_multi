
void FUN_005dfba0(int param_1)

{
  int *piVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d94f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  local_8 = 0xffffffff;
  local_14 = *(uint *)(param_1 + 0x250);
  FUN_008438c0(&local_14);
  if ((local_18 != DAT_00f8d9b0) && (*(int *)(local_18 + 0x10) != 0)) {
    if ((DAT_00fb744c & 1) == 0) {
      DAT_00fb744c = DAT_00fb744c | 1;
      local_8 = 2;
      FUN_004eec60();
      _atexit(FUN_00bcd140);
      local_8 = 0xffffffff;
    }
    puVar2 = (ushort *)FUN_004eeb00();
    if (puVar2 != (ushort *)0x0) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_8 = 3;
        FUN_005c3de0();
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_8 = 0xffffffff;
      }
      local_14 = (uint)*puVar2;
      FUN_008fed10();
      iVar3 = *(int *)(param_1 + 0x2a0);
      if ((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) {
        iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))();
        if (iVar3 == 0xbf6b) {
          FUN_0077b200();
        }
      }
      piVar5 = *(int **)(param_1 + 0x2a0);
      goto LAB_005dfd7f;
    }
  }
  iVar3 = *(int *)(param_1 + 0x2a0);
  if ((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) {
    iVar4 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))();
    if (iVar4 == 0xbf6b) {
      iVar3 = *(int *)(iVar3 + 0x94);
      iVar4 = *(int *)(iVar3 + 0x10);
      if (iVar4 != 0) {
        piVar5 = *(int **)(iVar4 + 8);
        if (piVar5 != (int *)0x0) {
          piVar1 = piVar5 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar5 + 0x28))();
          }
        }
        *(undefined4 *)(iVar3 + 0x10) = 0;
      }
    }
  }
  piVar5 = *(int **)(param_1 + 0x2a0);
LAB_005dfd7f:
  (**(code **)(*piVar5 + 200))();
  ExceptionList = local_10;
  return;
}

