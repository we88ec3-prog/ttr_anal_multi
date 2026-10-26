
void FUN_006544c0(byte *param_1,uint param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte in_AL;
  byte bVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  
  pbVar5 = param_1;
  if ((in_AL != 0) && (in_AL <= *param_1)) {
    param_1[1] = in_AL;
    pvVar2 = *(void **)(param_1 + 0x10);
    if (pvVar2 != *(void **)(param_1 + 0x14)) {
      FID_conflict__memcpy(pvVar2,*(void **)(param_1 + 0x14),0);
      *(void **)(pbVar5 + 0x14) = pvVar2;
    }
    pvVar2 = *(void **)(pbVar5 + 0x20);
    if (pvVar2 != *(void **)(pbVar5 + 0x24)) {
      param_1 = (byte *)0x0;
      FID_conflict__memcpy(pvVar2,*(void **)(pbVar5 + 0x24),0);
      *(int *)(pbVar5 + 0x24) = (int)param_1 + (int)pvVar2;
    }
    param_1._0_3_ = 0;
    param_1._3_1_ = 0;
    FUN_00443d10();
    bVar11 = 0;
    if (*pbVar5 != 0) {
      do {
        bVar6 = 0;
        if (pbVar5[2] != 0) {
          do {
            uVar12 = (uint)bVar6;
            bVar6 = bVar6 + 1;
            *(undefined4 *)(*(int *)((uint)bVar11 * 4 + *(int *)(pbVar5 + 4)) + uVar12 * 4) = 0;
          } while (bVar6 < pbVar5[2]);
        }
        bVar11 = bVar11 + 1;
      } while (bVar11 < *pbVar5);
    }
    FUN_0089288b(param_2);
    param_2 = param_2 & 0xffffff;
    if (pbVar5[2] != 2 && -1 < (int)(pbVar5[2] - 2)) {
      do {
        param_1._3_1_ = 0;
        if (pbVar5[1] != 1 && -1 < (int)(pbVar5[1] - 1)) {
          uVar12 = 0;
          do {
            iVar7 = FUN_0089289d();
            iVar7 = iVar7 % (int)(pbVar5[2] - 2);
            if (0 < iVar7) {
              piVar1 = (int *)(*(int *)(pbVar5 + 4) + uVar12 * 4);
              iVar3 = *piVar1;
              if ((*(int *)(iVar3 + iVar7 * 4) == 0) && (*(int *)(piVar1[1] + iVar7 * 4) == 0)) {
                *(undefined4 *)(iVar3 + iVar7 * 4) = 2;
                *(undefined4 *)(*(int *)(*(int *)(pbVar5 + 4) + 4 + uVar12 * 4) + iVar7 * 4) = 1;
              }
            }
            param_1._3_1_ = param_1._3_1_ + 1;
            uVar12 = (uint)param_1._3_1_;
          } while ((int)uVar12 < (int)(pbVar5[1] - 1));
        }
        bVar11 = param_2._3_1_ + 1;
        param_2 = CONCAT13(bVar11,(undefined3)param_2);
      } while ((int)(uint)bVar11 < (int)(pbVar5[2] - 2));
    }
    param_2 = param_2 & 0xffffff;
    if (pbVar5[1] != 0) {
      do {
        param_1._3_1_ = param_2._3_1_;
        if (pbVar5[2] != 0) {
          uVar12 = (uint)pbVar5[2];
          iVar7 = 0;
          do {
            iVar3 = *(int *)(iVar7 + *(int *)(*(int *)(pbVar5 + 4) + (uint)param_1._3_1_ * 4));
            if (iVar3 == 1) {
              param_1._3_1_ = param_1._3_1_ - 1;
            }
            else if (iVar3 == 2) {
              param_1._3_1_ = param_1._3_1_ + 1;
            }
            iVar7 = iVar7 + 4;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        uVar10 = *(uint *)(pbVar5 + 0x14);
        uVar12 = (int)&param_1 + 3;
        if ((uVar12 < uVar10) && (uVar4 = *(uint *)(pbVar5 + 0x10), uVar4 <= uVar12)) {
          if (uVar10 == *(uint *)(pbVar5 + 0x18)) {
            if (uVar10 - uVar4 == -1) {
LAB_00654718:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar8 = (uVar10 - uVar4) + 1;
            uVar10 = *(uint *)(pbVar5 + 0x18) - uVar4;
            if (uVar10 < uVar8) {
              if (-(uVar10 >> 1) - 1 < uVar10) {
                uVar10 = 0;
              }
              else {
                uVar10 = uVar10 + (uVar10 >> 1);
              }
              if (uVar10 < uVar8) {
                uVar10 = uVar8;
              }
              FUN_00407d50(uVar10);
            }
          }
          pbVar9 = *(byte **)(pbVar5 + 0x14);
          if (pbVar9 != (byte *)0x0) {
            param_1._3_1_ = *(byte *)((uVar12 - uVar4) + *(int *)(pbVar5 + 0x10));
LAB_006546f9:
            *pbVar9 = param_1._3_1_;
          }
        }
        else {
          if (uVar10 == *(uint *)(pbVar5 + 0x18)) {
            uVar12 = *(uint *)(pbVar5 + 0x10);
            iVar7 = uVar10 - uVar12;
            if (iVar7 == -1) goto LAB_00654718;
            uVar10 = iVar7 + 1;
            uVar12 = *(uint *)(pbVar5 + 0x18) - uVar12;
            if (uVar12 < uVar10) {
              if (-(uVar12 >> 1) - 1 < uVar12) {
                uVar12 = 0;
              }
              else {
                uVar12 = uVar12 + (uVar12 >> 1);
              }
              if (uVar12 < uVar10) {
                uVar12 = uVar10;
              }
              FUN_00407d50(uVar12);
            }
          }
          pbVar9 = *(byte **)(pbVar5 + 0x14);
          if (pbVar9 != (byte *)0x0) goto LAB_006546f9;
        }
        *(int *)(pbVar5 + 0x14) = *(int *)(pbVar5 + 0x14) + 1;
        bVar11 = param_2._3_1_ + 1;
        param_2 = CONCAT13(bVar11,(undefined3)param_2);
      } while (bVar11 < pbVar5[1]);
    }
  }
  return;
}

