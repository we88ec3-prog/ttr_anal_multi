
void FUN_008d7380(uint param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  byte extraout_CL;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  uint local_8;
  
  puVar2 = *(undefined4 **)(param_1 + 0x1e8);
  iVar4 = param_2[4];
  pbVar7 = (byte *)param_2[2];
  local_8 = 0;
  bVar10 = false;
  (*(code *)param_2[7])(param_2);
  if ((byte *)*param_2 < pbVar7) {
    bVar6 = *(byte *)*param_2;
    if (bVar6 - 0x30 < 10) {
      iVar3 = (*(code *)param_2[9])(param_2);
      param_2[0x24] = iVar3;
      if (param_2[3] != 0) {
        return;
      }
LAB_008d7461:
      if ((byte *)*param_2 < pbVar7) {
        iVar3 = (**(code **)*puVar2)(param_2 + 0x32,param_2[0x24],iVar4);
        if (((iVar3 != 0) ||
            (iVar3 = (**(code **)*puVar2)(param_2 + 0x25,param_2[0x24],iVar4), iVar3 != 0)) ||
           (iVar3 = (**(code **)*puVar2)(param_2 + 0x3f,4,iVar4), iVar3 != 0)) goto LAB_008d77a4;
        (*(code *)param_2[7])(param_2);
        pbVar8 = (byte *)*param_2;
        param_1 = 0;
        while (((pbVar8 < pbVar7 &&
                (((bVar6 = *pbVar8, bVar6 != 0x65 || (pbVar7 <= pbVar8 + 3)) ||
                 ((pbVar8[1] != 0x6e ||
                  ((pbVar8[2] != 100 || (iVar4 = FUN_008d6b30(), bVar6 = extraout_CL, iVar4 == 0))))
                 )))) && (bVar6 != 0x3e))) {
          (*(code *)param_2[8])(param_2);
          if (param_2[3] != 0) {
            return;
          }
          if (*pbVar8 == 0x2f) {
            pbVar8 = pbVar8 + 1;
            if (pbVar7 <= pbVar8) goto LAB_008d779f;
            iVar4 = *param_2;
            iVar3 = (*(code *)param_2[0x30])
                              (param_2 + 0x25,param_1,pbVar8,(iVar4 - (int)pbVar8) + 1);
            if (iVar3 != 0) goto LAB_008d77a4;
            *(undefined1 *)((iVar4 - (int)pbVar8) + *(int *)(param_2[0x2b] + param_1 * 4)) = 0;
            if (*pbVar8 == 0x2e) {
              pbVar8 = *(byte **)(param_2[0x2b] + param_1 * 4);
              pcVar5 = ".notdef";
              do {
                bVar6 = *pcVar5;
                bVar9 = bVar6 < *pbVar8;
                if (bVar6 != *pbVar8) {
LAB_008d75a4:
                  iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                  goto LAB_008d75a9;
                }
                if (bVar6 == 0) break;
                bVar6 = pcVar5[1];
                bVar9 = bVar6 < pbVar8[1];
                if (bVar6 != pbVar8[1]) goto LAB_008d75a4;
                pcVar5 = pcVar5 + 2;
                pbVar8 = pbVar8 + 2;
              } while (bVar6 != 0);
              iVar4 = 0;
LAB_008d75a9:
              if (iVar4 == 0) {
                bVar10 = true;
                local_8 = param_1;
              }
            }
            (*(code *)param_2[7])(param_2);
            iVar4 = *param_2;
            (*(code *)param_2[9])(param_2);
            pbVar8 = (byte *)*param_2;
            if (pbVar7 <= pbVar8) goto LAB_008d779f;
            iVar3 = (*(code *)param_2[0x3d])(param_2 + 0x32,param_1,iVar4,pbVar8 + (1 - iVar4));
            if (iVar3 != 0) goto LAB_008d77a4;
            iVar3 = param_1 * 4;
            param_1 = param_1 + 1;
            pbVar8[*(int *)(param_2[0x38] + iVar3) - iVar4] = 0;
            if ((uint)param_2[0x24] <= param_1) break;
          }
          (*(code *)param_2[7])(param_2);
          pbVar8 = (byte *)*param_2;
        }
        param_2[0x24] = param_1;
        if (bVar10) {
          pcVar5 = ".notdef";
          pbVar7 = *(byte **)param_2[0x2b];
          do {
            bVar6 = *pcVar5;
            bVar10 = bVar6 < *pbVar7;
            if (bVar6 != *pbVar7) {
LAB_008d7667:
              iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
              goto LAB_008d766c;
            }
            if (bVar6 == 0) break;
            bVar6 = pcVar5[1];
            bVar10 = bVar6 < pbVar7[1];
            if (bVar6 != pbVar7[1]) goto LAB_008d7667;
            pcVar5 = pcVar5 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar6 != 0);
          iVar4 = 0;
LAB_008d766c:
          if (iVar4 == 0) {
            return;
          }
          piVar1 = param_2 + 0x3f;
          iVar3 = (*(code *)param_2[0x4a])
                            (piVar1,0,*(byte **)param_2[0x2b],*(undefined4 *)param_2[0x2c]);
          if (iVar3 == 0) {
            iVar3 = (*(code *)param_2[0x4a])
                              (piVar1,1,*(undefined4 *)param_2[0x38],*(undefined4 *)param_2[0x39]);
            if (((((iVar3 == 0) &&
                  (iVar3 = (*(code *)param_2[0x4a])
                                     (piVar1,2,*(undefined4 *)(param_2[0x2b] + local_8 * 4),
                                      *(undefined4 *)(param_2[0x2c] + local_8 * 4)), iVar3 == 0)) &&
                 (iVar3 = (*(code *)param_2[0x4a])
                                    (piVar1,3,*(undefined4 *)(param_2[0x38] + local_8 * 4),
                                     *(undefined4 *)(param_2[0x39] + local_8 * 4)), iVar3 == 0)) &&
                ((iVar3 = (*(code *)param_2[0x30])
                                    (param_2 + 0x25,local_8,*(undefined4 *)param_2[0x45],
                                     *(undefined4 *)param_2[0x46]), iVar3 == 0 &&
                 (iVar3 = (*(code *)param_2[0x3d])
                                    (param_2 + 0x32,local_8,*(undefined4 *)(param_2[0x45] + 4),
                                     *(undefined4 *)(param_2[0x46] + 4)), iVar3 == 0)))) &&
               ((iVar3 = (*(code *)param_2[0x30])
                                   (param_2 + 0x25,0,*(undefined4 *)(param_2[0x45] + 8),
                                    *(undefined4 *)(param_2[0x46] + 8)), iVar3 == 0 &&
                (iVar3 = (*(code *)param_2[0x3d])
                                   (param_2 + 0x32,0,*(undefined4 *)(param_2[0x45] + 0xc),
                                    *(undefined4 *)(param_2[0x46] + 0xc)), iVar3 == 0)))) {
              return;
            }
          }
          goto LAB_008d77a4;
        }
      }
    }
    else if (bVar6 == 0x3c) {
      param_1 = 0;
      (*(code *)param_2[8])(param_2);
      if (param_2[3] != 0) {
        return;
      }
      (*(code *)param_2[7])(param_2);
      pbVar8 = (byte *)*param_2;
      if (pbVar8 < pbVar7) {
        do {
          if (*(char *)*param_2 == '/') {
            param_1 = param_1 + 1;
          }
          else if (*(char *)*param_2 == '>') {
            param_2[0x24] = param_1;
            *param_2 = (int)pbVar8;
            break;
          }
          (*(code *)param_2[8])(param_2);
          if (param_2[3] != 0) {
            return;
          }
          (*(code *)param_2[7])(param_2);
        } while ((byte *)*param_2 < pbVar7);
        goto LAB_008d7461;
      }
    }
  }
LAB_008d779f:
  iVar3 = 3;
LAB_008d77a4:
  param_2[3] = iVar3;
  return;
}

