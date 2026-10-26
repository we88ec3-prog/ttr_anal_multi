
void FUN_0073e670(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char ****ppppcVar5;
  int iVar6;
  undefined4 ****ppppuVar7;
  undefined4 uVar8;
  int in_ECX;
  char *in_EDX;
  char ****ppppcVar9;
  int *unaff_FS_OFFSET;
  wchar_t *local_108;
  char local_101;
  undefined2 local_100 [8];
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e4;
  undefined2 local_e0;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined2 local_c4;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined2 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  uint local_88;
  undefined4 local_78;
  uint local_74;
  undefined4 ***local_6c [4];
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  char ***local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  int local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091f23e;
  local_10 = *unaff_FS_OFFSET;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_ec = 7;
  local_f0 = 0;
  local_100[0] = 0;
  local_e4 = 0;
  local_cc = 7;
  local_d0 = 0;
  local_e0 = 0;
  local_b0 = 7;
  local_b4 = 0;
  local_c4 = 0;
  local_94 = 7;
  local_98 = 0;
  local_a8 = 0;
  local_8 = 0;
  local_101 = '\0';
  local_108 = L"Bold";
  if (param_3 != 1) {
    local_108 = L"Regular";
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_18 = uVar2;
  FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  local_8._0_1_ = 1;
  puVar4 = (undefined4 *)FUN_004028b0(local_34,uVar2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (7 < (uint)puVar4[5]) {
    puVar4 = (undefined4 *)*puVar4;
  }
  cVar1 = FUN_00741320(puVar4,local_108,local_100,&local_101);
  if (7 < local_74) {
    FUN_0089120c(local_88);
  }
  local_8 = local_8 & 0xffffff00;
  local_74 = 7;
  local_78 = 0;
  local_88 = local_88 & 0xffff0000;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  if (cVar1 == '\0') {
    FUN_0073e5e0();
  }
  else {
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
    local_8._0_1_ = 3;
    FUN_00429710();
    local_8 = CONCAT31(local_8._1_3_,4);
    ppppcVar9 = (char ****)local_34[0];
    if (local_20 < 0x10) {
      ppppcVar9 = local_34;
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffffff00);
    ppppcVar5 = ppppcVar9;
    do {
      cVar1 = *(char *)ppppcVar5;
      ppppcVar5 = (char ****)((int)ppppcVar5 + 1);
    } while (cVar1 != '\0');
    FUN_00402a70(ppppcVar9,(int)ppppcVar5 - (int)((int)ppppcVar9 + 1));
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
    local_8._0_1_ = 7;
    FUN_00429710();
    local_8._0_1_ = 8;
    ppppcVar9 = (char ****)local_34[0];
    if (local_20 < 0x10) {
      ppppcVar9 = local_34;
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50 = local_50 & 0xffffff00;
    ppppcVar5 = ppppcVar9;
    do {
      cVar1 = *(char *)ppppcVar5;
      ppppcVar5 = (char ****)((int)ppppcVar5 + 1);
    } while (cVar1 != '\0');
    FUN_00402a70(ppppcVar9,(int)ppppcVar5 - (int)((int)ppppcVar9 + 1));
    local_8 = CONCAT31(local_8._1_3_,10);
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
    if (local_101 != '\0') {
      iVar6 = FUN_0044df20(0,L"Bold",4);
      param_3 = (uint)(iVar6 == 0);
    }
    iVar6 = FUN_0073e260(in_ECX,param_1,param_2,param_3);
    if (iVar6 == 0) {
      iVar6 = FUN_00891268(100);
      if (iVar6 != 0) {
        FUN_00742e20();
      }
      ppppuVar7 = (undefined4 ****)local_6c[0];
      if (local_58 < 0x10) {
        ppppuVar7 = local_6c;
      }
      FUN_00742e60(ppppuVar7,local_e4,param_1,param_2);
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
      uVar8 = FUN_0057ef20();
      FUN_0057e850(in_ECX + 0x18,uVar8);
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      if (0xf < local_58) {
        FUN_0089120c(local_6c[0]);
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffffff00);
      FUN_0073e5e0();
    }
    else {
      puVar4 = (undefined4 *)FUN_004c2880();
      (*(code *)**(undefined4 **)*puVar4)();
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      local_3c = 0xf;
      local_40 = 0;
      local_50 = local_50 & 0xffffff00;
      if (0xf < local_58) {
        FUN_0089120c(local_6c[0]);
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c[0] = (undefined4 ***)((uint)local_6c[0] & 0xffffff00);
      FUN_0073e5e0();
    }
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

