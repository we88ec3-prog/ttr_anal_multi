
void FUN_008549e0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_EAX;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int local_8;
  
  iVar5 = ((int)param_2 - (int)param_1) / 0xc;
  iVar4 = (in_EAX - (int)param_1) / 0xc;
  iVar7 = iVar4;
  local_8 = iVar5;
  while (iVar6 = iVar7, iVar6 != 0) {
    iVar7 = local_8 % iVar6;
    local_8 = iVar6;
  }
  if ((local_8 < iVar5) && (0 < local_8)) {
    puVar8 = param_1 + local_8 * 3;
    do {
      puVar10 = param_1;
      puVar11 = puVar8;
      if (puVar8 + iVar4 * 3 != param_2) {
        puVar10 = puVar8 + iVar4 * 3;
      }
      do {
        puVar9 = puVar10;
        uVar1 = puVar11[2];
        uVar2 = *puVar11;
        uVar3 = puVar11[1];
        *puVar11 = *puVar9;
        puVar11[1] = puVar9[1];
        puVar11[2] = puVar9[2];
        *puVar9 = uVar2;
        puVar9[1] = uVar3;
        puVar9[2] = uVar1;
        iVar5 = ((int)param_2 - (int)puVar9) / 0xc;
        if (iVar4 < iVar5) {
          puVar10 = puVar9 + iVar4 * 3;
        }
        else {
          puVar10 = param_1 + (iVar4 - iVar5) * 3;
        }
        puVar11 = puVar9;
      } while (puVar10 != puVar8);
      local_8 = local_8 + -1;
      puVar8 = puVar8 + -3;
    } while (0 < local_8);
  }
  return;
}

