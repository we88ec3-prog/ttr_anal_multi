
void FUN_004a7f90(void)

{
  uint *puVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  bool bVar15;
  int *local_fc;
  int *piStack_f8;
  int *local_f4;
  int *local_f0;
  uint auStack_ec [5];
  undefined4 uStack_d8;
  uint uStack_d4;
  uint auStack_cc [4];
  undefined4 uStack_bc;
  uint uStack_b8;
  undefined **local_b0 [19];
  uint local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925027;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_fc;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffef8;
  ExceptionList = &local_14;
  FUN_0072ee30(local_b0);
  local_c = 0;
  cVar3 = FUN_0072f110(0);
  if ((cVar3 == '\0') || (iVar5 = FUN_0072e2e0("FEUDWORLDLISTTABLE"), iVar5 == 0)) {
    local_b0[0] = TiXmlDocument::vftable;
    local_c = 0xffffffff;
    if (0xf < local_50) {
      local_c = 0xffffffff;
      local_b0[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_64);
    }
  }
  else {
    local_f4 = (int *)FUN_0072e360(uVar4);
    while (local_f4 != (int *)0x0) {
      local_fc = (int *)FUN_00891268(0x3c);
      piVar10 = local_f4;
      if (local_fc == (int *)0x0) {
        local_fc = (int *)0x0;
      }
      else {
        local_fc[8] = 7;
        local_fc[7] = 0;
        *(undefined2 *)(local_fc + 3) = 0;
        local_fc[0xb] = 0;
        local_fc[0xc] = 0;
        local_fc[0xd] = 0;
      }
      local_f0 = local_fc;
      piVar6 = (int *)FUN_0072e360();
      (**(code **)(*piVar10 + 0x14))();
      iVar5 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar5 == 0) {
LAB_004a8121:
        iVar5 = 0;
      }
      else {
        puVar7 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar7 = (undefined4 *)*puVar7;
        }
        if (puVar7 == (undefined4 *)0x0) goto LAB_004a8121;
        iVar5 = FUN_008917b4(puVar7);
      }
      piVar10 = local_fc;
      *local_fc = iVar5;
      iVar5 = (**(code **)(*piVar6 + 0x14))();
      piStack_f8 = (int *)(iVar5 + 0x44);
      iVar5 = FUN_007300a0("bindno");
      if (iVar5 == 0) {
LAB_004a8163:
        iVar5 = 0;
      }
      else {
        puVar7 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar7 = (undefined4 *)*puVar7;
        }
        if (puVar7 == (undefined4 *)0x0) goto LAB_004a8163;
        iVar5 = FUN_008917b4(puVar7);
      }
      uVar4 = DAT_00fb9390 & 1;
      piVar10[1] = iVar5;
      if (uVar4 == 0) {
        DAT_00fb9390 = DAT_00fb9390 | 1;
        local_c._0_1_ = 1;
        FUN_0044ad70();
        _atexit((_func_4879 *)&LAB_00bcd610);
        local_c = (uint)local_c._1_3_ << 8;
      }
      puVar7 = (undefined4 *)DAT_00fb9398[1];
      cVar3 = *(char *)((int)puVar7 + 0x15);
      puVar14 = puVar7;
      while (cVar3 == '\0') {
        if ((int)puVar14[3] < 5) {
          puVar14 = (undefined4 *)puVar14[2];
        }
        else {
          puVar14 = (undefined4 *)*puVar14;
        }
        cVar3 = *(char *)((int)puVar14 + 0x15);
      }
      puVar14 = DAT_00fb9398;
      if (*(char *)((int)puVar7 + 0x15) == '\0') {
        do {
          if ((int)puVar7[3] < 4) {
            puVar8 = (undefined4 *)puVar7[2];
          }
          else {
            puVar8 = (undefined4 *)*puVar7;
            puVar14 = puVar7;
          }
          puVar7 = puVar8;
        } while (*(char *)((int)puVar8 + 0x15) == '\0');
        if ((puVar14 == DAT_00fb9398) || (*piVar10 <= (int)(uint)*(byte *)(puVar14[4] + 1)))
        goto LAB_004a8201;
        *(undefined1 *)(piVar10 + 2) = 0;
      }
      else {
LAB_004a8201:
        iVar5 = FUN_007300a0("visible");
        if (iVar5 == 0) {
LAB_004a8237:
          bVar15 = false;
        }
        else {
          pcVar9 = (char *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            pcVar9 = *(char **)pcVar9;
          }
          if (pcVar9 == (char *)0x0) goto LAB_004a8237;
          iVar5 = __stricmp(pcVar9,"true");
          bVar15 = iVar5 == 0;
        }
        *(bool *)(piVar10 + 2) = bVar15;
      }
      iVar5 = FUN_007300a0(&DAT_00bed1dc);
      if (iVar5 == 0) {
LAB_004a826e:
        bVar15 = false;
      }
      else {
        pcVar9 = (char *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          pcVar9 = *(char **)pcVar9;
        }
        if (pcVar9 == (char *)0x0) goto LAB_004a826e;
        iVar5 = __stricmp(pcVar9,"true");
        bVar15 = iVar5 == 0;
      }
      *(bool *)((int)piVar10 + 9) = bVar15;
      iVar5 = FUN_007300a0("feudTownPicNum");
      if (iVar5 == 0) {
LAB_004a829b:
        iVar5 = 0;
      }
      else {
        puVar7 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar7 = (undefined4 *)*puVar7;
        }
        if (puVar7 == (undefined4 *)0x0) goto LAB_004a829b;
        iVar5 = FUN_008917b4(puVar7);
      }
      local_fc[10] = iVar5;
      piVar10 = (int *)FUN_0072e360();
      (**(code **)(*piVar10 + 0x14))();
      uStack_d4 = 0xf;
      uStack_d8 = 0;
      auStack_ec[1] = auStack_ec[1] & 0xffffff00;
      FUN_00402a70("explain",7);
      local_c._0_1_ = 4;
      FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 6;
      if (0xf < uStack_d4) {
        FUN_0089120c(auStack_ec[1]);
      }
      uStack_d4 = 0xf;
      uStack_d8 = 0;
      auStack_ec[1] = auStack_ec[1] & 0xffffff00;
      uVar11 = FUN_004028b0(auStack_cc);
      local_c._0_1_ = 7;
      FUN_00402800(uVar11);
      local_c = CONCAT31(local_c._1_3_,6);
      if (7 < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      piStack_f8 = (int *)FUN_0072e360();
      piVar10 = local_fc;
      for (; piStack_f8 != (int *)0x0; piStack_f8 = (int *)piStack_f8[0x10]) {
        iVar12 = (**(code **)(*piStack_f8 + 0x14))();
        for (iVar5 = *(int *)(iVar12 + 0x94); iVar5 != iVar12 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)
            ) {
          pcVar9 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            pcVar9 = *(char **)pcVar9;
          }
          iVar13 = __stricmp(pcVar9,"groupid");
          if (iVar13 == 0) {
            if (iVar5 != 0) {
              puVar7 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar7 = (undefined4 *)*puVar7;
              }
              if (puVar7 != (undefined4 *)0x0) {
                uVar4 = FUN_008917b4(puVar7);
                goto LAB_004a83d6;
              }
            }
            break;
          }
        }
        uVar4 = 0;
