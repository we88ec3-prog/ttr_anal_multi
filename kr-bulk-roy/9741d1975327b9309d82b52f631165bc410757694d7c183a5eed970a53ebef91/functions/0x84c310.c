
/* WARNING: Removing unreachable block (ram,0x0084c419) */
/* WARNING: Removing unreachable block (ram,0x0084c471) */
/* WARNING: Removing unreachable block (ram,0x0084c812) */

void FUN_0084c310(float *param_1,int param_2,uint *param_3,int *param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  float **ppfVar3;
  float **ppfVar4;
  uint **ppuVar5;
  uint **ppuVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  undefined4 *in_ECX;
  uint *puVar10;
  uint *in_EDX;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  uint local_54;
  uint *local_48;
  uint local_34;
  uint *local_30;
  float *local_2c;
  float local_28 [4];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090e218;
  local_10 = ExceptionList;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar11 = (uint *)0x0;
  local_48 = (uint *)0x0;
  local_8 = 0;
  local_28[0] = 0.0;
  local_54 = 0;
  local_28[1] = 0.0;
  local_28[2] = 0.0;
  local_30 = in_EDX;
  local_18 = uVar8;
  if (*param_3 != 0) {
    local_2c = param_1;
    do {
      piVar2 = (int *)*in_ECX;
      uVar13 = 0;
      if (piVar2[1] - *piVar2 >> 2 != 0) {
        local_34 = *(uint *)((param_2 - (int)param_1) + (int)local_2c);
        puVar10 = (uint *)*piVar2;
        do {
          if (local_34 == *puVar10) {
            local_28[uVar13] = *local_2c;
            local_34 = uVar13;
            if (&local_34 < puVar11) {
              if (puVar11 == (uint *)0x0) {
                FUN_00797980(1);
                puVar11 = local_48;
              }
              if (puVar11 != (uint *)0x0) {
                *puVar11 = *(uint *)(((int)&local_34 >> 2) * 4);
              }
            }
            else {
              if (puVar11 == (uint *)0x0) {
                FUN_00797980(1);
                puVar11 = local_48;
              }
              if (puVar11 != (uint *)0x0) {
                *puVar11 = uVar13;
              }
            }
            puVar11 = puVar11 + 1;
            local_48 = puVar11;
            break;
          }
          uVar13 = uVar13 + 1;
          puVar10 = puVar10 + 1;
        } while (uVar13 < (uint)(piVar2[1] - *piVar2 >> 2));
      }
      local_2c = local_2c + 1;
      local_54 = local_54 + 1;
    } while (local_54 < *param_3);
  }
  pfVar14 = (float *)0x0;
  uVar13 = 0;
  local_2c = (float *)0x0;
  if (*param_3 != 0) {
    bVar9 = 0;
    do {
      piVar2 = (int *)(uVar13 * 4);
      bVar7 = bVar9 & 0x1f;
      uVar13 = uVar13 + 1;
      bVar9 = bVar9 + 8;
      pfVar14 = (float *)((uint)pfVar14 | *piVar2 << bVar7 & *(uint *)(uVar13 * 4 + 0xf8bee4));
      local_2c = pfVar14;
    } while (uVar13 < *param_3);
  }
  puVar11 = in_ECX + 5;
  uVar12 = 0;
  uVar13 = (int)(in_ECX[6] - *puVar11) >> 2;
  if (uVar13 != 0) {
    puVar10 = (uint *)*puVar11;
    do {
      pfVar14 = (float *)*puVar10;
      if ((((local_2c == *(float **)(*local_30 + (int)pfVar14 * 4)) &&
           (iVar1 = *param_4 + (int)pfVar14 * 0xc,
           *(float *)(*param_4 + (int)pfVar14 * 0xc) == local_28[0])) &&
          (*(float *)(iVar1 + 4) == local_28[1])) && (*(float *)(iVar1 + 8) == local_28[2]))
      goto LAB_0084c73c;
      uVar12 = uVar12 + 1;
      puVar10 = puVar10 + 1;
    } while (uVar12 < uVar13);
  }
  ppfVar3 = (float **)local_30[1];
  if ((&local_2c < ppfVar3) && (ppfVar4 = (float **)*local_30, ppfVar4 <= &local_2c)) {
    if (ppfVar3 == (float **)local_30[2]) {
      uVar13 = (int)ppfVar3 - (int)ppfVar4 >> 2;
      if (0x3ffffffe < uVar13) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long",uVar8);
      }
      uVar13 = uVar13 + 1;
      uVar12 = (int)local_30[2] - (int)ppfVar4 >> 2;
      if (uVar12 < uVar13) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar13) {
          uVar12 = uVar13;
        }
        FUN_00797980(uVar12);
      }
    }
    if ((undefined4 *)local_30[1] != (undefined4 *)0x0) {
      *(undefined4 *)local_30[1] =
           *(undefined4 *)(*local_30 + ((int)&local_2c - (int)ppfVar4 >> 2) * 4);
    }
  }
  else {
    if (ppfVar3 == (float **)local_30[2]) {
      uVar13 = (int)((int)ppfVar3 - *local_30) >> 2;
      if (0x3ffffffe < uVar13) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long",uVar8);
      }
      uVar13 = uVar13 + 1;
      uVar12 = (int)((int)local_30[2] - *local_30) >> 2;
      if (uVar12 < uVar13) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar13) {
          uVar12 = uVar13;
        }
        FUN_00797980(uVar12);
      }
    }
    if ((uint *)local_30[1] != (uint *)0x0) {
      *(uint *)local_30[1] = (uint)local_2c;
    }
  }
  local_30[1] = local_30[1] + 4;
  pfVar14 = (float *)(((int)(local_30[1] - *local_30) >> 2) - 1);
  local_2c = pfVar14;
  FUN_00857f00();
  ppfVar3 = (float **)in_ECX[6];
  if (&local_2c < ppfVar3) {
    ppfVar4 = (float **)*puVar11;
    if (&local_2c < ppfVar4) goto LAB_0084c6e5;
    if (ppfVar3 == (float **)in_ECX[7]) {
      uVar13 = (int)ppfVar3 - (int)ppfVar4 >> 2;
      if (0x3ffffffe < uVar13) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long",uVar8);
      }
      uVar13 = uVar13 + 1;
      uVar12 = (int)in_ECX[7] - (int)ppfVar4 >> 2;
      if (uVar12 < uVar13) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar13) {
          uVar12 = uVar13;
        }
        FUN_006ddf10(uVar12);
        pfVar14 = local_2c;
      }
    }
    if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
      *(undefined4 *)in_ECX[6] =
           *(undefined4 *)(*puVar11 + ((int)&local_2c - (int)ppfVar4 >> 2) * 4);
    }
  }
  else {
LAB_0084c6e5:
    if (ppfVar3 == (float **)in_ECX[7]) {
      uVar13 = (int)((int)ppfVar3 - *puVar11) >> 2;
      if (0x3ffffffe < uVar13) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar13 = uVar13 + 1;
      uVar12 = (int)((int)in_ECX[7] - *puVar11) >> 2;
      if (uVar12 < uVar13) {
        if (0x3fffffff - (uVar12 >> 1) < uVar12) {
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 + (uVar12 >> 1);
        }
        if (uVar12 < uVar13) {
          uVar12 = uVar13;
        }
        FUN_006ddf10(uVar12);
      }
    }
    if ((uint *)in_ECX[6] != (uint *)0x0) {
      *(uint *)in_ECX[6] = (uint)pfVar14;
    }
  }
  in_ECX[6] = in_ECX[6] + 4;
