
/* WARNING: Type propagation algorithm not settling */

void FUN_0084e090(uint param_1,char param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  void *pvVar11;
  void *pvVar12;
  int in_ECX;
  int iVar13;
  uint *puVar14;
  int *in_EDX;
  uint uVar15;
  int *piVar16;
  uint *puVar17;
  int *local_d4;
  int local_d0;
  int local_cc;
  void *local_c8;
  uint local_c4 [2];
  int *local_bc;
  int local_b8;
  int *local_b4;
  int *local_b0;
  undefined1 local_ac [4];
  undefined4 local_a8 [4];
  undefined4 local_98 [3];
  uint local_8c [21];
  uint local_38 [8];
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009204f0;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar8 = in_EDX[1] - *in_EDX >> 0x1f;
  local_14 = uVar7;
  if (((((in_EDX[1] - *in_EDX) / 100 + iVar8 != iVar8) && (3 < param_1)) &&
      ((iVar13 = *(int *)(in_ECX + 0xc4) - *(int *)(in_ECX + 0xc0), iVar8 = iVar13 >> 0x1f,
       iVar13 / 0x24 + iVar8 == iVar8 ||
       ((*(int *)(in_ECX + 0x70) - *(int *)(in_ECX + 0x6c) & 0xfffffff0U) == 0)))) &&
     ((((*(uint *)(in_ECX + 0xbc) = param_1, *(int *)(in_ECX + 0x40) != 0 &&
        (*(int *)(in_ECX + 0x44) != 0)) &&
       (local_b8 = in_ECX, local_b0 = (int *)FUN_00857b00(0,0), -1 < (int)local_b0)) &&
      (iVar8 = FUN_0084e8f0(in_ECX), iVar8 != 0)))) {
    local_bc = *(int **)(in_ECX + 0x44);
    iVar8 = *local_bc;
    iVar13 = local_bc[1] - iVar8 >> 0x1f;
    local_d4 = (int *)0x0;
    if ((local_bc[1] - iVar8) / 0x14 + iVar13 != iVar13) {
      local_c8 = (void *)((int)local_b0 * 0xc);
      local_d0 = 0;
      do {
        piVar16 = local_bc;
        local_cc = *(int *)(iVar8 + 0x10 + local_d0);
        local_c4[0] = 2;
        puVar9 = local_a8;
        do {
          FUN_00443d70(8,&LAB_00848010);
          iVar8 = local_b8;
          puVar9[7] = 0;
          *puVar9 = 0;
          puVar9[2] = 0;
          puVar9[-1] = 0;
          puVar9[4] = 0;
          puVar9[1] = 0;
          puVar9[6] = 0;
          puVar9[3] = 0;
          puVar9[5] = 0;
          puVar9 = puVar9 + 9;
          local_c4[0] = local_c4[0] - 1;
        } while (-1 < (int)local_c4[0]);
        local_b0 = *(int **)(local_b8 + 0xc0);
        iVar13 = *(int *)(local_b8 + 0xc4);
        iVar3 = *piVar16;
        uVar15 = 0;
        puVar9 = local_98;
        do {
          uVar4 = *(uint *)(uVar15 + *(int *)(iVar3 + local_d0) + (int)local_c8);
          if ((uint)((iVar13 - (int)local_b0) / 0x24) <= uVar4) {
                    /* WARNING: Subroutine does not return */
            FUN_0087db7d("invalid vector<T> subscript");
          }
          puVar1 = (undefined4 *)((int)local_b0 + uVar4 * 0x24);
          puVar9[-5] = *puVar1;
          puVar9[-4] = puVar1[1];
          puVar9[-3] = puVar1[2];
          puVar9[-2] = puVar1[3];
          puVar9[-1] = puVar1[4];
          *puVar9 = puVar1[5];
          puVar9[1] = puVar1[6];
          puVar9[2] = puVar1[7];
          puVar9[3] = puVar1[8];
          uVar15 = uVar15 + 4;
          puVar9 = puVar9 + 9;
        } while (uVar15 < 0xc);
        uVar10 = FUN_0084c8e0(local_b8 + 0x6c,local_ac,&local_cc,&local_b4);
        piVar16 = (int *)(iVar8 + 0xac);
        local_cc = iVar8 + 0x8c;
        puVar17 = local_8c;
        local_b0 = (int *)0x3;
        local_b4 = piVar16;
        do {
          local_c4[0] = *puVar17;
          if ((param_2 == '\0') && (3 < (int)local_c4[0])) {
            local_c4[0] = 3;
          }
          uVar15 = 0;
          local_38[5] = 0;
          local_38[6] = 0;
          local_38[7] = 0;
          local_18 = (void *)0x0;
          local_38[0] = 0;
          local_38[1] = 0;
          local_38[2] = 0;
          local_38[3] = 0;
          if (local_c4[0] != 0) {
            puVar14 = puVar17 + -8;
            do {
              uVar4 = *puVar14;
              local_38[uVar15 + 5] = puVar14[1];
              local_38[uVar15] = uVar4;
              uVar15 = uVar15 + 1;
              puVar14 = puVar14 + 2;
              piVar16 = local_b4;
            } while (uVar15 < local_c4[0]);
          }
          if (param_2 == '\0') {
            FUN_0084c310(local_38 + 5,local_38,local_c4,iVar8 + 0x9c,piVar16);
          }
          else {
            FUN_0084be20(uVar10,local_38 + 5,local_38,local_c4,local_cc,iVar8 + 0x9c,piVar16);
          }
          puVar17 = puVar17 + 9;
          local_b0 = (int *)((int)local_b0 + -1);
        } while (local_b0 != (int *)0x0);
        local_b4 = local_d4;
        FUN_004a8680();
        local_d0 = local_d0 + 0x14;
        local_d4 = (int *)((int)local_d4 + 1);
        iVar8 = *local_bc;
        in_ECX = local_b8;
      } while (local_d4 < (int *)((local_bc[1] - iVar8) / 0x14));
    }
    local_b0 = *(int **)(in_ECX + 0x9c);
    pvVar11 = *(void **)(in_ECX + 0x40);
    iVar8 = (*(int *)(in_ECX + 0xa0) - (int)local_b0) / 0xc;
    local_bc = (int *)0x1;
    local_c8 = pvVar11;
    FUN_00835c70(&local_bc);
    piVar16 = local_b4;
    while (piVar16 != *(int **)((int)pvVar11 + 4)) {
      if ((piVar16[3] == 1) && (piVar16[5] == 0)) {
        if (piVar16[7] != 0) {
          FUN_00891d3d(piVar16[7],uVar7);
          piVar16[7] = 0;
        }
        piVar16[5] = 0;
        piVar16[4] = 2;
        piVar16[6] = iVar8;
        pvVar11 = (void *)FUN_0087dc3d(iVar8 * 0xc);
        piVar16[7] = (int)pvVar11;
        FID_conflict__memcpy(pvVar11,local_b0,iVar8 * 0xc);
        goto LAB_0084e577;
      }
      if (*(char *)((int)piVar16 + 0x21) == '\0') {
        piVar5 = (int *)piVar16[2];
        if (*(char *)((int)piVar5 + 0x21) == '\0') {
          cVar2 = *(char *)(*piVar5 + 0x21);
          piVar16 = piVar5;
          piVar5 = (int *)*piVar5;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar5 + 0x21);
            piVar16 = piVar5;
            piVar5 = (int *)*piVar5;
          }
        }
        else {
          cVar2 = *(char *)(piVar16[1] + 0x21);
          piVar6 = (int *)piVar16[1];
          piVar5 = piVar16;
          while ((piVar16 = piVar6, cVar2 == '\0' && (piVar5 == (int *)piVar16[2]))) {
            cVar2 = *(char *)(piVar16[1] + 0x21);
            piVar6 = (int *)piVar16[1];
            piVar5 = piVar16;
          }
        }
      }
    }
    pvVar11 = (void *)FUN_0087dc3d(iVar8 * 0xc);
    FID_conflict__memcpy(pvVar11,local_b0,iVar8 * 0xc);
    local_38[5] = 2;
    local_38[6] = 0;
    local_38[4] = 1;
    local_38[7] = iVar8;
    local_18 = pvVar11;
    uVar10 = FUN_0054f7d0();
    FUN_008575f0(local_c4 + 1,uVar10);
