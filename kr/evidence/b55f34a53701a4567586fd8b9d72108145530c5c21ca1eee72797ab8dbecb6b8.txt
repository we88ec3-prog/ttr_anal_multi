
void FUN_00716740(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  char *in_ECX;
  int in_EDX;
  int local_3c;
  undefined4 local_38;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009284c8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_1;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = in_ECX;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_14 = uVar3;
  FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
  local_8 = 0;
  local_3c = FUN_007b6f30(local_30);
  if ((local_3c == *(int *)(in_EDX + 4)) || (cVar2 = FUN_0049ae30(uVar3), cVar2 != '\0')) {
    local_34 = *(int *)(in_EDX + 4);
    piVar5 = &local_34;
  }
  else {
    piVar5 = &local_3c;
  }
  iVar1 = *piVar5;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (iVar1 != *(int *)(in_EDX + 4)) {
    FUN_007197e0(local_38);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

