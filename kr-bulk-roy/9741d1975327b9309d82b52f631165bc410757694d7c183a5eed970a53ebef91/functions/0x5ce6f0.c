
void FUN_005ce6f0(int param_1)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d6fc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(uint *)(DAT_00fb1318 + 0xbf74);
  if (uVar1 < 0x1a) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
  }
  else {
    if (0x28 < uVar1) {
      if (uVar1 < 0x3d) {
        FUN_00403470(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      }
      else {
        FUN_00403470(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      }
      FUN_00745100();
      goto LAB_005ce7fe;
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
  }
  local_8 = 0xffffffff;
  iVar2 = *(int *)(param_1 + 0x334);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
LAB_005ce7fe:
  (**(code **)(**(int **)(param_1 + 0x334) + 200))();
  ExceptionList = local_10;
  return;
}

