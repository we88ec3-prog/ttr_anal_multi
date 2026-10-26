
void FUN_008095d0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  int unaff_ESI;
  char *unaff_EDI;
  int local_60;
  undefined1 local_5c [4];
  int local_58;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914450;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffffff00;
  pcVar3 = unaff_EDI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_18 = uVar2;
  FUN_00402a70(unaff_EDI,(int)pcVar3 - (int)(unaff_EDI + 1));
  local_8 = 0;
  local_60 = FUN_007b6f30(local_34);
  if ((local_60 == *(int *)(unaff_ESI + 4)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_58 = *(int *)(unaff_ESI + 4);
    piVar4 = &local_58;
  }
  else {
    piVar4 = &local_60;
  }
  local_58 = *piVar4;
  local_8 = 0xffffffff;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  if (local_58 == *(int *)(unaff_ESI + 4)) {
    local_40 = 0xf;
    local_44 = 0;
    local_54[0] = local_54[0] & 0xffffff00;
    pcVar3 = unaff_EDI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(unaff_EDI,(int)pcVar3 - (int)(unaff_EDI + 1));
    local_38 = param_1;
    local_8 = 1;
    uVar5 = FUN_00552de0(local_54);
    FUN_007e2910(unaff_ESI,local_5c,uVar5);
    if (0xf < local_40) {
      FUN_0089120c(local_54[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

