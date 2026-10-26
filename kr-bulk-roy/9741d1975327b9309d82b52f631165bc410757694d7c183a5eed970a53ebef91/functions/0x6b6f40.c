
void FUN_006b6f40(int param_1)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  float local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942558;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar2 = *(int *)(DAT_00fab130 + 0x5f18);
  iVar7 = *(int *)(DAT_00fab130 + 0x5f20);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 1;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar4 = DAT_00fb7258;
  if (DAT_00fb7258 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 2;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    iVar5 = FUN_00539aa0(DAT_00f93930);
    cVar1 = *(char *)(iVar5 + 0xb);
    iVar5 = *(int *)(iVar4 + 0x28);
    iVar6 = *(int *)(iVar4 + 0x2c) - iVar5 >> 2;
    local_24 = (float)iVar7 / (float)iVar2;
    uVar8 = 0;
    if (iVar6 != 0) {
      if (iVar6 == 0) goto LAB_006b70ff;
      do {
        iVar7 = *(int *)(iVar5 + uVar8 * 4);
        if ((((*(char *)(iVar7 + 10) != '\0') && (iVar7 != 0)) && (*(char *)(iVar7 + 0xb) != cVar1))
           && (*(char *)(iVar7 + 0xb) != '\x03')) {
          FUN_0054b8e0();
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 3;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          iVar7 = FUN_004dfb60();
          if ((iVar7 != 0) && (*(int *)(iVar7 + 0x3c8) != 0)) {
            local_24 = local_24 -
                       (1.0 - (float)*(int *)(iVar7 + 0x3c8) / (float)*(int *)(iVar7 + 0x3bc)) /
                       (float)iVar2;
          }
        }
LAB_006b70ff:
        iVar5 = *(int *)(iVar4 + 0x28);
        uVar8 = uVar8 + 1;
      } while (uVar8 < (uint)(*(int *)(iVar4 + 0x2c) - iVar5 >> 2));
    }
    fVar9 = 0.0;
    if ((local_24 < 0.0) || (fVar9 = 1.0, 1.0 < local_24)) {
      local_24 = fVar9;
    }
    if (*(int *)(*(int *)(param_1 + 0x84) + 0xcc) != 0) {
      FUN_00757710();
    }
    pcVar3 = *(code **)(**(int **)(param_1 + 0x84) + 0x128);
    (*(int **)(param_1 + 0x84))[0x34] = (int)local_24;
    (*pcVar3)();
    (**(code **)(**(int **)(param_1 + 0x84) + 200))();
  }
  ExceptionList = local_14;
  return;
}

