
void FUN_00656c80(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  uint local_40;
  int iStack_3c;
  uint uStack_38;
  int iStack_34;
  uint uStack_28;
  undefined4 *puStack_24;
  undefined4 *puStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935cac;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar4 = DAT_00fab130;
  local_c = 0xffffffff;
  if (DAT_00fab130 != 0) {
    local_40 = (*(int *)(param_1 + 0x138) * -0xb4 + 800) / 2;
    uVar10 = *(int *)(DAT_00fab130 + 0x5ebc) - *(int *)(DAT_00fab130 + 0x5eb8) >> 3;
    uVar8 = 0;
    piVar11 = (int *)(param_1 + 0xd8);
    do {
      if (uVar8 < uVar10) {
        FUN_00749a00(local_40,*(undefined4 *)(*piVar11 + 0xc));
        (**(code **)(*(int *)*piVar11 + 0x94))(1);
      }
      else {
        (**(code **)(*(int *)*piVar11 + 0x94))(0);
      }
      local_40 = local_40 + 0xb4;
      uVar8 = uVar8 + 1;
      piVar11 = piVar11 + 1;
    } while (uVar8 < 4);
    uStack_38 = 0;
    if (uVar10 != 0) {
      iStack_1c = uVar10 * 5;
      iStack_34 = 0x3a;
      puVar9 = DAT_00f8d91c;
      do {
        if (uStack_38 < (uint)(*(int *)(iVar4 + 0x5ecc) - *(int *)(iVar4 + 0x5ec8) >> 2)) {
          local_40 = *(uint *)(*(int *)(iVar4 + 0x5ec8) + uStack_38 * 4);
        }
        else {
          local_40 = 0;
        }
        iStack_3c = local_40 * 5;
        uStack_28 = 0;
        do {
          if ((local_40 < (uint)((*(int *)(iVar4 + 0x5edc) - *(int *)(iVar4 + 0x5ed8)) / 5)) &&
             (piVar11 = (int *)(*(int *)(iVar4 + 0x5ed8) + iStack_3c), piVar11 != (int *)0x0)) {
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 1;
              FUN_0051c120();
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
              puVar9 = DAT_00f8d91c;
            }
            iVar2 = *piVar11;
            cVar1 = *(char *)((int)puVar9[1] + 0x15);
            puVar5 = (undefined4 *)puVar9[1];
            puStack_24 = puVar9;
            while (puVar7 = puVar5, cVar1 == '\0') {
              if ((int)puVar7[3] < iVar2) {
                puVar5 = (undefined4 *)puVar7[2];
                puVar7 = puStack_24;
              }
              else {
                puVar5 = (undefined4 *)*puVar7;
              }
              cVar1 = *(char *)((int)puVar5 + 0x15);
              puStack_24 = puVar7;
            }
            if ((puStack_24 == puVar9) || (iVar2 < (int)puStack_24[3])) {
              puStack_20 = puVar9;
              ppuVar6 = &puStack_20;
            }
            else {
              ppuVar6 = &puStack_24;
            }
            if ((*ppuVar6 != puVar9) && (iVar3 = (*ppuVar6)[4], iVar3 != 0)) {
              puVar9 = (undefined4 *)(param_1 + (iStack_34 + uStack_28) * 4);
              (**(code **)(*(int *)*puVar9 + 0x1ac))
                        (*(undefined4 *)(iVar3 + 0x20),iVar2,0,0,(char)piVar11[1]);
              (**(code **)(*(int *)*puVar9 + 200))();
              puVar9 = DAT_00f8d91c;
            }
          }
          local_40 = local_40 + uVar10;
          iStack_3c = iStack_3c + iStack_1c;
          uStack_28 = uStack_28 + 1;
        } while (uStack_28 < 5);
        iStack_34 = iStack_34 + 5;
        uStack_38 = uStack_38 + 1;
      } while (uStack_38 < uVar10);
    }
  }
  ExceptionList = local_14;
  return;
}

