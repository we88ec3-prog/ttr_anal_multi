
void FUN_00611540(undefined4 param_1,undefined1 param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  int in_ECX;
  short *psVar8;
  undefined1 auStack_9c [4];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined4 uStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_54;
  int iStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e331;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffff58;
  ExceptionList = &local_14;
  uVar2 = DAT_00fab22c & 1;
  local_94 = CONCAT31(local_94._1_3_,param_2);
  *(undefined1 *)(in_ECX + 0x160) = param_2;
  local_98 = param_1;
  *(undefined4 *)(in_ECX + 0x15c) = param_1;
  *(int *)(in_ECX + 0x164) = param_3;
  if (uVar2 == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar5);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar6 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  *(undefined1 *)(in_ECX + 0x161) = *(undefined1 *)(iVar6 + 0x88);
  FUN_006119c0();
  uVar3 = local_94;
  cVar4 = FUN_00612d60(in_ECX,param_1,local_94);
  if (cVar4 == '\0') {
    cVar4 = FUN_00612b80(in_ECX,uVar3);
    if (cVar4 == '\0') {
      *(undefined4 *)(*(int *)(in_ECX + 0x170) + 0x154) = 0xffff503c;
      goto LAB_0061163a;
    }
  }
  *(undefined4 *)(*(int *)(in_ECX + 0x170) + 0x154) = 0xffffc000;
LAB_0061163a:
  uStack_24 = 7;
  uStack_28 = 0;
  uStack_38 = (uint)uStack_38._2_2_ << 0x10;
  local_c = 1;
  FUN_00611b60(param_1,uVar3);
  FUN_00757710();
  uStack_40 = 7;
  iStack_44 = 0;
  uStack_54 = (uint)uStack_54._2_2_ << 0x10;
  local_c._0_1_ = 2;
  psVar7 = (short *)FUN_00611de0(local_98,local_94);
  uStack_70 = (uint)uStack_70._2_2_ << 0x10;
  uStack_5c = 7;
  uStack_60 = 0;
  psVar8 = psVar7;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
  local_c = CONCAT31(local_c._1_3_,3);
  if (iStack_44 != 0) {
    FUN_00404300(L"<br>",4);
  }
  psVar7 = (short *)FUN_00612190(local_98,local_94);
  psVar8 = psVar7;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
  if (iStack_44 != 0) {
    FUN_00404300(L"<br>",4);
  }
  if (param_3 != 0) {
    psVar7 = (short *)FUN_00612940(local_98,local_94);
    psVar8 = psVar7;
    do {
      sVar1 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
    if (iStack_44 != 0) {
      FUN_00404300(L"<br>",4);
    }
  }
  uVar3 = local_94;
  psVar7 = (short *)FUN_00611ee0(local_98,local_94);
  psVar8 = psVar7;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
  if (iStack_44 != 0) {
    FUN_00404300(L"<br>",4);
  }
  psVar7 = (short *)FUN_00612750(local_98,uVar3);
  psVar8 = psVar7;
  do {
    sVar1 = *psVar8;
    psVar8 = psVar8 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
  uStack_7c = 7;
  uStack_80 = 0;
  uStack_90 = (uint)uStack_90._2_2_ << 0x10;
  FUN_004026e0(&uStack_70,0,0xffffffff);
  iVar6 = *(int *)(in_ECX + 0x174);
  local_c = CONCAT31(local_c._1_3_,4);
  FUN_007578f0();
  FUN_00759ed0(iVar6 + 0xe8,&uStack_90,0x7b,0x7d);
  if (7 < uStack_7c) {
    FUN_0089120c(uStack_90);
  }
  if (7 < uStack_5c) {
    FUN_0089120c(uStack_70);
  }
  uStack_5c = 7;
  uStack_60 = 0;
  uStack_70 = uStack_70 & 0xffff0000;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  uStack_40 = 7;
  iStack_44 = 0;
  uStack_54 = uStack_54 & 0xffff0000;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

