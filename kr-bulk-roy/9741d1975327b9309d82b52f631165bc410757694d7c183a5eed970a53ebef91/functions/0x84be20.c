
/* WARNING: Removing unreachable block (ram,0x0084beef) */
/* WARNING: Removing unreachable block (ram,0x0084bf47) */
/* WARNING: Removing unreachable block (ram,0x0084c2e4) */

void FUN_0084be20(undefined4 *param_1,float *param_2,uint param_3,uint *param_4,uint *param_5,
                 int *param_6,uint *param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  uint *local_34;
  uint local_1c;
  uint local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090e248;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar8 = (uint *)0x0;
  local_34 = (uint *)0x0;
  local_8 = 0;
  local_1c = 0;
  if (*param_4 != 0) {
    do {
      piVar10 = (int *)*param_1;
      uVar11 = 0;
      if (piVar10[1] - *piVar10 >> 2 != 0) {
        local_18[0] = *(uint *)(param_3 + local_1c * 4);
        puVar7 = (uint *)*piVar10;
        do {
          if (local_18[0] == *puVar7) {
            local_18[0] = uVar11;
            if (local_18 < puVar8) {
              if (puVar8 == (uint *)0x0) {
                FUN_00797980(1);
                puVar8 = local_34;
              }
              if (puVar8 != (uint *)0x0) {
                *puVar8 = *(uint *)(((int)local_18 >> 2) * 4);
              }
            }
            else {
              if (puVar8 == (uint *)0x0) {
                FUN_00797980(1);
                puVar8 = local_34;
              }
              if (puVar8 != (uint *)0x0) {
                *puVar8 = uVar11;
              }
            }
            puVar8 = puVar8 + 1;
            local_34 = puVar8;
            break;
          }
          uVar11 = uVar11 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar11 < (uint)(piVar10[1] - *piVar10 >> 2));
      }
      local_1c = local_1c + 1;
    } while (local_1c < *param_4);
  }
  puVar8 = param_5;
  uVar12 = 0;
  uVar11 = 0;
  param_3 = 0;
  if (*param_4 != 0) {
    bVar6 = 0;
    do {
      piVar10 = (int *)(uVar11 * 4);
      bVar4 = bVar6 & 0x1f;
      uVar11 = uVar11 + 1;
      bVar6 = bVar6 + 8;
      uVar12 = uVar12 | *piVar10 << bVar4 & *(uint *)(s___AVgbMesh___00f8bec8 + uVar11 * 4 + 0xc);
      param_3 = uVar12;
    } while (uVar11 < *param_4);
  }
  puVar7 = param_1 + 5;
  uVar12 = 0;
  uVar11 = (int)(param_1[6] - *puVar7) >> 2;
  if (uVar11 != 0) {
    param_4 = (uint *)*param_5;
    piVar10 = (int *)*puVar7;
    do {
      iVar9 = *piVar10;
      if ((((param_3 == param_4[iVar9]) &&
           (iVar1 = *param_6 + iVar9 * 0xc, *(float *)(*param_6 + iVar9 * 0xc) == *param_2)) &&
          (*(float *)(iVar1 + 4) == param_2[1])) && (*(float *)(iVar1 + 8) == param_2[2]))
      goto LAB_0084c20e;
      uVar12 = uVar12 + 1;
      piVar10 = piVar10 + 1;
    } while (uVar12 < uVar11);
  }
  puVar2 = (undefined4 *)param_5[1];
  if ((&param_3 < puVar2) && (puVar3 = (undefined4 *)*param_5, puVar3 <= &param_3)) {
    if (puVar2 == (undefined4 *)param_5[2]) {
      uVar11 = (int)puVar2 - (int)puVar3 >> 2;
      if (0x3ffffffe < uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long",uVar5);
      }
      uVar11 = uVar11 + 1;
      uVar12 = (int)param_5[2] - (int)puVar3 >> 2;
      if (uVar12 < uVar11) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar11) {
          uVar12 = uVar11;
        }
        FUN_00797980(uVar12);
      }
    }
    if ((undefined4 *)puVar8[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar8[1] = *(undefined4 *)(*puVar8 + ((int)&param_3 - (int)puVar3 >> 2) * 4);
    }
  }
  else {
    if (puVar2 == (undefined4 *)param_5[2]) {
      uVar11 = (int)((int)puVar2 - *param_5) >> 2;
      if (0x3ffffffe < uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long",uVar5);
      }
      uVar11 = uVar11 + 1;
      uVar12 = (int)((int)param_5[2] - *param_5) >> 2;
      if (uVar12 < uVar11) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar11) {
          uVar12 = uVar11;
        }
        FUN_00797980(uVar12);
      }
    }
    if ((uint *)puVar8[1] != (uint *)0x0) {
      *(uint *)puVar8[1] = param_3;
    }
  }
  puVar8[1] = puVar8[1] + 4;
  iVar9 = ((int)(puVar8[1] - *puVar8) >> 2) + -1;
  param_4 = (uint *)iVar9;
  FUN_00857f00();
  puVar2 = (undefined4 *)param_1[6];
  if (&param_4 < puVar2) {
    puVar3 = (undefined4 *)*puVar7;
    if (&param_4 < puVar3) goto LAB_0084c1b7;
    if (puVar2 == (undefined4 *)param_1[7]) {
      uVar11 = (int)puVar2 - (int)puVar3 >> 2;
      if (0x3ffffffe < uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long",uVar5);
      }
      uVar11 = uVar11 + 1;
      uVar12 = (int)param_1[7] - (int)puVar3 >> 2;
      if (uVar12 < uVar11) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar11) {
          uVar12 = uVar11;
        }
        FUN_006ddf10(uVar12);
        iVar9 = (int)param_4;
      }
    }
    if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
      *(undefined4 *)param_1[6] = *(undefined4 *)(*puVar7 + ((int)&param_4 - (int)puVar3 >> 2) * 4);
    }
  }
  else {
LAB_0084c1b7:
    if (puVar2 == (undefined4 *)param_1[7]) {
      uVar11 = (int)((int)puVar2 - *puVar7) >> 2;
      if (0x3ffffffe < uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar11 = uVar11 + 1;
      uVar12 = (int)((int)param_1[7] - *puVar7) >> 2;
      if (uVar12 < uVar11) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar11) {
          uVar12 = uVar11;
        }
        FUN_006ddf10(uVar12);
      }
    }
    if ((int *)param_1[6] != (int *)0x0) {
      *(int *)param_1[6] = iVar9;
    }
  }
  param_1[6] = param_1[6] + 4;
