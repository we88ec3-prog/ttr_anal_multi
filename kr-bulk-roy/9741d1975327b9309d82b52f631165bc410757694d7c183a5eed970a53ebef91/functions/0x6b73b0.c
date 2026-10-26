
void FUN_006b73b0(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  float local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009424fa;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar1 = *(int *)(DAT_00fab130 + 0x5f18);
  iVar5 = *(int *)(DAT_00fab130 + 0x5f20);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 1;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar3 = DAT_00fb7258;
  local_c = 0xffffffff;
  if (DAT_00fb7258 != 0) {
    uVar6 = 0;
    iVar4 = *(int *)(DAT_00fb7258 + 0x2c) - *(int *)(DAT_00fb7258 + 0x28) >> 2;
    local_24 = (float)iVar5 / (float)iVar1;
    if (iVar4 != 0) {
      if (iVar4 == 0) goto LAB_006b751f;
      do {
        iVar5 = *(int *)(*(int *)(iVar3 + 0x28) + uVar6 * 4);
        if (((*(char *)(iVar5 + 10) != '\0') && (iVar5 != 0)) && (*(char *)(iVar5 + 0xb) == '\x02'))
        {
          FUN_0054b8e0();
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 2;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          iVar5 = FUN_004dfb60();
          if ((iVar5 != 0) && (*(int *)(iVar5 + 0x3c8) != 0)) {
            local_24 = local_24 -
                       (1.0 - (float)*(int *)(iVar5 + 0x3c8) / (float)*(int *)(iVar5 + 0x3bc)) /
                       (float)iVar1;
          }
        }
LAB_006b751f:
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)(*(int *)(iVar3 + 0x2c) - *(int *)(iVar3 + 0x28) >> 2));
    }
    fVar7 = 0.0;
    if ((local_24 < 0.0) || (fVar7 = 1.0, 1.0 < local_24)) {
      local_24 = fVar7;
    }
    if (*(int *)(*(int *)(param_1 + 0x84) + 0xcc) != 0) {
      FUN_00757710();
    }
    pcVar2 = *(code **)(**(int **)(param_1 + 0x84) + 0x128);
    (*(int **)(param_1 + 0x84))[0x34] = (int)local_24;
    (*pcVar2)();
    (**(code **)(**(int **)(param_1 + 0x84) + 200))();
  }
  ExceptionList = local_14;
  return;
}

