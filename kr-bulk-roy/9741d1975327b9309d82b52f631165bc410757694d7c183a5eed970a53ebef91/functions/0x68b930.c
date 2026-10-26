
void FUN_0068b930(int *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int *piVar3;
  longlong lVar4;
  int iVar5;
  uint *in_EAX;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int in_ECX;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined2 *puVar13;
  int local_20;
  int local_1c;
  int local_10;
  int local_c [2];
  
  if (*(int *)(in_ECX + 0xcc) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(*(int *)(in_ECX + 0xcc) + 0xd0);
  }
  iVar6 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8)) / iVar6;
  iVar11 = param_1[1] - *param_1 >> 1;
  lVar4 = CONCAT44(param_1[1] - *param_1 >> 0x1f,iVar11);
  iVar7 = (int)(lVar4 / (longlong)iVar6);
  local_c[0] = (int)(lVar4 % (longlong)iVar6);
  local_c[1] = iVar6;
  if (iVar7 == 0) {
    iVar6 = 0;
    if (0 < iVar11) {
      do {
        puVar1 = (undefined2 *)(*param_1 + iVar6 * 2);
        puVar13 = (undefined2 *)in_EAX[1];
        if ((puVar1 < puVar13) && (puVar2 = (undefined2 *)*in_EAX, puVar2 <= puVar1)) {
          if (puVar13 == (undefined2 *)in_EAX[2]) {
            FUN_00419600();
          }
          if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
            *(undefined2 *)in_EAX[1] =
                 *(undefined2 *)(*in_EAX + ((int)puVar1 - (int)puVar2 >> 1) * 2);
          }
        }
        else {
          if (puVar13 == (undefined2 *)in_EAX[2]) {
            FUN_00419600();
          }
          if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
            *(undefined2 *)in_EAX[1] = *puVar1;
          }
        }
        in_EAX[1] = in_EAX[1] + 2;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar11);
    }
  }
  else if (0 < iVar7) {
    iVar5 = iVar6 * -2;
    iVar11 = iVar7 * iVar6 * 2;
    local_1c = (iVar7 * 2 + -2) * iVar6;
    do {
      iVar12 = iVar11;
      local_10 = local_c[0];
      if (0 < local_c[0]) {
        do {
          puVar1 = (undefined2 *)in_EAX[1];
          puVar13 = (undefined2 *)(*param_1 + iVar12);
          if ((puVar13 < puVar1) && (puVar2 = (undefined2 *)*in_EAX, puVar2 <= puVar13)) {
            if (puVar1 == (undefined2 *)in_EAX[2]) {
              FUN_00419600();
            }
            if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
              *(undefined2 *)in_EAX[1] =
                   *(undefined2 *)(*in_EAX + ((int)puVar13 - (int)puVar2 >> 1) * 2);
            }
          }
          else {
            if (puVar1 == (undefined2 *)in_EAX[2]) {
              FUN_00419600();
            }
            if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
              *(undefined2 *)in_EAX[1] = *puVar13;
            }
          }
          in_EAX[1] = in_EAX[1] + 2;
          piVar8 = (int *)in_EAX[1];
          local_10 = local_10 + -1;
          iVar12 = iVar12 + 2;
        } while (local_10 != 0);
        local_10 = local_c[0];
        if (local_c[0] < local_c[1]) {
          local_c[0] = -1;
          do {
            if (local_c < piVar8) {
              piVar3 = (int *)*in_EAX;
              if (local_c < piVar3) goto LAB_0068bb07;
              if (piVar8 == (int *)in_EAX[2]) {
                uVar9 = (int)piVar8 - (int)piVar3 >> 1;
                if (0x7ffffffe < uVar9) goto LAB_0068bc8b;
                uVar9 = uVar9 + 1;
                uVar10 = (int)in_EAX[2] - (int)piVar3 >> 1;
                if (uVar10 < uVar9) {
                  if (0x7fffffff - (uVar10 >> 1) < uVar10) {
                    uVar10 = 0;
                  }
                  else {
                    uVar10 = uVar10 + (uVar10 >> 1);
                  }
                  if (uVar10 < uVar9) {
                    uVar10 = uVar9;
                  }
                  FUN_00419730(uVar10);
                }
              }
              if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
                *(undefined2 *)in_EAX[1] =
                     *(undefined2 *)(*in_EAX + ((int)local_c - (int)piVar3 >> 1) * 2);
              }
            }
            else {
LAB_0068bb07:
              if (piVar8 == (int *)in_EAX[2]) {
                uVar9 = (int)((int)piVar8 - *in_EAX) >> 1;
                if (0x7ffffffe < uVar9) goto LAB_0068bc8b;
                uVar9 = uVar9 + 1;
                uVar10 = (int)((int)in_EAX[2] - *in_EAX) >> 1;
                if (uVar10 < uVar9) {
                  if (0x7fffffff - (uVar10 >> 1) < uVar10) {
                    uVar10 = 0;
                  }
                  else {
                    uVar10 = uVar10 + (uVar10 >> 1);
                  }
                  if (uVar10 < uVar9) {
                    uVar10 = uVar9;
                  }
                  FUN_00419730(uVar10);
                }
              }
              if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
                *(undefined2 *)in_EAX[1] = 0xffff;
              }
            }
            in_EAX[1] = in_EAX[1] + 2;
            piVar8 = (int *)in_EAX[1];
            local_10 = local_10 + 1;
          } while (local_10 < local_c[1]);
        }
        local_c[0] = 0;
        iVar6 = local_c[1];
      }
      local_20 = 0;
      if (0 < iVar6) {
        local_10 = local_1c;
        do {
          puVar13 = (undefined2 *)(*param_1 + local_10);
          puVar1 = (undefined2 *)in_EAX[1];
          if ((puVar13 < puVar1) && (puVar2 = (undefined2 *)*in_EAX, puVar2 <= puVar13)) {
            if (puVar1 == (undefined2 *)in_EAX[2]) {
              uVar9 = (int)puVar1 - (int)puVar2 >> 1;
              if (0x7ffffffe < uVar9) goto LAB_0068bc8b;
              uVar9 = uVar9 + 1;
              uVar10 = (int)in_EAX[2] - (int)puVar2 >> 1;
              if (uVar10 < uVar9) {
                if (0x7fffffff - (uVar10 >> 1) < uVar10) {
                  uVar10 = 0;
                }
                else {
                  uVar10 = uVar10 + (uVar10 >> 1);
                }
                if (uVar10 < uVar9) {
                  uVar10 = uVar9;
                }
                FUN_00419730(uVar10);
              }
            }
            if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
              *(undefined2 *)in_EAX[1] =
                   *(undefined2 *)(*in_EAX + ((int)puVar13 - (int)puVar2 >> 1) * 2);
            }
          }
          else {
            if (puVar1 == (undefined2 *)in_EAX[2]) {
              uVar9 = (int)((int)puVar1 - *in_EAX) >> 1;
              if (0x7ffffffe < uVar9) {
LAB_0068bc8b:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar9 = uVar9 + 1;
              uVar10 = (int)((int)in_EAX[2] - *in_EAX) >> 1;
              if (uVar10 < uVar9) {
                if (0x7fffffff - (uVar10 >> 1) < uVar10) {
                  uVar10 = 0;
                }
                else {
                  uVar10 = uVar10 + (uVar10 >> 1);
                }
                if (uVar10 < uVar9) {
                  uVar10 = uVar9;
                }
                FUN_00419730(uVar10);
              }
            }
            if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
              *(undefined2 *)in_EAX[1] = *puVar13;
            }
          }
          in_EAX[1] = in_EAX[1] + 2;
          local_10 = local_10 + 2;
          local_20 = local_20 + 1;
          iVar6 = local_c[1];
        } while (local_20 < local_c[1]);
      }
      iVar11 = iVar11 + iVar5;
      local_1c = local_1c + iVar5;
      iVar7 = iVar7 + -1;
      if (iVar7 < 1) {
        return;
      }
    } while( true );
  }
  return;
}