LAB_0084c20e:
  puVar8 = param_7;
  puVar2 = (undefined4 *)param_7[1];
  param_4 = (uint *)iVar9;
  if (&param_4 < puVar2) {
    puVar3 = (undefined4 *)*param_7;
    if (puVar3 <= &param_4) {
      if (puVar2 == (undefined4 *)param_7[2]) {
        uVar11 = (int)puVar2 - (int)puVar3 >> 2;
        if (0x3ffffffe < uVar11) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long",uVar5);
        }
        uVar11 = uVar11 + 1;
        uVar5 = (int)param_7[2] - (int)puVar3 >> 2;
        if (uVar5 < uVar11) {
          if (0x3fffffff - (uVar5 >> 1) < uVar5) {
            uVar5 = 0;
          }
          else {
            uVar5 = uVar5 + (uVar5 >> 1);
          }
          if (uVar5 < uVar11) {
            uVar5 = uVar11;
          }
          FUN_00797980(uVar5);
        }
      }
      if ((undefined4 *)puVar8[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar8[1] = *(undefined4 *)(*puVar8 + ((int)&param_4 - (int)puVar3 >> 2) * 4)
        ;
      }
      goto LAB_0084c2d9;
    }
  }
  if (puVar2 == (undefined4 *)param_7[2]) {
    uVar11 = (int)((int)puVar2 - *param_7) >> 2;
    if (0x3ffffffe < uVar11) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long",uVar5);
    }
    uVar11 = uVar11 + 1;
    uVar5 = (int)((int)param_7[2] - *param_7) >> 2;
    if (uVar5 < uVar11) {
      if (0x3fffffff - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (uVar5 < uVar11) {
        uVar5 = uVar11;
      }
      FUN_00797980(uVar5);
    }
  }
  if ((int *)puVar8[1] != (int *)0x0) {
    *(int *)puVar8[1] = iVar9;
  }
LAB_0084c2d9:
  puVar8[1] = puVar8[1] + 4;
  ExceptionList = local_10;
  return;
}

