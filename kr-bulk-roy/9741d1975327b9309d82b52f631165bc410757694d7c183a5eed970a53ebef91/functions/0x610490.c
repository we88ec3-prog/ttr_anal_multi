
void FUN_00610490(undefined1 param_1,undefined1 param_2,int param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int in_ECX;
  short *psVar4;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c;
  int local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093e413;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6c = CONCAT31(local_6c._1_3_,param_1);
  *(undefined1 *)(in_ECX + 0x15c) = param_1;
  local_70 = CONCAT31(local_70._1_3_,param_2);
  *(undefined1 *)(in_ECX + 0x15d) = param_2;
  *(int *)(in_ECX + 0x160) = param_3;
  FUN_00610760(local_14);
  local_54 = 7;
  local_58 = 0;
  local_68 = (uint)local_68._2_2_ << 0x10;
  local_8 = 0;
  FUN_00610850(local_6c,local_70);
  FUN_00757710();
  local_38 = 7;
  local_3c = 0;
  local_4c = (uint)local_4c._2_2_ << 0x10;
  local_8._0_1_ = 1;
  psVar3 = (short *)FUN_00610920(local_6c,local_70);
  local_30 = (uint)local_30._2_2_ << 0x10;
  local_1c = 7;
  local_20 = 0;
  psVar4 = psVar3;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_3c != 0) {
    FUN_00404300(L"<br>",4);
  }
  if (param_3 != 0) {
    psVar3 = (short *)FUN_00610a00(local_6c,local_70,&local_4c);
    psVar4 = psVar3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
    if (local_3c != 0) {
      FUN_00404300(L"<br>",4);
    }
  }
  local_78 = 7;
  local_7c = 0;
  local_8c = (uint)local_8c._2_2_ << 0x10;
  FUN_004026e0(&local_30,0,0xffffffff);
  iVar2 = *(int *)(in_ECX + 0x170);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_007578f0();
  FUN_00759ed0(iVar2 + 0xe8,&local_8c,0x7b,0x7d);
  if (7 < local_78) {
    FUN_0089120c(local_8c);
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = local_30 & 0xffff0000;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = local_4c & 0xffff0000;
  if (7 < local_54) {
    FUN_0089120c(local_68);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

