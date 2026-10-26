
void FUN_00610f80(undefined4 param_1,undefined1 param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  short *psVar5;
  int in_ECX;
  short *psVar6;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  int local_70;
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
  local_6c = CONCAT31(local_6c._1_3_,param_2);
  local_70 = in_ECX;
  FUN_00611540(param_1,local_6c,param_3);
  local_6c = CONCAT31(local_6c._1_3_,(char)local_6c + '\x01');
  uVar3 = local_6c;
  local_54 = 7;
  local_58 = 0;
  local_68 = (uint)local_68._2_2_ << 0x10;
  local_8 = 0;
  cVar4 = FUN_00612d60(in_ECX,param_1,local_6c);
  if (cVar4 == '\0') {
    cVar4 = FUN_00612b80(in_ECX,uVar3);
    if (cVar4 == '\0') {
      *(undefined4 *)(*(int *)(in_ECX + 0x17c) + 0x154) = 0xffff503c;
      goto LAB_0061101d;
    }
  }
  *(undefined4 *)(*(int *)(in_ECX + 0x17c) + 0x154) = 0xffffc000;
LAB_0061101d:
  FUN_00611b60(param_1,uVar3);
  FUN_00757710();
  local_38 = 7;
  local_3c = 0;
  local_4c = (uint)local_4c._2_2_ << 0x10;
  local_8._0_1_ = 1;
  psVar5 = (short *)FUN_00611de0(param_1,local_6c);
  local_30 = (uint)local_30._2_2_ << 0x10;
  local_1c = 7;
  local_20 = 0;
  psVar6 = psVar5;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_3c != 0) {
    FUN_00404300(L"<br>",4);
  }
  psVar5 = (short *)FUN_00612190(param_1,local_6c);
  psVar6 = psVar5;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
  if (local_3c != 0) {
    FUN_00404300(L"<br>",4);
  }
  if (param_3 != 0) {
    psVar5 = (short *)FUN_00612940(param_1,local_6c);
    psVar6 = psVar5;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
    if (local_3c != 0) {
      FUN_00404300(L"<br>",4);
    }
  }
  psVar5 = (short *)FUN_00611ee0(param_1,local_6c);
  psVar6 = psVar5;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
  local_78 = 7;
  local_7c = 0;
  local_8c = (uint)local_8c._2_2_ << 0x10;
  FUN_004026e0(&local_30,0,0xffffffff);
  iVar2 = *(int *)(local_70 + 0x180);
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

