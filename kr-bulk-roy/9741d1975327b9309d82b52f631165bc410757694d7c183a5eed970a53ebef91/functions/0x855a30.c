
void FUN_00855a30(undefined4 *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int unaff_EDI;
  int local_38;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917838;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_14 = uVar3;
  FUN_00402a70("isSkinning",10);
  local_8 = 0;
  local_38 = FUN_00856250(local_30);
  if ((local_38 == *(int *)(unaff_EDI + 0x188)) || (cVar2 = FUN_0049ae30(uVar3), cVar2 != '\0')) {
    local_34 = *(int *)(unaff_EDI + 0x188);
    piVar4 = &local_34;
  }
  else {
    piVar4 = &local_38;
  }
  iVar1 = *piVar4;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (iVar1 != *(int *)(unaff_EDI + 0x188)) {
    if (*(int *)(iVar1 + 0x30) == 0) {
      uVar5 = FUN_00891268(4);
      *(undefined4 *)(iVar1 + 0x30) = uVar5;
    }
    **(undefined4 **)(iVar1 + 0x30) = *param_1;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

