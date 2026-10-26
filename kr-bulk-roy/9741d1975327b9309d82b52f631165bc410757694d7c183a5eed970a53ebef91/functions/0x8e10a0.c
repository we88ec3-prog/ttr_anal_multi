
uint FUN_008e10a0(undefined4 *param_1)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  char cVar4;
  undefined4 *in_EAX;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  int unaff_ESI;
  undefined4 *local_c;
  
  bVar3 = true;
  cVar4 = FUN_008e0eb0();
  if (cVar4 == '\0') {
    local_c = param_1;
    puVar12 = param_1;
  }
  else {
    cVar4 = FUN_008e0eb0();
    puVar12 = extraout_ECX;
    local_c = in_EAX;
    if (cVar4 != '\0') goto LAB_008e10cf;
  }
  bVar3 = false;
LAB_008e10cf:
  uVar6 = *(uint *)(unaff_ESI + 0x14);
  uVar13 = 0;
  if (uVar6 != 0) {
    piVar5 = (int *)(unaff_ESI + 0x24);
    do {
      if ((int)puVar12[2] <= *piVar5) break;
      uVar13 = uVar13 + 1;
      piVar5 = piVar5 + 5;
    } while (uVar13 < uVar6);
  }
  if (uVar13 < uVar6) {
    iVar7 = *(int *)(unaff_ESI + 0x24 + uVar13 * 0x14);
    uVar6 = unaff_ESI + uVar13 * 0x14;
    if (iVar7 == puVar12[2]) {
      return uVar6;
    }
    if ((bVar3) && (iVar7 <= (int)param_1[2])) {
      return uVar6;
    }
    uVar6 = FUN_008e0ed0();
    if ((char)uVar6 != '\0') {
      return uVar6;
    }
  }
  cVar4 = FUN_008e0f70();
  puVar12 = extraout_ECX_00;
  if ((cVar4 != '\0') && (cVar4 = FUN_008e0f00(), puVar12 = extraout_ECX_01, cVar4 == '\0')) {
    if (bVar3) {
      iVar7 = FUN_008e0f80((int)(extraout_ECX_01[2] + param_1[2]) / 2);
      lVar2 = (longlong)((int)(param_1[2] - local_c[2]) / 2) * (longlong)*(int *)(unaff_ESI + 0x10);
      lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
      iVar8 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
      local_c[3] = iVar7 - iVar8;
      param_1[3] = iVar8 + iVar7;
      puVar12 = local_c;
    }
    else {
      uVar9 = FUN_008e0f80(extraout_ECX_01[2]);
      local_c[3] = uVar9;
      puVar12 = local_c;
    }
  }
  if ((uVar13 == 0) || (uVar6 = uVar13 * 5 + 5, *(int *)(unaff_ESI + uVar6 * 4) <= (int)puVar12[3]))
  {
    uVar1 = *(uint *)(unaff_ESI + 0x14);
    if (uVar13 < uVar1) {
      uVar6 = uVar13 * 5 + 10;
      if (bVar3) {
        iVar7 = param_1[3];
      }
      else {
        iVar7 = puVar12[3];
      }
      if (*(int *)(unaff_ESI + uVar6 * 4) < iVar7) {
        return uVar6;
      }
    }
    uVar6 = uVar1 + 1;
    if (!bVar3) {
      uVar6 = uVar1;
    }
    iVar7 = uVar1 - uVar13;
    if ((int)uVar6 < 0xc0) {
      if (iVar7 != 0) {
        puVar10 = (undefined4 *)(unaff_ESI + 0x1c + uVar6 * 0x14);
        puVar11 = (undefined4 *)(unaff_ESI + 0x1c + (uVar1 * 5 + -5) * 4);
        do {
          *puVar10 = *puVar11;
          puVar10[1] = puVar11[1];
          puVar10[2] = puVar11[2];
          puVar10[3] = puVar11[3];
          puVar10[4] = puVar11[4];
          puVar10 = puVar10 + -5;
          puVar11 = puVar11 + -5;
          iVar7 = iVar7 + -1;
          puVar12 = local_c;
        } while (iVar7 != 0);
      }
      *(undefined4 *)(unaff_ESI + 0x1c + uVar13 * 0x14) = *puVar12;
      uVar6 = unaff_ESI + uVar13 * 0x14;
      *(undefined4 *)(uVar6 + 0x20) = puVar12[1];
      *(undefined4 *)(uVar6 + 0x24) = puVar12[2];
      *(undefined4 *)(uVar6 + 0x28) = puVar12[3];
      *(undefined4 *)(uVar6 + 0x2c) = puVar12[4];
      *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
      if (bVar3) {
        *(undefined4 *)(uVar6 + 0x30) = *param_1;
        *(undefined4 *)(uVar6 + 0x34) = param_1[1];
        *(undefined4 *)(uVar6 + 0x38) = param_1[2];
        *(undefined4 *)(uVar6 + 0x3c) = param_1[3];
        *(undefined4 *)(uVar6 + 0x40) = param_1[4];
        *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + 1;
      }
    }
  }
  return uVar6;
}

