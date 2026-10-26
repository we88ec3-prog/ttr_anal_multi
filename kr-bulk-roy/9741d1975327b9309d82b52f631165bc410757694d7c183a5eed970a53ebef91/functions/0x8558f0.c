
void FUN_008558f0(int param_1)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  int local_44;
  undefined1 local_40 [4];
  int local_3c;
  char local_35;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913fa0;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar1 = *(char **)(param_1 + 0xc);
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffffff00;
  pcVar5 = pcVar1;
  do {
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  local_18 = uVar4;
  FUN_00402a70(pcVar1,(int)pcVar5 - (int)(pcVar1 + 1));
  local_8 = 0;
  iVar2 = *(int *)(in_ECX + 0x188);
  local_44 = FUN_00856250(local_34);
  if ((local_44 == *(int *)(in_ECX + 0x188)) || (cVar3 = FUN_0049ae30(uVar4), cVar3 != '\0')) {
    local_3c = *(int *)(in_ECX + 0x188);
    piVar6 = &local_3c;
  }
  else {
    piVar6 = &local_44;
  }
  local_35 = *piVar6 == iVar2;
  local_8 = 0xffffffff;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  if (local_35 != '\0') {
    local_3c = *(int *)(param_1 + 0xc);
    uVar7 = FUN_008563c0(&local_3c);
    local_8 = 1;
    uVar7 = FUN_00856820(uVar7);
    FUN_00856530(in_ECX + 0x184,local_40,uVar7);
    FUN_00867f40();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

