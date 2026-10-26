
void FUN_007cf2f0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  char *unaff_EDI;
  undefined1 local_64 [4];
  int local_60;
  int local_5c;
  int local_58;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914bc0;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = local_54[0] & 0xffffff00;
  pcVar5 = unaff_EDI;
  do {
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  local_58 = in_ECX;
  local_18 = uVar4;
  FUN_00402a70(unaff_EDI,(int)pcVar5 - (int)(unaff_EDI + 1));
  local_8 = 0;
  iVar1 = *(int *)(in_ECX + 0x14);
  local_5c = FUN_007b6f30(local_54);
  if ((local_5c == *(int *)(in_ECX + 0x14)) || (cVar3 = FUN_0049ae30(uVar4), cVar3 != '\0')) {
    local_60 = *(int *)(in_ECX + 0x14);
    piVar6 = &local_60;
  }
  else {
    piVar6 = &local_5c;
  }
  iVar2 = *piVar6;
  local_8 = 0xffffffff;
  if (0xf < local_40) {
    FUN_0089120c(local_54[0]);
  }
  if (iVar2 == iVar1) {
    local_24 = 0xf;
    local_28 = 0;
    local_38[0] = local_38[0] & 0xffffff00;
    pcVar5 = unaff_EDI;
    do {
      cVar3 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar3 != '\0');
    FUN_00402a70(unaff_EDI,(int)pcVar5 - (int)(unaff_EDI + 1));
    local_1c = param_1;
    local_8 = 1;
    uVar7 = FUN_00552de0(local_38);
    FUN_007e2910(in_ECX + 0x10,local_64,uVar7);
    local_8 = 0xffffffff;
    if (0xf < local_24) {
      FUN_0089120c(local_38[0]);
    }
    local_24 = 0xf;
    local_28 = 0;
    local_38[0] = local_38[0] & 0xffffff00;
    FUN_007cf170(local_58);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

