
void FUN_0041c620(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927d8a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  iVar3 = DAT_00fb7280;
  if (DAT_00fb7284 - DAT_00fb7280 >> 2 != 0) {
    do {
      piVar5 = *(int **)(iVar3 + local_14 * 4);
      if (((char)piVar5[2] != '\0') && (*piVar5 == param_2)) {
        local_1c = -0x164 - param_1;
        piVar5 = (int *)(param_1 + 0x164);
        local_18 = 3;
        do {
          if (*(int *)((int)piVar5 + *(int *)(*(int *)(iVar3 + local_14 * 4) + 0x2c) + local_1c) ==
              0) {
            if ((DAT_00f94394 & 1) == 0) {
              DAT_00f94394 = DAT_00f94394 | 1;
              local_8 = 2;
              FUN_005c3de0();
              _atexit((_func_4879 *)&LAB_00bccc30);
              local_8 = 0xffffffff;
            }
            local_20 = 0;
            FUN_0082ef00(&local_20);
          }
          else {
            iVar3 = *(int *)(*(int *)(iVar3 + local_14 * 4) + 0x2c) + local_1c;
            if ((DAT_00f94394 & 1) == 0) {
              DAT_00f94394 = DAT_00f94394 | 1;
              local_8 = 1;
              FUN_005c3de0();
              _atexit((_func_4879 *)&LAB_00bccc30);
              local_8 = 0xffffffff;
            }
            local_20 = *(undefined4 *)((int)piVar5 + iVar3);
            FUN_0082ef00(&local_20);
          }
          iVar3 = *piVar5;
          if (((*(char *)(iVar3 + 0xa4) != '\0') && (*(int *)(iVar3 + 0x94) != 0)) &&
             (iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
            FUN_0077b200();
          }
          (**(code **)(*(int *)*piVar5 + 200))();
          piVar5 = piVar5 + 1;
          local_18 = local_18 + -1;
          iVar3 = DAT_00fb7280;
        } while (local_18 != 0);
        local_18 = 0;
      }
      local_14 = local_14 + 1;
    } while (local_14 < (uint)(DAT_00fb7284 - iVar3 >> 2));
  }
  FUN_00749c50();
  iVar3 = *(int *)(param_1 + 0x160);
  iVar4 = ((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8)) / 2 -
          (*(int *)(iVar3 + 0x10) - *(int *)(iVar3 + 8)) / 2) - *(int *)(iVar3 + 8);
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar4;
  *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar4;
  iVar4 = *(int *)(iVar3 + 0xc);
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + -iVar4;
  *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + -iVar4;
  *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 8);
  *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar3 + 0x10);
  *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 0x14);
  if (*(int *)(iVar3 + 0x60) != 0) {
    iVar4 = *(int *)(*(int *)(iVar3 + 0x60) + 0x2c);
    *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + iVar4;
    *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x34) + iVar4;
    iVar4 = *(int *)(*(int *)(iVar3 + 0x60) + 0x30);
    *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + iVar4;
    *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0x38) + iVar4;
  }
  puVar1 = *(undefined4 **)(iVar3 + 100);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    FUN_00746f70();
  }
  (**(code **)(**(int **)(param_1 + 0x160) + 200))();
  ExceptionList = local_10;
  return;
}

