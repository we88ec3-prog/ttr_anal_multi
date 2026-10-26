
int FUN_008f3660(int param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  ushort *puVar11;
  uint local_c;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 100);
  iVar8 = 0;
  local_8 = 0;
  if ((*(int *)(param_1 + 0x2a4) != 0) || (local_8 = FUN_008f0bb0(param_1,0), local_8 == 0)) {
    iVar7 = *(int *)(param_1 + 0x2a4);
    puVar2 = *(uint **)(iVar7 + 8);
    if (param_2 == *puVar2) {
      iVar8 = FUN_008bc7d0(uVar1,4,0,*puVar2,0,&local_8);
      if (local_8 == 0) {
        local_c = 0;
        if (*puVar2 != 0) {
          piVar9 = (int *)(puVar2[3] + 8);
          iVar5 = iVar8 - (int)param_3;
          do {
            iVar6 = *param_3;
            iVar3 = piVar9[1];
            if ((iVar3 < iVar6) || (iVar6 < piVar9[-1])) goto LAB_008f37bf;
            iVar4 = *piVar9;
            if (iVar6 < iVar4) {
              iVar6 = FUN_008b7f40(iVar6 - iVar4,piVar9[-1] - iVar4);
              iVar6 = -iVar6;
LAB_008f3746:
              *(int *)(iVar5 + (int)param_3) = iVar6;
            }
            else {
              if (iVar3 != iVar4) {
                iVar6 = FUN_008b7f40(iVar6 - iVar4,iVar3 - iVar4);
                goto LAB_008f3746;
              }
              *(undefined4 *)(iVar5 + (int)param_3) = 0;
            }
            local_c = local_c + 1;
            param_3 = param_3 + 1;
            piVar9 = piVar9 + 6;
          } while (local_c < *puVar2);
        }
        if (*(char *)(iVar7 + 0x10) == '\0') {
          FUN_008f06c0();
        }
        puVar11 = *(ushort **)(iVar7 + 0x14);
        if ((puVar11 != (ushort *)0x0) && (local_c = 0, *puVar2 != 0)) {
          do {
            uVar10 = 1;
            if (1 < *puVar11) {
              piVar9 = *(int **)(puVar11 + 2);
              iVar7 = *(int *)(iVar8 + local_c * 4);
              do {
                piVar9 = piVar9 + 2;
                if (iVar7 < *piVar9) {
                  iVar5 = *(int *)(puVar11 + 2) + uVar10 * 8;
                  iVar7 = FUN_008b7dc0(iVar7 - *(int *)(iVar5 + -8),
                                       *(int *)(iVar5 + 4) - *(int *)(iVar5 + -4),
                                       *(int *)(*(int *)(puVar11 + 2) + uVar10 * 8) -
                                       *(int *)(iVar5 + -8));
                  *(int *)(iVar8 + local_c * 4) =
                       iVar7 + *(int *)(*(int *)(puVar11 + 2) + -4 + uVar10 * 8);
                  break;
                }
                uVar10 = uVar10 + 1;
              } while (uVar10 < *puVar11);
            }
            local_c = local_c + 1;
            puVar11 = puVar11 + 4;
          } while (local_c < *puVar2);
        }
        local_8 = FUN_008f34f0(param_1,param_2,iVar8);
      }
    }
    else {
LAB_008f37bf:
      local_8 = 6;
    }
  }
  FUN_008b9f80(uVar1,iVar8);
  return local_8;
}

