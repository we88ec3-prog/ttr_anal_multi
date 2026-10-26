
void FUN_005daf60(int param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d99f;
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
    if (0 < *(int *)(param_1 + 0x2b4)) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_8 = 2;
        FUN_005c3de0();
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_8 = 0xffffffff;
      }
      iVar3 = *(int *)(param_1 + 0x2b4);
      iVar1 = FUN_008fed10();
      iVar1 = *(int *)(&DAT_00f944b0 + iVar1 * -4);
      *(int *)(param_1 + 0x2b4) = iVar3 + -1;
      goto LAB_005db12d;
    }
    if ((DAT_00fb744c & 1) == 0) {
      DAT_00fb744c = DAT_00fb744c | 1;
      local_8 = 3;
      FUN_004eec60();
      _atexit(FUN_00bcd140);
      local_8 = 0xffffffff;
    }
    puVar2 = (ushort *)FUN_004eeb00();
    if (puVar2 != (ushort *)0x0) {
      local_14 = (uint)*puVar2;
      iVar3 = FUN_00403470();
      iVar1 = FUN_008fed10();
      iVar1 = *(int *)(iVar3 + (0x2c - iVar1) * 4);
      if (puVar2[1] - 1 == (uint)*puVar2) {
        *(undefined4 *)(param_1 + 0x2b4) = 0x3c;
      }
      goto LAB_005db12d;
    }
  }
  iVar1 = 0;
LAB_005db12d:
  if (iVar1 != *(int *)(param_1 + 0x2a8)) {
    iVar3 = *(int *)(param_1 + 0x2ac);
    if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
       (iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
      FUN_0077b200();
    }
    (**(code **)(**(int **)(param_1 + 0x2ac) + 200))();
    *(int *)(param_1 + 0x2a8) = iVar1;
  }
  ExceptionList = local_10;
  return;
}

