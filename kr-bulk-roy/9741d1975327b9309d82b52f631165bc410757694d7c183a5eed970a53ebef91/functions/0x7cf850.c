
void FUN_007cf850(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  char *in_EDX;
  int local_58;
  int local_54;
  char local_4d;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009188f0;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = in_EDX;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_14 = uVar3;
  FUN_00402a70(in_EDX,(int)pcVar4 - (int)(in_EDX + 1));
  local_8 = 0;
  iVar1 = *(int *)(in_ECX + 0x14);
  local_58 = FUN_007b6f30(local_30);
  if ((local_58 == *(int *)(in_ECX + 0x14)) || (cVar2 = FUN_0049ae30(uVar3), cVar2 != '\0')) {
    local_54 = *(int *)(in_ECX + 0x14);
    piVar5 = &local_54;
  }
  else {
    piVar5 = &local_58;
  }
  local_4d = *piVar5 != iVar1;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  if (local_4d != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
    pcVar4 = in_EDX;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(in_EDX,(int)pcVar4 - (int)(in_EDX + 1));
    local_8 = 1;
    puVar6 = (undefined4 *)FUN_007cff00(local_4c);
    FUN_007ee240(*puVar6);
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

