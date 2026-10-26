
void FUN_008cec30(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_EAX;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 0xc);
  uVar2 = *(uint *)(in_EAX + 4);
  if (param_2 != 0) {
    puVar4 = (uint *)(param_1 + 0x10);
    do {
      uVar9 = *puVar4;
      uVar3 = puVar4[3];
      if ((uVar9 & 0x10) == 0) {
        iVar5 = (int)(char)puVar4[1];
        if (((((iVar5 == param_3) || (iVar5 == -param_3)) ||
             (iVar5 = (int)*(char *)((int)puVar4 + 5), iVar5 == param_3)) || (iVar5 == -param_3)) &&
           (iVar5 != 0)) {
          if (iVar5 == param_3) {
            uVar8 = 0;
            if (uVar2 != 0) {
              do {
                piVar7 = *(int **)(iVar1 + uVar8 * 4);
                iVar5 = uVar3 - *piVar7;
                if ((iVar5 < unaff_EDI) && (-iVar5 < unaff_EDI)) {
                  *puVar4 = uVar9 | 0x210;
                  puVar4[2] = (uint)piVar7;
                  break;
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < uVar2);
            }
          }
          else if ((iVar5 == -param_3) && (uVar8 = 0, uVar2 != 0)) {
            do {
              piVar7 = *(int **)(iVar1 + uVar8 * 4);
              iVar5 = (uVar3 - piVar7[1]) - *piVar7;
              if ((iVar5 < unaff_EDI) && (-iVar5 < unaff_EDI)) {
                *puVar4 = uVar9 | 0x410;
                puVar4[2] = (uint)piVar7;
                break;
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar2);
          }
        }
        else if ((uVar9 & 0x40) != 0) {
          if (param_3 == 2) {
            uVar8 = 0x80;
            uVar6 = 0x100;
          }
          else {
            uVar8 = 0x100;
            uVar6 = 0x80;
          }
          if ((uVar9 & uVar8) == 0) {
            if (((uVar9 & uVar6) != 0) && (uVar8 = 0, uVar2 != 0)) {
              do {
                piVar7 = *(int **)(iVar1 + uVar8 * 4);
                iVar5 = (uVar3 - piVar7[1]) - *piVar7;
                if ((iVar5 < unaff_EDI) && (-iVar5 < unaff_EDI)) {
                  uVar9 = uVar9 | 0x410;
                  goto LAB_008ceda4;
                }
                uVar8 = uVar8 + 1;
              } while (uVar8 < uVar2);
            }
          }
          else {
            uVar8 = 0;
            if (uVar2 != 0) {
LAB_008ced51:
              piVar7 = *(int **)(iVar1 + uVar8 * 4);
              if ((unaff_EDI <= (int)(uVar3 - *piVar7)) || (unaff_EDI <= (int)-(uVar3 - *piVar7)))
              goto LAB_008ced62;
              uVar9 = uVar9 | 0x210;
LAB_008ceda4:
              *puVar4 = uVar9;
              puVar4[2] = (uint)piVar7;
            }
          }
LAB_008cedac:
          if ((puVar4[2] == 0) && (uVar9 = 0, uVar2 != 0)) {
            do {
              piVar7 = *(int **)(iVar1 + uVar9 * 4);
              if ((*piVar7 <= (int)uVar3) && ((int)uVar3 <= piVar7[1] + *piVar7)) {
                puVar4[2] = (uint)piVar7;
                break;
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < uVar2);
          }
        }
      }
      param_2 = param_2 + -1;
      puVar4 = puVar4 + 10;
    } while (param_2 != 0);
  }
  return;
LAB_008ced62:
  uVar8 = uVar8 + 1;
  if (uVar2 <= uVar8) goto LAB_008cedac;
  goto LAB_008ced51;
}