LAB_0084c73c:
  ppuVar5 = (uint **)param_5[1];
  local_30 = (uint *)pfVar14;
  if (&local_30 < ppuVar5) {
    ppuVar6 = (uint **)*param_5;
    if (ppuVar6 <= &local_30) {
      if (ppuVar5 == (uint **)param_5[2]) {
        uVar13 = (int)ppuVar5 - (int)ppuVar6 >> 2;
        if (0x3ffffffe < uVar13) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long",uVar8);
        }
        uVar13 = uVar13 + 1;
        uVar8 = (int)param_5[2] - (int)ppuVar6 >> 2;
        if (uVar8 < uVar13) {
          if (0x3fffffff - (uVar8 >> 1) < uVar8) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar8 + (uVar8 >> 1);
          }
          if (uVar8 < uVar13) {
            uVar8 = uVar13;
          }
          FUN_00797980(uVar8);
        }
      }
      if ((undefined4 *)param_5[1] != (undefined4 *)0x0) {
        *(undefined4 *)param_5[1] =
             *(undefined4 *)(*param_5 + ((int)&local_30 - (int)ppuVar6 >> 2) * 4);
      }
      goto LAB_0084c807;
    }
  }
  if (ppuVar5 == (uint **)param_5[2]) {
    uVar13 = (int)((int)ppuVar5 - *param_5) >> 2;
    if (0x3ffffffe < uVar13) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long",uVar8);
    }
    uVar13 = uVar13 + 1;
    uVar8 = (int)((int)param_5[2] - *param_5) >> 2;
    if (uVar8 < uVar13) {
      if (0x3fffffff - (uVar8 >> 1) < uVar8) {
        uVar8 = 0;
      }
      else {
        uVar8 = uVar8 + (uVar8 >> 1);
      }
      if (uVar8 < uVar13) {
        uVar8 = uVar13;
      }
      FUN_00797980(uVar8);
    }
  }
  if ((uint *)param_5[1] != (uint *)0x0) {
    *(uint *)param_5[1] = (uint)pfVar14;
  }
LAB_0084c807:
  param_5[1] = param_5[1] + 4;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

