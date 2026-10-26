
void FUN_0053e800(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  char *in_ECX;
  int local_b8;
  undefined **local_b0 [17];
  char local_6c;
  uint local_64;
  undefined4 local_54;
  uint local_50;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923243;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffffff00;
  local_18 = uVar4;
  FUN_00402a70("Field/MapFlow/",0xe);
  local_8 = 0;
  pcVar5 = in_ECX;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_ECX,(int)pcVar5 - (int)(in_ECX + 1));
  FUN_0072ef00(local_b0,local_34);
  local_8._0_1_ = 1;
  FUN_0072f110(0);
  if (local_6c == '\0') {
    iVar6 = FUN_0072e2e0("MAPCHART");
    if (iVar6 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      FUN_0072e040();
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      goto LAB_0053eb73;
    }
    iVar6 = FUN_0072e2e0("NodeList");
    if (iVar6 != 0) {
      piVar7 = (int *)FUN_0072e2e0(&DAT_00c0f444);
      while (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 0x14))();
        iVar6 = FUN_007300a0("arrayx");
        if (iVar6 == 0) {
LAB_0053e9e1:
          local_b8 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_0053e9e1;
          local_b8 = FUN_008917b4(puVar8);
        }
        iVar6 = FUN_007300a0("arrayy");
        if (iVar6 == 0) {
LAB_0053ea1a:
          iVar6 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_0053ea1a;
          iVar6 = FUN_008917b4(puVar8);
        }
        piVar7 = (int *)((local_b8 * 7 + 1 + iVar6) * 0x10 + param_1);
        iVar9 = FUN_007300a0(&DAT_00bed1d0);
        if (iVar9 == 0) {
LAB_0053ea5a:
          uVar3 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar9 + 0x30);
          if (0xf < *(uint *)(iVar9 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_0053ea5a;
          uVar3 = FUN_008917b4(puVar8);
        }
        *(undefined2 *)(piVar7 + 2) = uVar3;
        iVar9 = FUN_007300a0(&DAT_00bfb808);
        if (iVar9 == 0) {
LAB_0053ea88:
          uVar2 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar9 + 0x30);
          if (0xf < *(uint *)(iVar9 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_0053ea88;
          uVar2 = FUN_008917b4(puVar8);
        }
        *(undefined1 *)((int)piVar7 + 10) = uVar2;
        iVar9 = FUN_007300a0(&DAT_00c0f45c);
        if (iVar9 == 0) {
LAB_0053eab5:
          uVar2 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar9 + 0x30);
          if (0xf < *(uint *)(iVar9 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_0053eab5;
          uVar2 = FUN_008917b4(puVar8);
        }
        *(undefined1 *)((int)piVar7 + 0xb) = uVar2;
        iVar9 = FUN_007300a0("rotate");
        if (iVar9 == 0) {
LAB_0053eae2:
          uVar2 = 0;
        }
        else {
          puVar8 = (undefined4 *)(iVar9 + 0x30);
          if (0xf < *(uint *)(iVar9 + 0x44)) {
            puVar8 = (undefined4 *)*puVar8;
          }
          if (puVar8 == (undefined4 *)0x0) goto LAB_0053eae2;
          uVar2 = FUN_008917b4(puVar8);
        }
        *(undefined1 *)(piVar7 + 3) = uVar2;
        *piVar7 = local_b8;
        piVar7[1] = iVar6;
        FUN_0053eba0();
        piVar7 = (int *)FUN_0072e320(&DAT_00c0f444);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      local_b0[0] = TiXmlDocument::vftable;
      if (0xf < local_50) {
        FUN_0089120c(local_64);
      }
      local_50 = 0xf;
      local_54 = 0;
      local_64 = local_64 & 0xffffff00;
      FUN_0072e040();
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      goto LAB_0053eb73;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00407fb0();
  }
  else {
    local_8 = (uint)local_8._1_3_ << 8;
    local_b0[0] = TiXmlDocument::vftable;
    if (0xf < local_50) {
      FUN_0089120c(local_64,uVar4);
    }
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    FUN_0072e040();
  }
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
LAB_0053eb73:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

