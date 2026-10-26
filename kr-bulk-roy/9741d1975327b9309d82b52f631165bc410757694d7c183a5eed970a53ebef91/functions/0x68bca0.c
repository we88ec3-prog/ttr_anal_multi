
void FUN_0068bca0(int *param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *unaff_ESI;
  undefined4 *puVar10;
  int local_24;
  int local_20;
  int local_14;
  int local_10;
  undefined4 local_8;
  
  if (*(int *)(in_ECX + 0xcc) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(in_ECX + 0xcc) + 0xd0);
  }
  iVar3 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8)) / iVar3;
  iVar8 = param_1[1] - *param_1 >> 2;
  lVar2 = CONCAT44(param_1[1] - *param_1 >> 0x1f,iVar8);
  iVar4 = (int)(lVar2 / (longlong)iVar3);
  local_10 = (int)(lVar2 % (longlong)iVar3);
  if (iVar4 == 0) {
    iVar3 = 0;
    if (0 < iVar8) {
      do {
        puVar5 = (undefined4 *)(*param_1 + iVar3 * 4);
        puVar10 = (undefined4 *)unaff_ESI[1];
        if ((puVar5 < puVar10) && (puVar1 = (undefined4 *)*unaff_ESI, puVar1 <= puVar5)) {
          if (puVar10 == (undefined4 *)unaff_ESI[2]) {
            FUN_0068c010();
          }
          if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
            *(undefined4 *)unaff_ESI[1] =
                 *(undefined4 *)(*unaff_ESI + ((int)puVar5 - (int)puVar1 >> 2) * 4);
          }
        }
        else {
          if (puVar10 == (undefined4 *)unaff_ESI[2]) {
            FUN_0068c010();
          }
          if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
            *(undefined4 *)unaff_ESI[1] = *puVar5;
          }
        }
        unaff_ESI[1] = unaff_ESI[1] + 4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar8);
    }
  }
  else if (0 < iVar4) {
    iVar8 = iVar4 * iVar3 * 4;
    local_20 = (iVar4 * 4 + -4) * iVar3;
    do {
      iVar9 = iVar8;
      local_14 = local_10;
      if (0 < local_10) {
        do {
          puVar5 = (undefined4 *)unaff_ESI[1];
          puVar10 = (undefined4 *)(*param_1 + iVar9);
          if ((puVar10 < puVar5) && (puVar1 = (undefined4 *)*unaff_ESI, puVar1 <= puVar10)) {
            if (puVar5 == (undefined4 *)unaff_ESI[2]) {
              FUN_0068c010();
            }
            if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
              *(undefined4 *)unaff_ESI[1] =
                   *(undefined4 *)(*unaff_ESI + ((int)puVar10 - (int)puVar1 >> 2) * 4);
            }
          }
          else {
            if (puVar5 == (undefined4 *)unaff_ESI[2]) {
              FUN_0068c010();
            }
            if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
              *(undefined4 *)unaff_ESI[1] = *puVar10;
            }
          }
          unaff_ESI[1] = unaff_ESI[1] + 4;
          puVar5 = (undefined4 *)unaff_ESI[1];
          local_14 = local_14 + -1;
          iVar9 = iVar9 + 4;
        } while (local_14 != 0);
        local_14 = local_10;
        if (local_10 < iVar3) {
          local_8 = 0;
          do {
            if (&local_8 < puVar5) {
              puVar10 = (undefined4 *)*unaff_ESI;
              if (&local_8 < puVar10) goto LAB_0068be71;
              if (puVar5 == (undefined4 *)unaff_ESI[2]) {
                uVar6 = (int)puVar5 - (int)puVar10 >> 2;
                if (0x3ffffffe < uVar6) goto LAB_0068bffc;
                uVar6 = uVar6 + 1;
                uVar7 = (int)unaff_ESI[2] - (int)puVar10 >> 2;
                if (uVar7 < uVar6) {
                  if (0x3fffffff - (uVar7 >> 1) < uVar7) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = uVar7 + (uVar7 >> 1);
                  }
                  if (uVar7 < uVar6) {
                    uVar7 = uVar6;
                  }
                  FUN_0083f320(uVar7);
                }
              }
              if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
                *(undefined4 *)unaff_ESI[1] =
                     *(undefined4 *)(*unaff_ESI + ((int)&local_8 - (int)puVar10 >> 2) * 4);
              }
            }
            else {
LAB_0068be71:
              if (puVar5 == (undefined4 *)unaff_ESI[2]) {
                uVar6 = (int)((int)puVar5 - *unaff_ESI) >> 2;
                if (0x3ffffffe < uVar6) goto LAB_0068bffc;
                uVar6 = uVar6 + 1;
                uVar7 = (int)((int)unaff_ESI[2] - *unaff_ESI) >> 2;
                if (uVar7 < uVar6) {
                  if (0x3fffffff - (uVar7 >> 1) < uVar7) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = uVar7 + (uVar7 >> 1);
                  }
                  if (uVar7 < uVar6) {
                    uVar7 = uVar6;
                  }
                  FUN_0083f320(uVar7);
                }
              }
              if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
                *(undefined4 *)unaff_ESI[1] = local_8;
              }
            }
            unaff_ESI[1] = unaff_ESI[1] + 4;
            puVar5 = (undefined4 *)unaff_ESI[1];
            local_14 = local_14 + 1;
          } while (local_14 < iVar3);
        }
        local_10 = 0;
      }
      local_24 = 0;
      if (0 < iVar3) {
        local_14 = local_20;
        do {
          puVar10 = (undefined4 *)(*param_1 + local_14);
          puVar5 = (undefined4 *)unaff_ESI[1];
          if ((puVar10 < puVar5) && (puVar1 = (undefined4 *)*unaff_ESI, puVar1 <= puVar10)) {
            if (puVar5 == (undefined4 *)unaff_ESI[2]) {
              uVar6 = (int)puVar5 - (int)puVar1 >> 2;
              if (0x3ffffffe < uVar6) goto LAB_0068bffc;
              uVar6 = uVar6 + 1;
              uVar7 = (int)unaff_ESI[2] - (int)puVar1 >> 2;
              if (uVar7 < uVar6) {
                if (0x3fffffff - (uVar7 >> 1) < uVar7) {
                  uVar7 = 0;
                }
                else {
                  uVar7 = uVar7 + (uVar7 >> 1);
                }
                if (uVar7 < uVar6) {
                  uVar7 = uVar6;
                }
                FUN_0083f320(uVar7);
              }
            }
            if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
              *(undefined4 *)unaff_ESI[1] =
                   *(undefined4 *)(*unaff_ESI + ((int)puVar10 - (int)puVar1 >> 2) * 4);
            }
          }
          else {
            if (puVar5 == (undefined4 *)unaff_ESI[2]) {
              uVar6 = (int)((int)puVar5 - *unaff_ESI) >> 2;
              if (0x3ffffffe < uVar6) {
LAB_0068bffc:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar6 = uVar6 + 1;
              uVar7 = (int)((int)unaff_ESI[2] - *unaff_ESI) >> 2;
              if (uVar7 < uVar6) {
                if (0x3fffffff - (uVar7 >> 1) < uVar7) {
                  uVar7 = 0;
                }
                else {
                  uVar7 = uVar7 + (uVar7 >> 1);
                }
                if (uVar7 < uVar6) {
                  uVar7 = uVar6;
                }
                FUN_0083f320(uVar7);
              }
            }
            if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
              *(undefined4 *)unaff_ESI[1] = *puVar10;
            }
          }
          unaff_ESI[1] = unaff_ESI[1] + 4;
          local_14 = local_14 + 4;
          local_24 = local_24 + 1;
        } while (local_24 < iVar3);
      }
      iVar8 = iVar8 + iVar3 * -4;
      local_20 = local_20 + iVar3 * -4;
      iVar4 = iVar4 + -1;
      if (iVar4 < 1) {
        return;
      }
    } while( true );
  }
  return;
}

