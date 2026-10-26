
void FUN_007e2130(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *in_ECX;
  undefined1 local_90 [4];
  int local_8c;
  int local_88;
  int *local_84;
  uint local_80;
  undefined4 local_70;
  uint local_6c;
  uint local_64;
  uint local_60 [3];
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  undefined4 *local_48;
  uint local_44 [3];
  char *local_38;
  char *local_34;
  uint local_30;
  char local_28 [16];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a588;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_84 = param_1;
  local_30 = 0xf;
  local_34 = (char *)0x0;
  local_44[0] = local_44[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_18 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  piVar4 = local_84;
  local_8 = 0;
  local_88 = FUN_007b6f30(local_44);
  if (local_88 == piVar4[3]) {
LAB_007e21c7:
    local_8c = piVar4[3];
    piVar4 = &local_8c;
  }
  else {
    cVar1 = FUN_0049ae30(uVar2);
    if (cVar1 != '\0') goto LAB_007e21c7;
    piVar4 = &local_88;
  }
  iVar6 = *piVar4;
  local_8 = 0xffffffff;
  if (0xf < local_30) {
    FUN_0089120c(local_44[0]);
  }
  local_30 = 0xf;
  local_34 = (char *)0x0;
  local_44[0] = local_44[0] & 0xffffff00;
  if (iVar6 != local_84[3]) {
    piVar4 = *(int **)(iVar6 + 0x28);
    *piVar4 = *piVar4 + 1;
    goto LAB_007e2489;
  }
  puVar5 = (undefined4 *)FUN_00891268(8);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
  }
  *puVar5 = 1;
  local_38 = (char *)0x0;
  local_34 = (char *)0x0;
  local_30 = 0;
  local_8 = 1;
  local_4c = 0xf;
  local_50 = 0;
  local_60[0] = local_60[0] & 0xffffff00;
  FUN_00402a70(&DAT_00c504d0,1);
  local_8._0_1_ = 2;
  local_6c = 0xf;
  local_70 = 0;
  local_80 = local_80 & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_007da6b0(&local_38,local_60);
  if (0xf < local_6c) {
    FUN_0089120c(local_80);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  local_6c = 0xf;
  local_70 = 0;
  local_80 = local_80 & 0xffffff00;
  if (0xf < local_4c) {
    FUN_0089120c(local_60[0]);
  }
  if (local_38 == local_34) {
    if (local_38 == (char *)0x0) goto LAB_007e2489;
    FUN_00440a80();
    pcVar3 = local_38;
  }
  else {
    pcVar3 = local_38;
    if (0xf < *(uint *)(local_38 + 0x14)) {
      pcVar3 = *(char **)local_38;
    }
    __splitpath(pcVar3,(char *)0x0,(char *)0x0,(char *)0x0,local_28);
    iVar6 = __stricmp(local_28,".gb3");
    if (iVar6 == 0) {
LAB_007e23dc:
      iVar6 = FUN_00891268(0x40);
      if (iVar6 == 0) {
LAB_007e23f1:
        puVar7 = (undefined4 *)0x0;
      }
      else {
        puVar7 = (undefined4 *)FUN_007f5500();
      }
LAB_007e23f3:
      puVar5[1] = puVar7;
    }
    else {
      iVar6 = __stricmp(local_28,".3do");
      if (iVar6 == 0) goto LAB_007e23dc;
      iVar6 = __stricmp(local_28,".ptc");
      if (iVar6 == 0) {
        puVar7 = (undefined4 *)FUN_00891268(0x30);
        if (puVar7 == (undefined4 *)0x0) goto LAB_007e23f1;
        puVar7[6] = 0xf;
        puVar7[5] = 0;
        *(undefined1 *)(puVar7 + 1) = 0;
        puVar7[0xb] = 0x3eb33333;
        puVar7[8] = 0;
        puVar7[9] = 1;
        puVar7[10] = 0;
        *puVar7 = IS3D::CFieldObjectCacheParticle::vftable;
        goto LAB_007e23f3;
      }
      iVar6 = __stricmp(local_28,".eff");
      if (iVar6 == 0) {
        puVar7 = (undefined4 *)FUN_00891268(0x34);
        if (puVar7 == (undefined4 *)0x0) goto LAB_007e23f1;
        puVar7[6] = 0xf;
        puVar7[5] = 0;
        *(undefined1 *)(puVar7 + 1) = 0;
        puVar7[0xb] = 0x3eb33333;
        puVar7[8] = 0;
        puVar7[9] = 1;
        puVar7[10] = 0;
        *puVar7 = IS3D::CFieldObjectCacheEffect::vftable;
        puVar7[0xc] = 0;
        goto LAB_007e23f3;
      }
    }
    (**(code **)(*(int *)puVar5[1] + 8))();
    local_50 = 0xf;
    local_54 = 0;
    local_64 = local_64 & 0xffffff00;
    pcVar3 = in_ECX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
    piVar4 = local_84 + 2;
    local_8._0_1_ = 4;
    local_48 = puVar5;
    uVar8 = FUN_00552de0(&local_64);
    FUN_007e2910(piVar4,local_90,uVar8);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (0xf < local_50) {
      FUN_0089120c(local_64);
    }
    if (0 < *local_84) {
      (**(code **)(*(int *)puVar5[1] + 0xc))();
    }
    pcVar3 = local_38;
    FUN_00440a80();
  }
  FUN_0089120c(pcVar3);
LAB_007e2489:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

