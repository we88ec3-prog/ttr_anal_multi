
void FUN_007b8090(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  char *in_ECX;
  int in_EDX;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e28;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = in_ECX;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar3;
  FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
  local_8 = 0;
  FUN_007b86f0(&local_34,local_30);
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar3);
  }
  if (local_34 != *(int *)(in_EDX + 8)) {
    iVar2 = *(int *)(local_34 + 0x24);
    iVar5 = FUN_007dd100();
    if (iVar5 == 0) {
      if (iVar2 != 0) {
        FUN_007dcf40();
        FUN_0089120c(iVar2);
      }
      FUN_007b8680(&local_34,local_34);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

