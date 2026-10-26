
void FUN_0056bf40(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 auStack_dc [4];
  undefined1 auStack_d8 [8];
  undefined4 uStack_d0;
  uint uStack_cc;
  undefined4 uStack_bc;
  uint uStack_b8;
  undefined **local_b0 [19];
  uint local_64;
  undefined4 uStack_54;
  uint local_50;
  undefined1 auStack_38 [28];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00922eae;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_dc;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff18;
  ExceptionList = &local_14;
  FUN_0072ee30(local_b0);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if ((((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("QuestCameraWorks"), iVar3 != 0)) &&
      (piVar4 = (int *)FUN_0072e2e0(&DAT_00c0d83c), piVar4 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*piVar4 + 0x14))(uVar2), iVar3 != 0)) {
    uVar5 = FUN_0072e650(0);
    iVar3 = FUN_007300a0("fileName");
    if (iVar3 == 0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = (undefined4 *)(iVar3 + 0x30);
      if (0xf < *(uint *)(iVar3 + 0x44)) {
        puVar6 = (undefined4 *)*puVar6;
      }
    }
    FUN_00402b70(puVar6);
    local_c._0_1_ = 1;
    uStack_b8 = 0xf;
    uStack_bc = 0;
    uStack_cc = uStack_cc & 0xffffff00;
    uStack_d0 = uVar5;
    FUN_00403040(auStack_38,0,0xffffffff);
    local_c = CONCAT31(local_c._1_3_,2);
    FUN_0056c490();
    FUN_0056c1b0(auStack_d8);
    if (0xf < uStack_b8) {
      FUN_0089120c(uStack_cc);
    }
    uStack_b8 = 0xf;
    uStack_bc = 0;
    uStack_cc = uStack_cc & 0xffffff00;
    FUN_00402c50();
  }
  local_c = 0xffffffff;
  local_b0[0] = TiXmlDocument::vftable;
  if (0xf < local_50) {
    FUN_0089120c(local_64);
  }
  local_50 = 0xf;
  uStack_54 = 0;
  local_64 = local_64 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_dc);
  return;
}

