
void FUN_008ce640(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint local_24;
  uint local_1c;
  int local_18;
  int local_14;
  int *local_c;
  
  local_24 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      bVar4 = false;
      if (3 < *(uint *)(*(int *)(param_1 + 0xc) + 4 + local_24 * 8)) {
        piVar8 = *(int **)(*(int *)(param_1 + 0xc) + local_24 * 8);
        piVar5 = piVar8;
        do {
          piVar5 = (int *)piVar5[1];
          if (piVar5 == piVar8) goto LAB_008ce78c;
          iVar9 = piVar5[7];
          iVar10 = piVar8[7];
          iVar1 = piVar5[8];
          iVar2 = piVar8[8];
          piVar3 = piVar8;
        } while ((iVar9 - iVar10 == 0) && (iVar1 - iVar2 == 0));
        do {
          piVar7 = piVar3;
          piVar3 = (int *)*piVar7;
          if (piVar3 == piVar8) goto LAB_008ce78c;
          local_14 = piVar7[7] - piVar3[7];
          local_18 = piVar7[8] - piVar3[8];
        } while (((local_14 == 0) && (local_18 == 0)) ||
                (local_1c = FUN_008b81c0(iVar9 - iVar10,iVar1 - iVar2,local_14,local_18),
                local_c = piVar7, local_1c == 0));
        do {
          do {
            piVar8 = piVar5;
            piVar5 = (int *)piVar8[1];
            if (piVar5 == piVar7) {
              bVar4 = true;
            }
            iVar9 = piVar5[7] - piVar8[7];
            iVar10 = piVar5[8] - piVar8[8];
          } while (((iVar9 == 0) && (iVar10 == 0)) ||
                  (uVar6 = FUN_008b81c0(local_14,local_18,iVar9,iVar10), uVar6 == 0));
          if ((int)(uVar6 ^ local_1c) < 0) {
            do {
              local_c[3] = local_c[3] | 4;
              local_c = (int *)local_c[1];
            } while (local_c != piVar8);
            local_c[3] = local_c[3] | 4;
          }
          local_1c = uVar6;
          local_18 = iVar10;
          local_14 = iVar9;
          local_c = piVar8;
        } while (!bVar4);
      }
LAB_008ce78c:
      local_24 = local_24 + 1;
    } while (local_24 < *(uint *)(param_1 + 4));
  }
  return;
}

