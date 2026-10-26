
void FUN_00854ae0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int in_EAX;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int local_8;
  
  iVar7 = ((int)param_2 - (int)param_1) / 0x14;
  iVar6 = (in_EAX - (int)param_1) / 0x14;
  iVar9 = iVar6;
  local_8 = iVar7;
  while (iVar8 = iVar9, iVar8 != 0) {
    iVar9 = local_8 % iVar8;
    local_8 = iVar8;
  }
  if ((local_8 < iVar7) && (0 < local_8)) {
    puVar10 = param_1 + local_8 * 5;
    do {
      puVar12 = param_1;
      puVar13 = puVar10;
      if (puVar10 + iVar6 * 5 != param_2) {
        puVar12 = puVar10 + iVar6 * 5;
      }
      do {
        puVar11 = puVar12;
        uVar1 = puVar13[2];
        uVar2 = *puVar13;
        uVar3 = puVar13[1];
        uVar4 = puVar13[3];
        uVar5 = puVar13[4];
        *puVar13 = *puVar11;
        puVar13[1] = puVar11[1];
        puVar13[2] = puVar11[2];
        puVar13[3] = puVar11[3];
        puVar13[4] = puVar11[4];
        *puVar11 = uVar2;
        puVar11[1] = uVar3;
        puVar11[2] = uVar1;
        puVar11[3] = uVar4;
        puVar11[4] = uVar5;
        iVar7 = ((int)param_2 - (int)puVar11) / 0x14;
        if (iVar6 < iVar7) {
          puVar12 = puVar11 + iVar6 * 5;
        }
        else {
          puVar12 = param_1 + (iVar6 - iVar7) * 5;
        }
        puVar13 = puVar11;
      } while (puVar12 != puVar10);
      local_8 = local_8 + -1;
      puVar10 = puVar10 + -5;
    } while (0 < local_8);
  }
  return;
}

