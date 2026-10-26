
void FUN_00696f50(int param_1)

{
  ushort uVar1;
  short sVar2;
  undefined1 uVar3;
  ushort *puVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  uint uVar10;
  short *psVar11;
  int *piVar12;
  char cVar13;
  ushort *puVar14;
  bool bVar15;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094787e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar8 = DAT_00fb7258;
  local_8 = 0xffffffff;
  if (DAT_00fb7258 == 0) {
    if (((uint)(*(int **)(param_1 + 0xec))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(param_1 + 0xec) + 0x94))(0);
    }
    ExceptionList = local_10;
    return;
  }
  if (((uint)(*(int **)(param_1 + 0xec))[10] >> 8 & 1) == 0) {
    (**(code **)(**(int **)(param_1 + 0xec) + 0x94))(1);
  }
  if (*(uint *)(iVar8 + 0x18) < 8) {
    puVar9 = (ushort *)(iVar8 + 4);
  }
  else {
    puVar9 = *(ushort **)(iVar8 + 4);
  }
  puVar14 = (ushort *)(param_1 + 0xf4);
  puVar4 = puVar14;
  if (7 < *(uint *)(param_1 + 0x108)) {
    puVar4 = *(ushort **)puVar14;
  }
  do {
    uVar1 = *puVar4;
    bVar15 = uVar1 < *puVar9;
    if (uVar1 != *puVar9) {
LAB_0069701e:
      iVar5 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
      goto LAB_00697023;
    }
    if (uVar1 == 0) break;
    uVar1 = puVar4[1];
    bVar15 = uVar1 < puVar9[1];
    if (uVar1 != puVar9[1]) goto LAB_0069701e;
    puVar9 = puVar9 + 2;
    puVar4 = puVar4 + 2;
  } while (uVar1 != 0);
  iVar5 = 0;
LAB_00697023:
  if (iVar5 != 0) {
    if (*(uint *)(iVar8 + 0x18) < 8) {
      psVar11 = (short *)(iVar8 + 4);
    }
    else {
      psVar11 = *(short **)(iVar8 + 4);
    }
    psVar6 = psVar11;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar11,(int)psVar6 - (int)(psVar11 + 1) >> 1);
    FUN_00757800(puVar14);
    (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  }
  uVar10 = 0;
  uVar7 = *(int *)(iVar8 + 0x2c) - *(int *)(iVar8 + 0x28) >> 2;
  if (uVar7 != 0) {
    piVar12 = *(int **)(iVar8 + 0x28);
    do {
      if ((*(char *)(*piVar12 + 10) != '\0') && (*(char *)(*piVar12 + 6) != '\0')) {
        piVar12 = (int *)(*(int **)(iVar8 + 0x28))[uVar10];
        if ((piVar12 != (int *)0x0) &&
           (iVar8 = FUN_00404ba0(), *piVar12 == *(int *)(iVar8 + 0x5f50))) {
          cVar13 = '\x01';
          goto LAB_006970b8;
        }
        break;
      }
      uVar10 = uVar10 + 1;
      piVar12 = piVar12 + 1;
    } while (uVar10 < uVar7);
  }
  cVar13 = '\0';
LAB_006970b8:
  if (*(char *)(param_1 + 0x110) != cVar13) {
    (**(code **)(**(int **)(param_1 + 0xf0) + 0x90))(cVar13);
    *(char *)(param_1 + 0x110) = cVar13;
  }
  uVar3 = FUN_00697150();
  FUN_00696e50(uVar3);
  ExceptionList = local_10;
  return;
}

