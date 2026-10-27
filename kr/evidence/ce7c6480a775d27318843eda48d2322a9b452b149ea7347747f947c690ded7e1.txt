
undefined4 FUN_004d2e40(int param_1)

{
  ushort *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  void **ppvVar5;
  uint uVar6;
  uint uVar7;
  int local_2c;
  int *local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936d4e;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  local_2c = 3;
  ppvVar5 = &local_14;
  local_14 = ExceptionList;
  for (local_24 = (uint)*(byte *)(param_1 + 2); ExceptionList = ppvVar5, local_24 != 0;
      local_24 = local_24 - 1) {
    puVar1 = (ushort *)(local_2c + param_1);
    local_2c = local_2c + 3;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(uVar6);
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    local_28 = (int *)(uint)*puVar1;
    FUN_0082ef00(&local_28);
    if ((local_20 == DAT_00fab13c) || (iVar3 = *(int *)(local_20 + 0x10), iVar3 == 0)) {
      FUN_006edb60(&DAT_00c0cb30);
      if ((byte)puVar1[1] != 0) {
        local_2c = local_2c + (uint)(byte)puVar1[1] * 4;
      }
    }
    else {
      piVar4 = *(int **)(*(int *)(iVar3 + 0x3f4) + 4);
      cVar2 = *(char *)((int)piVar4 + 0x15);
      uVar7 = (uint)(byte)puVar1[1];
      while (local_28 = piVar4, local_1c = uVar7, cVar2 == '\0') {
        FUN_0073eba0(piVar4[2]);
        piVar4 = (int *)*piVar4;
        FUN_0089120c(local_28);
        uVar7 = local_1c;
        cVar2 = *(char *)((int)piVar4 + 0x15);
      }
      *(int *)(*(int *)(iVar3 + 0x3f4) + 4) = *(int *)(iVar3 + 0x3f4);
      *(undefined4 *)*(undefined4 *)(iVar3 + 0x3f4) = *(undefined4 *)(iVar3 + 0x3f4);
      *(int *)(*(int *)(iVar3 + 0x3f4) + 8) = *(int *)(iVar3 + 0x3f4);
      *(undefined4 *)(iVar3 + 0x3f8) = 0;
      *(undefined4 *)(iVar3 + 0x400) = 0;
      *(undefined4 *)(iVar3 + 0x404) = 0;
      *(undefined4 *)(iVar3 + 0x408) = 0;
      if (0 < (int)uVar7) {
        do {
          iVar3 = local_2c + param_1;
          local_2c = local_2c + 4;
          FUN_004c9840(*(undefined1 *)(iVar3 + 2),*(undefined1 *)(iVar3 + 3));
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
    }
    ppvVar5 = ExceptionList;
  }
  ExceptionList = local_14;
  return 0;
}

