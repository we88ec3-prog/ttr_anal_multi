
void FUN_005b9fa0(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  int *piVar8;
  short *psVar9;
  undefined2 local_74 [8];
  undefined4 local_64;
  undefined2 *local_60;
  undefined4 *puStack_5c;
  undefined2 local_58 [8];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00947332;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20();
    uStack_3c = 0x5b9ff5;
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  if (DAT_00fb7258 != 0) {
    uVar7 = 0;
    uVar3 = *(int *)(DAT_00fb7258 + 0x2c) - *(int *)(DAT_00fb7258 + 0x28) >> 2;
    if (uVar3 != 0) {
      piVar8 = *(int **)(DAT_00fb7258 + 0x28);
      do {
        if ((*(char *)(*piVar8 + 10) != '\0') && (*(char *)(*piVar8 + 6) != '\0')) {
          piVar8 = (int *)(*(int **)(DAT_00fb7258 + 0x28))[uVar7];
          goto LAB_005ba03e;
        }
        uVar7 = uVar7 + 1;
        piVar8 = piVar8 + 1;
      } while (uVar7 < uVar3);
    }
    piVar8 = (int *)0x0;
LAB_005ba03e:
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      uStack_3c = 0x5ba065;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    if (*piVar8 != DAT_00f93930) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 2;
        FUN_00587480();
        uStack_3c = 0x5ba0a5;
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_c = 0xffffffff;
      uStack_3c = 0;
      local_1c = (undefined1 *)local_58;
      puStack_5c = (undefined4 *)0x0;
      local_44 = 7;
      local_48 = 0;
      local_60 = &DAT_00bed1fc;
      local_58[0] = 0;
      local_64 = 0x5ba0d8;
      FUN_00402160();
      local_c = 3;
      local_24 = 0x35;
      puStack_5c = (undefined4 *)0x5ba0ed;
      iVar4 = FUN_005854b0();
      puStack_5c = &local_24;
      local_60 = (undefined2 *)0x5ba0ff;
      FUN_005740f0();
      if (local_20 == (undefined1 *)*(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar9 = (short *)((int)local_20 + 0x10);
      if (7 < *(uint *)((int)local_20 + 0x24)) {
        psVar9 = *(short **)psVar9;
      }
      local_20 = (undefined1 *)local_74;
      local_60 = (undefined2 *)0x7;
      local_64 = 0;
      local_74[0] = 0;
      psVar5 = psVar9;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar9,(int)psVar5 - (int)(psVar9 + 1) >> 1);
      local_c = 0xffffffff;
      FUN_0058b270(0xca);
      ExceptionList = local_14;
      return;
    }
  }
  local_c = 0xffffffff;
  piVar8 = *(int **)(in_ECX + 0x230);
  if (((uint)piVar8[10] >> 8 & 1) != 0) {
    if (((uint)piVar8[10] >> 8 & 1) != 0) {
      (**(code **)(*piVar8 + 0xd4))();
    }
    uStack_3c = 0x5ba1ae;
    FUN_005a55e0();
    ExceptionList = local_14;
    return;
  }
  uStack_40 = 0x5ba1c8;
  FUN_00596e00();
  uStack_3c = 0x5ba1d3;
  FUN_005a55e0();
  if (*(int *)(in_ECX + 0x158) == 1) {
    iVar4 = *(int *)(in_ECX + 0x140);
  }
  else {
    if (*(int *)(in_ECX + 0x158) != 2) goto LAB_005ba20e;
    iVar4 = *(int *)(in_ECX + 0x148);
  }
  iVar6 = 0x19 - *(int *)(iVar4 + 8);
  *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + iVar6;
  *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + iVar6;
  iVar6 = 0x37 - *(int *)(iVar4 + 0xc);
  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar6;
  *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar6;
  FUN_00746f70();
LAB_005ba20e:
  if (*(int *)(in_ECX + 0x158) == 1) {
    piVar8 = *(int **)(in_ECX + 0x140);
  }
  else {
    if (*(int *)(in_ECX + 0x158) != 2) {
      ExceptionList = local_14;
      return;
    }
    piVar8 = *(int **)(in_ECX + 0x148);
  }
  uStack_3c = 0x5ba237;
  (**(code **)(*piVar8 + 0xb4))();
  ExceptionList = local_14;
  return;
}