LAB_0084e577:
    if (param_2 != '\0') {
      pvVar11 = *(void **)(local_b8 + 0x8c);
      pvVar12 = *(void **)(local_b8 + 0x40);
      iVar8 = *(int *)(local_b8 + 0x90) - (int)pvVar11 >> 2;
      local_bc = (int *)0x2;
      local_c8 = pvVar11;
      local_b0 = pvVar12;
      FUN_00835c70(&local_bc);
      piVar16 = local_b4;
      while (piVar16 != *(int **)((int)pvVar12 + 4)) {
        if ((piVar16[3] == 2) && (piVar16[5] == 0)) {
          if (piVar16[7] != 0) {
            FUN_00891d3d(piVar16[7]);
            piVar16[7] = 0;
          }
          piVar16[5] = 0;
          piVar16[4] = 5;
          piVar16[6] = iVar8;
          pvVar12 = (void *)FUN_0087dc3d(iVar8 * 4);
          piVar16[7] = (int)pvVar12;
          FID_conflict__memcpy(pvVar12,pvVar11,iVar8 * 4);
          goto LAB_0084e6cc;
        }
        if (*(char *)((int)piVar16 + 0x21) == '\0') {
          piVar5 = (int *)piVar16[2];
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            cVar2 = *(char *)(*piVar5 + 0x21);
            piVar16 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*piVar5 + 0x21);
              piVar16 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar2 = *(char *)(piVar16[1] + 0x21);
            piVar6 = (int *)piVar16[1];
            piVar5 = piVar16;
            while ((piVar16 = piVar6, cVar2 == '\0' && (piVar5 == (int *)piVar16[2]))) {
              cVar2 = *(char *)(piVar16[1] + 0x21);
              piVar6 = (int *)piVar16[1];
              piVar5 = piVar16;
            }
          }
        }
      }
      pvVar11 = (void *)FUN_0087dc3d(iVar8 * 4);
      FID_conflict__memcpy(pvVar11,local_c8,iVar8 * 4);
      local_38[5] = 5;
      local_38[6] = 0;
      local_38[4] = 2;
      local_38[7] = iVar8;
      local_18 = pvVar11;
      uVar10 = FUN_0054f7d0();
      FUN_008575f0(local_c4 + 1,uVar10);
    }
