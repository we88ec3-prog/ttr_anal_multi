
void FUN_0082eaa0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float10 extraout_ST0;
  float10 extraout_ST1;
  uint uStack00000008;
  int iStack0000000c;
  uint local_28;
  uint local_18;
  int local_14;
  uint local_c;
  
  local_18 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      uStack00000008 = *(uint *)(param_1 + 8);
      local_c = 0;
      if (uStack00000008 != 0) {
        do {
          iVar2 = *(int *)(param_1 + 0x20);
          iVar3 = uStack00000008 * local_18 + local_c;
          if (*(int *)(iVar2 + 0x10 + iVar3 * 0x18) != 0) {
            iStack0000000c = 0;
            iVar4 = FUN_008fed10();
            local_28 = iVar4 + 1 + local_c;
            uVar7 = (local_c - iVar4) - 1;
            iVar5 = (local_18 - iVar4) + -1;
            local_14 = iVar4 + 1 + local_18;
            if ((int)uVar7 < 0) {
              uVar6 = 0;
LAB_0082eb2e:
              uVar7 = uVar6;
            }
            else {
              uVar6 = uStack00000008;
              if ((int)uStack00000008 < (int)uVar7) goto LAB_0082eb2e;
            }
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            else if (*(int *)(param_1 + 0xc) < iVar5) {
              iVar5 = *(int *)(param_1 + 0xc);
            }
            if ((int)local_28 < 0) {
              local_28 = 0;
            }
            else if ((int)uStack00000008 < (int)local_28) {
              local_28 = uStack00000008;
            }
            if (local_14 < 0) {
              local_14 = 0;
            }
            else if (*(int *)(param_1 + 0xc) < local_14) {
              local_14 = *(int *)(param_1 + 0xc);
            }
            fVar1 = (float)(extraout_ST0 * extraout_ST0);
            if (iVar5 < local_14) {
              iVar8 = local_18 - iVar5;
              iVar4 = uStack00000008 * iVar5;
              local_14 = local_14 - iVar5;
              do {
                if ((int)uVar7 < (int)local_28) {
                  uVar6 = uVar7;
                  if (3 < (int)(local_28 - uVar7)) {
                    iVar9 = iVar8 * iVar8;
                    iVar5 = (local_c - uVar7) + -2;
                    do {
                      if (((float)((iVar5 + 2) * (iVar5 + 2) + iVar9) < fVar1) &&
                         (*(int *)(iVar2 + 0x10 + (iVar4 + uVar6) * 0x18) == 0)) {
                        iStack0000000c = iStack0000000c + 1;
                      }
                      if (((float)((iVar5 + 1) * (iVar5 + 1) + iVar9) < fVar1) &&
                         (*(int *)(iVar2 + 0x28 + (iVar4 + uVar6) * 0x18) == 0)) {
                        iStack0000000c = iStack0000000c + 1;
                      }
                      if (((float)(iVar5 * iVar5 + iVar9) < fVar1) &&
                         (*(int *)(iVar2 + 0x40 + (iVar4 + uVar6) * 0x18) == 0)) {
                        iStack0000000c = iStack0000000c + 1;
                      }
                      if (((float)((iVar5 + -1) * (iVar5 + -1) + iVar9) < fVar1) &&
                         (*(int *)(iVar2 + 0x58 + (iVar4 + uVar6) * 0x18) == 0)) {
                        iStack0000000c = iStack0000000c + 1;
                      }
                      uVar6 = uVar6 + 4;
                      iVar5 = iVar5 + -4;
                    } while ((int)uVar6 < (int)(local_28 - 3));
                  }
                  if ((int)uVar6 < (int)local_28) {
                    iVar5 = local_c - uVar6;
                    do {
                      if (((float)(iVar5 * iVar5 + iVar8 * iVar8) < fVar1) &&
                         (*(int *)(iVar2 + 0x10 + (iVar4 + uVar6) * 0x18) == 0)) {
                        iStack0000000c = iStack0000000c + 1;
                      }
                      uVar6 = uVar6 + 1;
                      iVar5 = iVar5 + -1;
                    } while ((int)uVar6 < (int)local_28);
                  }
                }
                iVar4 = iVar4 + uStack00000008;
                iVar8 = iVar8 + -1;
                local_14 = local_14 + -1;
              } while (local_14 != 0);
            }
            *(float *)(iVar2 + iVar3 * 0x18 + 0x14) =
                 (float)((float10)iStack0000000c * extraout_ST1);
          }
          uStack00000008 = *(uint *)(param_1 + 8);
          local_c = local_c + 1;
        } while (local_c < uStack00000008);
      }
      local_18 = local_18 + 1;
    } while (local_18 < *(uint *)(param_1 + 0xc));
  }
  return;
}

