
undefined4 FUN_005243a0(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009478d8;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  uVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
  local_1c = 0;
  if (uVar5 != 0) {
    do {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 4) + local_1c * 8);
      switch(*puVar1) {
      case 0:
        if ((DAT_00fab29c & 1) == 0) {
          DAT_00fab29c = DAT_00fab29c | 1;
          local_c = 0;
          FUN_004ffe60();
          _atexit((_func_4879 *)&LAB_00bccf00);
          local_c = 0xffffffff;
        }
        uVar3 = 0;
        uVar6 = DAT_00fb1154 - DAT_00fb1150 >> 1;
        if (uVar6 == 0) {
          ExceptionList = local_14;
          return 0;
        }
        while (*(short *)(DAT_00fb1150 + uVar3 * 2) != *(short *)(puVar1 + 1)) {
          uVar3 = uVar3 + 1;
          if (uVar6 <= uVar3) {
            ExceptionList = local_14;
            return 0;
          }
        }
        break;
      case 1:
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 1;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
        if (iVar4 == 0) {
          ExceptionList = local_14;
          return 0;
        }
        if (*(short *)(iVar4 + 0x88) != *(short *)(puVar1 + 1)) {
          ExceptionList = local_14;
          return 0;
        }
        break;
      case 2:
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 2;
          FUN_004e1590(uVar2);
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        iVar4 = FUN_004d43d0();
        goto LAB_00524549;
      case 3:
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 3;
          FUN_004e1590(uVar2);
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        iVar4 = *(int *)(DAT_00f94300 + 0x50b8) / 0x14;
LAB_00524549:
        if ((iVar4 < (int)(uint)*(ushort *)(puVar1 + 1)) ||
           ((int)(uint)*(ushort *)((int)puVar1 + 6) < iVar4)) {
          ExceptionList = local_14;
          return 0;
        }
      }
      local_1c = local_1c + 1;
    } while (local_1c < uVar5);
  }
  ExceptionList = local_14;
  return 1;
}