LAB_004a83d6:
        puVar1 = (uint *)piVar10[0xc];
        auStack_ec[0] = uVar4;
        if (auStack_ec < puVar1) {
          puVar2 = (uint *)piVar10[0xb];
          if (auStack_ec < puVar2) goto LAB_004a843c;
          if (puVar1 == (uint *)piVar10[0xd]) {
            FUN_006d6240();
          }
          if ((undefined4 *)piVar10[0xc] != (undefined4 *)0x0) {
            *(undefined4 *)piVar10[0xc] =
                 *(undefined4 *)(piVar10[0xb] + ((int)auStack_ec - (int)puVar2 >> 2) * 4);
          }
        }
        else {
LAB_004a843c:
          if (puVar1 == (uint *)piVar10[0xd]) {
            FUN_006d6240();
          }
          if ((uint *)piVar10[0xc] != (uint *)0x0) {
            *(uint *)piVar10[0xc] = uVar4;
          }
        }
        piVar10[0xc] = piVar10[0xc] + 4;
      }
      if ((&local_f0 < DAT_00fb7284) && (DAT_00fb7280 <= &local_f0)) {
        iVar5 = (int)&local_f0 - (int)DAT_00fb7280;
        if (DAT_00fb7284 == DAT_00fb7288) {
          FUN_004deab0();
        }
        if (DAT_00fb7284 != (int **)0x0) {
          *DAT_00fb7284 = DAT_00fb7280[iVar5 >> 2];
        }
      }
      else {
        if (DAT_00fb7284 == DAT_00fb7288) {
          FUN_004deab0();
        }
        if (DAT_00fb7284 != (int **)0x0) {
          *DAT_00fb7284 = local_fc;
        }
      }
      DAT_00fb7284 = DAT_00fb7284 + 1;
      local_c = local_c & 0xffffff00;
      if (0xf < uStack_b8) {
        FUN_0089120c(auStack_cc[0]);
      }
      local_f4 = (int *)local_f4[0x10];
      uStack_b8 = 0xf;
      uStack_bc = 0;
      auStack_cc[0] = auStack_cc[0] & 0xffffff00;
    }
    FUN_004a85b0();
    local_c = 0xffffffff;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64);
    }
  }
  local_54 = 0;
  local_64 = local_64 & 0xffffff00;
  local_50 = 0xf;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_fc);
  return;
}