LAB_0084e6cc:
    local_38[5] = 0;
    local_38[6] = 0;
    local_38[7] = 0;
    local_8 = 0;
    local_c4[1] = 1;
    local_bc = (int *)0x0;
    FUN_0079bea0();
    if (param_2 != '\0') {
      local_c4[1] = 2;
      local_bc = (int *)0x0;
      FUN_0079bea0();
    }
    FUN_00857800(*(undefined4 *)(local_b8 + 0x44),local_38 + 5,*(undefined4 *)(local_b8 + 0xac));
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    local_b4 = *(int **)(local_b8 + 0x80);
    local_b0 = (int *)*local_b4;
    if (local_b0 != local_b4) {
      do {
        local_bc = (int *)local_b0[5];
        piVar16 = (int *)*local_bc;
        if (piVar16 != local_bc) {
          do {
            uVar7 = 0;
            if (piVar16[6] - piVar16[5] >> 2 != 0) {
              do {
                FUN_0084fdf0();
                uVar7 = uVar7 + 1;
              } while (uVar7 < (uint)(piVar16[6] - piVar16[5] >> 2));
            }
            if (*(char *)((int)piVar16 + 0x35) == '\0') {
              piVar5 = (int *)piVar16[2];
              if (*(char *)((int)piVar5 + 0x35) == '\0') {
                cVar2 = *(char *)(*piVar5 + 0x35);
                piVar16 = piVar5;
                piVar5 = (int *)*piVar5;
                while (cVar2 == '\0') {
                  cVar2 = *(char *)(*piVar5 + 0x35);
                  piVar16 = piVar5;
                  piVar5 = (int *)*piVar5;
                }
              }
              else {
                cVar2 = *(char *)(piVar16[1] + 0x35);
                piVar6 = (int *)piVar16[1];
                piVar5 = piVar16;
                while ((piVar16 = piVar6, cVar2 == '\0' && (piVar5 == (int *)piVar16[2]))) {
                  cVar2 = *(char *)(piVar16[1] + 0x35);
                  piVar6 = (int *)piVar16[1];
                  piVar5 = piVar16;
                }
              }
            }
          } while (piVar16 != local_bc);
        }
        FUN_0085e240();
      } while (local_b0 != local_b4);
    }
    FUN_0084fca0(local_38);
    FUN_0084fc70();
    if (local_38[5] != 0) {
      FUN_0089120c(local_38[5]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

