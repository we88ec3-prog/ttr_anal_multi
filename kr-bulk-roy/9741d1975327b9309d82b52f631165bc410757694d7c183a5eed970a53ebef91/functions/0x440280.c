
void FUN_00440280(char *param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  DWORD DVar5;
  byte ****ppppbVar6;
  byte *pbVar7;
  int iVar8;
  bool bVar9;
  int local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_60;
  uint local_5c;
  byte ***local_54 [4];
  undefined4 local_44;
  uint local_40;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  puStack_10 = &LAB_0092a228;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_84;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  if (param_1 == (char *)0x0) goto LAB_00440598;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_c = 0;
  local_24 = 0xf;
  local_28 = 0;
  local_38[0] = local_38[0] & 0xffffff00;
  FUN_00402a70(&DAT_00bfafb8,1);
  local_c._0_1_ = 1;
  local_5c = 0xf;
  local_60 = 0;
  local_70 = local_70 & 0xffffff00;
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_1,(int)pcVar4 - (int)(param_1 + 1));
  local_c = CONCAT31(local_c._1_3_,2);
  FUN_00440d30(&local_80,local_38,uVar3);
  if (0xf < local_5c) {
    FUN_0089120c(local_70);
  }
  local_5c = 0xf;
  local_60 = 0;
  local_70 = local_70 & 0xffffff00;
  if (0xf < local_24) {
    FUN_0089120c(local_38[0]);
  }
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_c._0_1_ = 3;
  uVar3 = local_70;
  for (iVar8 = (local_7c - local_80) / 0x1c; local_70 = uVar3, iVar8 != 0; iVar8 = iVar8 + -1) {
    local_24 = 0xf;
    local_28 = 0;
    local_38[0] = local_38[0] & 0xffffff00;
    FUN_00402a70(&DAT_00bfafbc,1);
    local_c._0_1_ = 4;
    FUN_00440d30(&local_70,local_38);
    local_c._0_1_ = 3;
    if (0xf < local_24) {
      FUN_0089120c(local_38[0]);
    }
    uVar3 = local_70;
  }
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = (byte ***)((uint)local_54[0] & 0xffffff00);
  FUN_00403040(uVar3,0,0xffffffff);
  DVar5 = GetFileAttributesA("serverIp.ini");
  if (DVar5 == 0xffffffff) {
LAB_004404a0:
    ppppbVar6 = (byte ****)local_54[0];
    if (local_40 < 0x10) {
      ppppbVar6 = local_54;
    }
    pbVar7 = &DAT_00bf2375;
    do {
      bVar2 = *(byte *)ppppbVar6;
      bVar9 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
LAB_004404d2:
        iVar8 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_004404d7;
      }
      if (bVar2 == 0) break;
      bVar2 = *(byte *)((int)ppppbVar6 + 1);
      bVar9 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_004404d2;
      ppppbVar6 = (byte ****)((int)ppppbVar6 + 2);
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_004404d7:
    if (iVar8 == 0) {
      *(undefined4 *)(local_84 + 8) = 0x52;
      goto LAB_00440534;
    }
    ppppbVar6 = (byte ****)local_54[0];
    if (local_40 < 0x10) {
      ppppbVar6 = local_54;
    }
    pbVar7 = &DAT_00bfafd8;
    do {
      bVar2 = *(byte *)ppppbVar6;
      bVar9 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
LAB_00440520:
        iVar8 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_00440525;
      }
      if (bVar2 == 0) break;
      bVar2 = *(byte *)((int)ppppbVar6 + 1);
      bVar9 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_00440520;
      ppppbVar6 = (byte ****)((int)ppppbVar6 + 2);
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_00440525:
    if (iVar8 == 0) {
      *(undefined4 *)(local_84 + 8) = 0x54;
      goto LAB_00440534;
    }
  }
  else {
    ppppbVar6 = (byte ****)local_54[0];
    if (local_40 < 0x10) {
      ppppbVar6 = local_54;
    }
    pbVar7 = &DAT_00bfafd0;
    do {
      bVar2 = *(byte *)ppppbVar6;
      bVar9 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
LAB_00440487:
        iVar8 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_0044048c;
      }
      if (bVar2 == 0) break;
      bVar2 = *(byte *)((int)ppppbVar6 + 1);
      bVar9 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_00440487;
      ppppbVar6 = (byte ****)((int)ppppbVar6 + 2);
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar8 = 0;
LAB_0044048c:
    if (iVar8 != 0) goto LAB_004404a0;
    *(undefined4 *)(local_84 + 8) = 0x40;
LAB_00440534:
    *(undefined4 *)(local_84 + 0x28) = 1;
  }
  if (0xf < local_40) {
    FUN_0089120c(local_54[0]);
  }
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = (byte ***)((uint)local_54[0] & 0xffffff00);
  if (uVar3 != 0) {
    FUN_00440a80();
    FUN_0089120c(uVar3);
  }
  iVar8 = local_80;
  if (local_80 != 0) {
    FUN_00440a80();
    FUN_0089120c(iVar8);
  }
LAB_00440598:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_84);
  return;
}

