
void FUN_0058cd50(int param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  undefined4 uVar4;
  short *psVar5;
  short *in_ECX;
  undefined1 auStack_84 [4];
  short *local_80;
  short *local_7c [2];
  int local_74;
  uint local_70 [4];
  undefined4 local_60;
  uint local_5c;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091da88;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  local_80 = param_2;
  local_5c = 7;
  local_60 = 0;
  local_70[0] = local_70[0] & 0xffff0000;
  psVar3 = in_ECX;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  local_7c[0] = in_ECX;
  FUN_00402160(in_ECX,(int)psVar3 - (int)(in_ECX + 1) >> 1);
  local_c = 0;
  FUN_00539110(&local_74);
  local_c = 0xffffffff;
  if (7 < local_5c) {
    FUN_0089120c(local_70[0],uVar2);
  }
  psVar3 = local_80;
  if (local_74 == *(int *)(param_1 + 8)) {
    FUN_0058fe70(local_70,local_7c,&local_80);
    local_c = 1;
    uVar4 = FUN_005394c0(local_70);
    FUN_00539230(param_1 + 4,local_7c,uVar4);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    local_40 = 7;
    local_44 = 0;
    local_54 = local_54 & 0xffff0000;
    psVar3 = local_80;
    if (7 < local_5c) {
      FUN_0089120c(local_70[0]);
      psVar3 = local_80;
    }
  }
  else {
    local_7c[0] = local_80 + 1;
    psVar5 = local_80;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(local_80,(int)psVar5 - (int)local_7c[0] >> 1);
  }
  local_38 = (uint)local_38._2_2_ << 0x10;
  local_24 = 7;
  local_28 = 0;
  psVar5 = in_ECX;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(in_ECX,(int)psVar5 - (int)(in_ECX + 1) >> 1);
  local_c = 2;
  FUN_0058f260(param_1 + 4);
  psVar5 = psVar3;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar3,(int)psVar5 - (int)(psVar3 + 1) >> 1);
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

