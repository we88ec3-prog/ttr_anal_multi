
void FUN_004a8c20(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *_Str1;
  int in_ECX;
  double dVar8;
  undefined1 auStack_134 [4];
  float fStack_130;
  int *local_12c;
  undefined4 uStack_128;
  int local_124;
  undefined2 uStack_118;
  undefined2 uStack_116;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  uint uStack_108;
  uint local_104 [4];
  undefined4 local_f4;
  uint local_f0;
  uint uStack_e8;
  undefined2 uStack_e4;
  undefined2 uStack_e2;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  undefined4 uStack_c0;
  uint uStack_bc;
  uint uStack_b4;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00924fb7;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_134;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffec0;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("TutCheckPointList"), iVar3 != 0)) {
    local_f0 = 0xf;
    local_f4 = 0;
    local_104[0] = local_104[0] & 0xffffff00;
    local_c = CONCAT31(local_c._1_3_,1);
    piVar4 = (int *)FUN_0072e2e0("CheckPoint");
    local_12c = piVar4;
    if (piVar4 != (int *)0x0) {
      local_124 = in_ECX + 0x24;
      do {
        local_12c = piVar4;
        uStack_128 = (**(code **)(*piVar4 + 0x14))();
        iVar3 = FUN_007300a0(&DAT_00bed1d0);
        if (iVar3 == 0) {
LAB_004a8d35:
          uStack_116 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_004a8d35;
          uStack_116 = FUN_008917b4(puVar5);
        }
        iVar3 = FUN_007300a0("category");
        if (iVar3 == 0) {
LAB_004a8d63:
          uStack_118 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_004a8d63;
          uStack_118 = FUN_008917b4(puVar5);
        }
        iVar3 = FUN_007300a0(&DAT_00c06928);
        if (iVar3 == 0) {
LAB_004a8d9b:
          fStack_114 = 0.0;
        }
        else {
          pcVar6 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
          if (pcVar6 == (char *)0x0) goto LAB_004a8d9b;
          dVar8 = _atof(pcVar6);
          fStack_114 = (float)dVar8;
          fStack_130 = fStack_114;
        }
        iVar3 = FUN_007300a0(&DAT_00c0692c);
        if (iVar3 == 0) {
LAB_004a8dd5:
          fStack_110 = 0.0;
        }
        else {
          pcVar6 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
          if (pcVar6 == (char *)0x0) goto LAB_004a8dd5;
          dVar8 = _atof(pcVar6);
          fStack_110 = (float)dVar8;
          fStack_130 = fStack_110;
        }
        iVar3 = FUN_007300a0("range");
        if (iVar3 == 0) {
LAB_004a8e0f:
          fStack_10c = 0.0;
        }
        else {
          pcVar6 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
          if (pcVar6 == (char *)0x0) goto LAB_004a8e0f;
          dVar8 = _atof(pcVar6);
          fStack_10c = (float)dVar8;
          fStack_130 = fStack_10c;
        }
        iVar3 = FUN_007300a0("active");
        if (iVar3 == 0) {
LAB_004a8e3f:
          uStack_108 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_004a8e3f;
          uStack_108 = FUN_008917b4(puVar5);
        }
        uStack_a0 = 0xf;
        uStack_a4 = 0;
        uStack_b4 = uStack_b4 & 0xffffff00;
        FUN_00402a70("effect",6);
        local_c._0_1_ = 2;
        uVar7 = FUN_0072ecf0(&DAT_00bf2375);
        local_c = CONCAT31(local_c._1_3_,3);
        FUN_00402bb0(uVar7);
        if (0xf < uStack_d4) {
          FUN_0089120c(uStack_e8);
        }
        local_c._0_1_ = 1;
        uStack_d4 = 0xf;
        fStack_d8 = 0.0;
        uStack_e8 = uStack_e8 & 0xffffff00;
        if (0xf < uStack_a0) {
          FUN_0089120c(uStack_b4);
        }
        uStack_e4 = uStack_118;
        fStack_e0 = fStack_114;
        uStack_e8 = CONCAT22(uStack_e8._2_2_,uStack_116);
        uStack_e2 = uStack_116;
        uStack_d4 = uStack_108;
        fStack_dc = fStack_110;
        fStack_d8 = fStack_10c;
        uStack_bc = 0xf;
        uStack_c0 = 0;
        uStack_d0 = uStack_d0 & 0xffffff00;
        FUN_00403040(local_104,0,0xffffffff);
        iVar3 = local_124;
        local_c._0_1_ = 4;
        uVar7 = FUN_004abe00(&uStack_e8);
        FUN_004abb10(iVar3,uVar7);
        local_c = CONCAT31(local_c._1_3_,1);
        if (0xf < uStack_bc) {
          FUN_0089120c(uStack_d0);
        }
        piVar4 = (int *)local_12c[0x10];
        uStack_bc = 0xf;
        uStack_c0 = 0;
        uStack_d0 = uStack_d0 & 0xffffff00;
        for (; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x10]) {
          _Str1 = piVar4 + 8;
          if (0xf < (uint)piVar4[0xd]) {
            _Str1 = (int *)*_Str1;
          }
          iVar3 = __stricmp((char *)_Str1,"CheckPoint");
          if (iVar3 == 0) goto LAB_004a8fd9;
        }
        piVar4 = (int *)0x0;
LAB_004a8fd9:
        local_12c = piVar4;
      } while (piVar4 != (int *)0x0);
    }
    if (0xf < local_f0) {
      FUN_0089120c(local_104[0]);
    }
    local_f0 = 0xf;
    local_f4 = 0;
    local_104[0] = local_104[0] & 0xffffff00;
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c,uVar2);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_134);
  return;
}

