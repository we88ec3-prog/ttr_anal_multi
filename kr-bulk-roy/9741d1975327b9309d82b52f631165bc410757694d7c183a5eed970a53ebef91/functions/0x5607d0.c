
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005607d0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_ec [4];
  int *local_e8;
  undefined4 uStack_e4;
  undefined1 auStack_e0 [8];
  uint auStack_d8 [4];
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
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
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00922f71;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_ec;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff08;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    FUN_00565a90(*(undefined4 *)(DAT_00fb73cc + 4));
    *(int *)(DAT_00fb73cc + 4) = DAT_00fb73cc;
    *(int *)DAT_00fb73cc = DAT_00fb73cc;
    *(int *)(DAT_00fb73cc + 8) = DAT_00fb73cc;
    _DAT_00fb73d0 = 0;
    iVar3 = FUN_0072e2e0("SCENESET");
    if (iVar3 != 0) {
      for (piVar4 = (int *)FUN_0072e2e0("SCENE"); local_e8 = piVar4, piVar4 != (int *)0x0;
          piVar4 = (int *)piVar4[0x10]) {
        iVar3 = (**(code **)(*piVar4 + 0x14))();
        if (iVar3 != 0) {
          uStack_c4 = 0xf;
          uStack_c8 = 0;
          auStack_d8[0] = auStack_d8[0] & 0xffffff00;
          local_c = CONCAT31(local_c._1_3_,1);
          iVar3 = FUN_007300a0("questIdx");
          if (iVar3 == 0) {
LAB_0056090d:
            uStack_e4 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_0056090d;
            uStack_e4 = FUN_008917b4(puVar5);
          }
          iVar3 = FUN_007300a0("sceneIdx");
          if (iVar3 == 0) {
LAB_0056093b:
            uVar6 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_0056093b;
            uVar6 = FUN_008917b4(puVar5);
          }
          iVar3 = FUN_007300a0("funcName");
          if (iVar3 == 0) {
            pcVar8 = (char *)0x0;
          }
          else {
            pcVar8 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar8 = *(char **)pcVar8;
            }
          }
          pcVar7 = pcVar8;
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar8,(int)pcVar7 - (int)(pcVar8 + 1));
          uStack_bc = uStack_e4;
          uStack_a0 = 0xf;
          uStack_a4 = 0;
          uStack_b4 = uStack_b4 & 0xffffff00;
          uStack_b8 = uVar6;
          FUN_00403040(auStack_d8,0,0xffffffff);
          local_c = CONCAT31(local_c._1_3_,2);
          FUN_00568950(&DAT_00fb73c8);
          FUN_00568680(&DAT_00fb73c8,auStack_e0);
          if (0xf < uStack_a0) {
            FUN_0089120c(uStack_b4);
          }
          local_c = local_c & 0xffffff00;
          uStack_a0 = 0xf;
          uStack_a4 = 0;
          uStack_b4 = uStack_b4 & 0xffffff00;
          if (0xf < uStack_c4) {
            FUN_0089120c(auStack_d8[0]);
          }
          uStack_c4 = 0xf;
          uStack_c8 = 0;
          auStack_d8[0] = auStack_d8[0] & 0xffffff00;
          piVar4 = local_e8;
        }
      }
    }
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
  __security_check_cookie(local_1c ^ (uint)auStack_ec);
  return;
}

