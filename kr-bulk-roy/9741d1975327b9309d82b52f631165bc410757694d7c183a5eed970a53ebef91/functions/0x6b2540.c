
void FUN_006b2540(int param_1,undefined4 param_2)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint uStack_2c;
  uint uStack_24;
  uint uStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c0fa;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c = 1;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  local_c = 0xffffffff;
  iVar3 = FUN_0050d8b0(param_2);
  if (iVar3 != 0) {
    puVar6 = (undefined4 *)(param_1 + 0x124);
    iVar8 = 4;
    do {
      iVar7 = iVar8;
      (**(code **)(*(int *)*puVar6 + 0x90))(0);
      puVar6 = puVar6 + 1;
      iVar8 = iVar7 + -1;
    } while (iVar8 != 0);
    uVar5 = iVar7 + 3;
    uStack_20 = *(int *)(iVar3 + 0x48) - *(int *)(iVar3 + 0x44) >> 2;
    if (uStack_20 != 0) {
      uStack_2c = 0;
      do {
        puVar1 = *(ushort **)(*(int *)(iVar3 + 0x44) + uStack_2c * 4);
        uVar2 = *(uint *)(puVar1 + 2);
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 2;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        uStack_24 = (uint)*puVar1;
        piVar4 = (int *)FUN_0081ed70(&uStack_24);
        if ((*piVar4 != DAT_00f942f0) &&
           ((**(code **)(**(int **)(param_1 + 0x124 + uVar2 * 4) + 0x90))(1), uVar2 < uVar5)) {
          uVar5 = uVar2;
        }
        uStack_2c = uStack_2c + 1;
      } while (uStack_2c < uStack_20);
      if (uVar5 < 4) {
        (**(code **)(**(int **)(param_1 + 0x124 + uVar5 * 4) + 0xa0))(1);
      }
    }
    (**(code **)(**(int **)(param_1 + 0x11c) + 0x90))(uVar5 != 4);
    puVar6 = (undefined4 *)(param_1 + 0x124);
    iVar3 = 4;
    do {
      (**(code **)(*(int *)*puVar6 + 200))();
      puVar6 = puVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    (**(code **)(**(int **)(param_1 + 0x11c) + 200))();
  }
  ExceptionList = local_14;
  return;
}

