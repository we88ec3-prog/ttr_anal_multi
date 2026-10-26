
void FUN_007c2b60(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  char *in_ECX;
  int unaff_ESI;
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
  puStack_c = &LAB_00914cd3;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 0;
  local_38 = FUN_007b6f30(local_30);
  if ((local_38 == *(int *)(unaff_ESI + 4)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_34 = *(int *)(unaff_ESI + 4);
    piVar4 = &local_34;
  }
  else {
    piVar4 = &local_38;
  }
  local_34 = *piVar4;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (local_34 != *(int *)(unaff_ESI + 4)) {
    local_34 = FUN_00891268(0x6c);
    local_8 = 1;
    if (local_34 != 0) {
      FUN_007cd450(local_34,param_1);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

