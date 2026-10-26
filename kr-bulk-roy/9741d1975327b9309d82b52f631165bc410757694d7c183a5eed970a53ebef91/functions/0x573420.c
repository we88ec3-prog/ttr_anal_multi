
void FUN_00573420(char *param_1,undefined4 *param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int *unaff_EDI;
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
  puStack_c = &LAB_0091b0c8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(char **)param_1;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = param_1;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_14 = uVar3;
  FUN_0040b310(param_1);
  local_8 = 0;
  iVar1 = *unaff_EDI;
  local_38 = FUN_006cf160(local_30);
  if ((local_38 == *(int *)(iVar1 + 4)) || (cVar2 = FUN_005436a0(uVar3), cVar2 != '\0')) {
    local_34 = *(int *)(iVar1 + 4);
    piVar5 = &local_34;
  }
  else {
    piVar5 = &local_38;
  }
  iVar1 = *piVar5;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (iVar1 != *(int *)(*unaff_EDI + 4)) {
    iVar1 = *(int *)(iVar1 + 0x28);
    *(undefined4 *)(iVar1 + 0x30) = *param_2;
    *(undefined4 *)(iVar1 + 0x34) = param_2[1];
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

