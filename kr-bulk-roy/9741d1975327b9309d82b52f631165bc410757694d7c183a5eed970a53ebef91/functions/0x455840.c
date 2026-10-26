
void FUN_00455840(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint *puVar11;
  int unaff_EDI;
  uint uStack_28;
  uint local_24;
  int *piStack_20;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  local_24 = 1;
  do {
    uVar3 = local_24;
    iVar6 = *(int *)(unaff_EDI + 0x168);
    piVar5 = (int *)FUN_004364c0(&local_24);
    (**(code **)(**(int **)(unaff_EDI + 0x120 + uVar3 * 4) + 0x90))(*piVar5 != iVar6,uVar4);
    local_24 = uVar3 + 1;
  } while ((int)local_24 < 10);
  (**(code **)(**(int **)(unaff_EDI + 0x118) + 200))();
  uVar4 = *(int *)(unaff_EDI + 0x158) - *(int *)(unaff_EDI + 0x154) >> 2;
  piStack_20 = (int *)(-0x148 - unaff_EDI);
  local_24 = 0;
  puVar10 = (undefined4 *)(unaff_EDI + 0x148);
  do {
    (**(code **)(*(int *)*puVar10 + 0x90))(local_24 < uVar4);
    if (uStack_28 < uVar4) {
      (**(code **)(*(int *)*puVar10 + 0x198))
                (*(undefined4 *)((int)puVar10 + *(int *)(unaff_EDI + 0x154) + local_24));
    }
    else {
      (**(code **)(*(int *)*puVar10 + 0x19c))();
    }
    local_24 = local_24 + 1;
    puVar10 = puVar10 + 1;
  } while (local_24 < 3);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  iVar6 = FUN_004d43d0();
  piVar5 = *(int **)(unaff_EDI + 0x11c);
  puVar10 = (undefined4 *)piVar5[0x19];
  piStack_20 = piVar5;
  for (puVar1 = (undefined4 *)*puVar10; puVar1 != puVar10; puVar1 = (undefined4 *)*puVar1) {
    iVar2 = puVar1[2];
    if ((*(int *)(iVar2 + 0x60) != 0) && ((*(int **)(iVar2 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0x30))(iVar2);
      piVar5 = piStack_20;
    }
  }
  (**(code **)(*piVar5 + 0x128))();
  (**(code **)(**(int **)(unaff_EDI + 0x11c) + 200))();
  if (((uint)(*(int *)(unaff_EDI + 0x158) - *(int *)(unaff_EDI + 0x154) >> 2) < 3) || (iVar6 < 0x1e)
     ) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0x90))(uVar7);
  iVar6 = (*(int *)(DAT_00fc0c6c + 0xc) - *(int *)(DAT_00fc0c6c + 8)) / 0x34;
  puVar8 = (uint *)0x0;
  if (iVar6 != 0) {
    puVar11 = *(uint **)(DAT_00fc0c6c + 8);
    do {
      if (*puVar11 == (uint)*(ushort *)(unaff_EDI + 0x178)) {
        puVar8 = puVar11;
      }
      puVar11 = puVar11 + 0xd;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (puVar8 != (uint *)0x0) {
      iVar6 = (int)(puVar8[10] - puVar8[9]) / 0x24;
      piVar5 = (int *)0x0;
      if (iVar6 != 0) {
        piVar9 = (int *)puVar8[9];
        do {
          if (*piVar9 == 1) {
            piVar5 = piVar9;
          }
          piVar9 = piVar9 + 9;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        if (piVar5 != (int *)0x0) {
          FUN_00757800(piVar5 + 2);
          (**(code **)(**(int **)(unaff_EDI + 0x108) + 200))();
        }
      }
    }
  }
  ExceptionList = pvStack_18;
  return;
}

