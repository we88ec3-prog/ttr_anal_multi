
/* WARNING: Type propagation algorithm not settling */

void FUN_00474740(uint *param_1)

{
  undefined ***pppuVar1;
  undefined ***pppuVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined **ppuVar9;
  int *piVar10;
  undefined **local_94 [20];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925deb;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar4;
  FUN_0072ee30(local_94 + 1);
  local_8 = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 == '\0') {
    local_8 = 0xffffffff;
    local_94[1] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
  }
  else {
    iVar5 = FUN_0072e2e0("CAMERAMOVEPOSITION");
    if (iVar5 != 0) {
      for (piVar6 = (int *)FUN_0072e360(uVar4); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x10])
      {
        (**(code **)(*piVar6 + 0x14))();
        iVar5 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar5 == 0) {
LAB_0047486d:
          puVar8 = (undefined *)0x0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0047486d;
          puVar8 = (undefined *)FUN_008917b4(puVar7);
        }
        ppuVar9 = (undefined **)FUN_00891268(0x10);
        if (ppuVar9 == (undefined **)0x0) {
          ppuVar9 = (undefined **)0x0;
        }
        else {
          *ppuVar9 = (undefined *)0x0;
          ppuVar9[1] = (undefined *)0x0;
          ppuVar9[2] = (undefined *)0x0;
          ppuVar9[3] = (undefined *)0x0;
        }
        *ppuVar9 = puVar8;
        local_94[0] = ppuVar9;
        piVar10 = (int *)FUN_0072e360();
        (**(code **)(*piVar10 + 0x14))();
        iVar5 = FUN_007300a0("EndPosX");
        if (iVar5 == 0) {
LAB_004748dc:
          iVar5 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_004748dc;
          iVar5 = FUN_008917b4(puVar7);
        }
        ppuVar9[1] = (undefined *)(float)iVar5;
        iVar5 = FUN_007300a0("EndPosY");
        if (iVar5 == 0) {
LAB_00474912:
          iVar5 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_00474912;
          iVar5 = FUN_008917b4(puVar7);
        }
        ppuVar9[2] = (undefined *)(float)iVar5;
        iVar5 = FUN_007300a0("EndPosZ");
        if (iVar5 == 0) {
LAB_00474948:
          iVar5 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_00474948;
          iVar5 = FUN_008917b4(puVar7);
        }
        ppuVar9[3] = (undefined *)(float)iVar5;
        pppuVar1 = (undefined ***)param_1[1];
        if (local_94 < pppuVar1) {
          pppuVar2 = (undefined ***)*param_1;
          if (local_94 < pppuVar2) goto LAB_0047499a;
          if (pppuVar1 == (undefined ***)param_1[2]) {
            FUN_004deab0();
          }
          if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
            *(undefined4 *)param_1[1] =
                 *(undefined4 *)(*param_1 + ((int)local_94 - (int)pppuVar2 >> 2) * 4);
          }
        }
        else {
LAB_0047499a:
          if (pppuVar1 == (undefined ***)param_1[2]) {
            FUN_004deab0();
          }
          if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
            *(undefined4 *)param_1[1] = ppuVar9;
          }
        }
        param_1[1] = param_1[1] + 4;
        ppuVar9 = (undefined **)FUN_00891268(0x10);
        if (ppuVar9 == (undefined **)0x0) {
          ppuVar9 = (undefined **)0x0;
        }
        else {
          *ppuVar9 = (undefined *)0x0;
          ppuVar9[1] = (undefined *)0x0;
          ppuVar9[2] = (undefined *)0x0;
          ppuVar9[3] = (undefined *)0x0;
        }
        *ppuVar9 = puVar8;
        local_94[0] = ppuVar9;
        piVar10 = (int *)FUN_0072e360();
        (**(code **)(*piVar10 + 0x14))();
        iVar5 = FUN_007300a0("EndPosX");
        if (iVar5 == 0) {
LAB_00474a24:
          iVar5 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_00474a24;
          iVar5 = FUN_008917b4(puVar7);
        }
        ppuVar9[1] = (undefined *)(float)iVar5;
        iVar5 = FUN_007300a0("EndPosY");
        if (iVar5 == 0) {
LAB_00474a59:
          iVar5 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_00474a59;
          iVar5 = FUN_008917b4(puVar7);
        }
        ppuVar9[2] = (undefined *)(float)iVar5;
        iVar5 = FUN_007300a0("EndPosZ");
        if (iVar5 == 0) {
LAB_00474a8e:
          iVar5 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_00474a8e;
          iVar5 = FUN_008917b4(puVar7);
        }
        ppuVar9[3] = (undefined *)(float)iVar5;
        pppuVar1 = (undefined ***)param_1[5];
        if (local_94 < pppuVar1) {
          pppuVar2 = (undefined ***)param_1[4];
          if (local_94 < pppuVar2) goto LAB_00474ae3;
          if (pppuVar1 == (undefined ***)param_1[6]) {
            FUN_004deab0();
          }
          if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
            *(undefined4 *)param_1[5] =
                 *(undefined4 *)(param_1[4] + ((int)local_94 - (int)pppuVar2 >> 2) * 4);
          }
        }
        else {
LAB_00474ae3:
          if (pppuVar1 == (undefined ***)param_1[6]) {
            FUN_004deab0();
          }
          if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
            *(undefined4 *)param_1[5] = ppuVar9;
          }
        }
        param_1[5] = param_1[5] + 4;
      }
      local_8 = 0xffffffff;
      local_94[1] = TiXmlDocument::vftable;
      if (0xf < local_30) {
        FUN_0089120c(local_44);
      }
      local_44 = local_44 & 0xffffff00;
      goto LAB_00474b42;
    }
    local_8 = 0xffffffff;
    local_94[1] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
      local_44 = local_44 & 0xffffff00;
      goto LAB_00474b42;
    }
  }
  local_44 = local_44 & 0xffffff00;
LAB_00474b42:
  local_34 = 0;
  local_30 = 0xf;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

