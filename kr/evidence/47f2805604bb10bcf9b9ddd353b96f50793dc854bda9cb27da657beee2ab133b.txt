
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005038f0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined1 auStack_104 [4];
  int local_100;
  undefined4 local_fc;
  uint local_f0 [4];
  undefined4 local_e0;
  uint local_dc;
  uint uStack_d4;
  uint uStack_d0;
  undefined4 uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint local_b4 [4];
  undefined4 local_a4;
  uint local_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00924312;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_104;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffef0;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    FUN_004803c0(*(undefined4 *)(DAT_00fb119c + 4));
    *(int *)(DAT_00fb119c + 4) = DAT_00fb119c;
    *(int *)DAT_00fb119c = DAT_00fb119c;
    *(int *)(DAT_00fb119c + 8) = DAT_00fb119c;
    _DAT_00fb11a0 = 0;
    iVar3 = FUN_0072e2e0("ScenarioBook");
    if (iVar3 != 0) {
      iVar4 = FUN_0072e360(uVar2);
      iVar3 = iVar4;
      while (local_100 = iVar3, iVar4 != 0) {
        iVar4 = FUN_007300a0(&DAT_00c071fc);
        if (iVar4 == 0) {
LAB_00503a0b:
          local_fc = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_00503a0b;
          local_fc = FUN_008917b4(puVar5);
        }
        local_a0 = 7;
        local_a4 = 0;
        local_b4[0] = local_b4[0] & 0xffff0000;
        local_c._0_1_ = 1;
        for (iVar3 = *(int *)(iVar3 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
          pcVar6 = (char *)(iVar3 + 0x20);
          if (0xf < *(uint *)(iVar3 + 0x34)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar4 = __stricmp(pcVar6,"Summary");
          if (iVar4 == 0) goto LAB_00503a56;
        }
        iVar3 = 0;
LAB_00503a56:
        if ((*(int **)(iVar3 + 0x18) != (int *)0x0) &&
           (iVar3 = (**(code **)(**(int **)(iVar3 + 0x18) + 0x2c))(), iVar3 != 0)) {
          pcVar6 = (char *)(iVar3 + 0x20);
          if (0xf < *(uint *)(iVar3 + 0x34)) {
            pcVar6 = *(char **)pcVar6;
          }
          local_dc = 0xf;
          local_e0 = 0;
          local_f0[0] = local_f0[0] & 0xffffff00;
          pcVar7 = pcVar6;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar6,(int)pcVar7 - (int)(pcVar6 + 1));
          local_c._0_1_ = 2;
          uVar8 = FUN_004028b0(local_f0);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_00402800(uVar8);
          if (7 < uStack_c0) {
            FUN_0089120c(uStack_d4);
          }
          local_c._0_1_ = 1;
          uStack_c0 = 7;
          uStack_c4 = 0;
          uStack_d4 = uStack_d4 & 0xffff0000;
          if (0xf < local_dc) {
            FUN_0089120c(local_f0[0]);
          }
        }
        local_dc = 7;
        local_e0 = 0;
        local_f0[0] = local_f0[0] & 0xffff0000;
        FUN_004026e0(local_b4,0,0xffffffff);
        local_c._0_1_ = 4;
        uStack_d4 = CONCAT22(uStack_d4._2_2_,(undefined2)local_fc);
        uStack_bc = 7;
        uStack_c0 = 0;
        uStack_d0 = uStack_d0 & 0xffff0000;
        FUN_004026e0(local_f0,0,0xffffffff);
        local_c = CONCAT31(local_c._1_3_,5);
        uVar8 = FUN_00504280(&uStack_d4);
        FUN_004808f0(&DAT_00fb1198,uVar8);
        if (7 < uStack_bc) {
          FUN_0089120c(uStack_d0);
        }
        local_c = CONCAT31(local_c._1_3_,1);
        uStack_bc = 7;
        uStack_c0 = 0;
        uStack_d0 = uStack_d0 & 0xffff0000;
        if (7 < local_dc) {
          FUN_0089120c(local_f0[0]);
        }
        local_dc = 7;
        local_e0 = 0;
        local_f0[0] = local_f0[0] & 0xffff0000;
        iVar4 = FUN_0072e3c0();
        local_100 = iVar4;
        if (7 < local_a0) {
          FUN_0089120c(local_b4[0]);
        }
        local_a0 = 7;
        local_a4 = 0;
        local_b4[0] = local_b4[0] & 0xffff0000;
        iVar3 = local_100;
      }
    }
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_104);
  return;
}

