
/* WARNING: Removing unreachable block (ram,0x0066d4f7) */
/* WARNING: Removing unreachable block (ram,0x0066d508) */
/* WARNING: Removing unreachable block (ram,0x0066d50a) */
/* WARNING: Removing unreachable block (ram,0x0066d50e) */

undefined4 * FUN_0066d490(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined4 *in_EAX;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  
  *param_1 = *in_EAX;
  puVar6 = param_1 + 1;
  iVar10 = 0x1e;
  do {
    *(undefined2 *)puVar6 = *(undefined2 *)(((int)in_EAX - (int)param_1) + (int)puVar6);
    puVar6 = (undefined4 *)((int)puVar6 + 2);
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  piVar14 = in_EAX + 0x10;
  piVar1 = param_1 + 0x10;
  if (piVar1 != piVar14) {
    puVar6 = (undefined4 *)in_EAX[0x11];
    iVar8 = (int)puVar6 - *piVar14;
    iVar10 = iVar8 >> 0x1f;
    iVar8 = iVar8 / 0x60 + iVar10;
    uVar11 = iVar8 - iVar10;
    if (iVar8 != iVar10) {
      uVar2 = (param_1[0x11] - *piVar1) / 0x60;
      if (uVar11 <= uVar2) {
        puVar3 = (undefined4 *)*piVar14;
        puVar4 = (undefined4 *)*piVar1;
        while (puVar3 != puVar6) {
          puVar15 = puVar3 + 0x18;
          puVar9 = puVar4 + 0x18;
          puVar12 = puVar3;
          puVar13 = puVar4;
          for (iVar10 = 0x18; puVar3 = puVar15, puVar4 = puVar9, iVar10 != 0; iVar10 = iVar10 + -1)
          {
            *puVar13 = *puVar12;
            puVar12 = puVar12 + 1;
            puVar13 = puVar13 + 1;
          }
        }
        param_1[0x11] = ((in_EAX[0x11] - *piVar14) / 0x60) * 0x60 + *piVar1;
        return param_1;
      }
      if ((uint)((param_1[0x12] - *piVar1) / 0x60) < uVar11) {
        if (*piVar1 != 0) {
          FUN_0089120c(*piVar1);
        }
        cVar5 = FUN_00508040();
        if (cVar5 != '\0') {
          uVar7 = FUN_00508080(in_EAX[0x11],param_1);
          param_1[0x11] = uVar7;
          return param_1;
        }
      }
      else {
        puVar6 = (undefined4 *)*piVar14;
        puVar3 = puVar6;
        puVar4 = (undefined4 *)*piVar1;
        while (puVar3 != puVar6 + uVar2 * 0x18) {
          puVar12 = puVar4 + 0x18;
          puVar9 = puVar3 + 0x18;
          puVar13 = puVar3;
          puVar15 = puVar4;
          for (iVar10 = 0x18; puVar3 = puVar9, puVar4 = puVar12, iVar10 != 0; iVar10 = iVar10 + -1)
          {
            *puVar15 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar15 = puVar15 + 1;
          }
        }
        uVar7 = FUN_00508080(in_EAX[0x11],param_1);
        param_1[0x11] = uVar7;
      }
      return param_1;
    }
    if (*piVar1 != param_1[0x11]) {
      param_1[0x11] = *piVar1;
    }
  }
  return param_1;
}

