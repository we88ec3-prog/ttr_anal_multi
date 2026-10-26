
void FUN_005737d0(int *param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  char *in_ECX;
  int local_90;
  undefined4 local_8c;
  int local_88;
  int *local_84;
  uint local_80;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b108;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_84 = param_1;
  pcVar6 = in_ECX;
  if (0xf < *(uint *)(in_ECX + 0x14)) {
    pcVar6 = *(char **)in_ECX;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffffff00;
  pcVar5 = pcVar6;
  do {
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  local_18 = uVar4;
  FUN_0040b310(pcVar6);
  local_8 = 0;
  FUN_00574010(local_34);
  local_8 = 0xffffffff;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0],uVar4);
  }
  if (0xf < *(uint *)(in_ECX + 0x14)) {
    in_ECX = *(char **)in_ECX;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffffff00;
  pcVar6 = in_ECX;
  do {
    cVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar3 != '\0');
  FUN_0040b310(in_ECX);
  piVar2 = local_84;
  local_8 = 1;
  iVar1 = *local_84;
  local_90 = FUN_006cf160(local_34);
  if ((local_90 == *(int *)(iVar1 + 4)) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
    local_88 = *(int *)(iVar1 + 4);
    piVar7 = &local_88;
  }
  else {
    piVar7 = &local_90;
  }
  iVar1 = *piVar7;
  local_8 = 0xffffffff;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffffff00;
  if (iVar1 != *(int *)(*piVar2 + 4)) {
    local_6c = 0xf;
    local_70 = 0;
    local_80 = local_80 & 0xffffff00;
    FUN_00402a70(&DAT_00bf2375,0);
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_8 = 2;
    FUN_00572aa0();
    local_8c = local_44;
    local_88 = local_40;
    FUN_007b6e80(&local_8c);
    if (0xf < local_6c) {
      FUN_0089120c(local_80);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

