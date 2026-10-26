
void FUN_00872350(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *in_ECX;
  char *pcVar4;
  undefined4 *in_EDX;
  uint in_stack_00000018;
  undefined1 local_240 [4];
  char *local_23c;
  uint local_238;
  undefined4 local_228;
  uint local_224;
  char local_21c [520];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00927e93;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar3 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar3 = (char *)&param_1;
  }
  iVar2 = -(int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)(local_21c + iVar2)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_23c = in_ECX;
  FUN_00556160(in_EDX,local_240,*in_EDX,in_EDX[1]);
  pcVar3 = _strtok(local_21c,in_ECX);
  while (pcVar3 != (char *)0x0) {
    local_224 = 0xf;
    local_228 = 0;
    local_238 = local_238 & 0xffffff00;
    pcVar4 = pcVar3;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
    local_8._0_1_ = 1;
    FUN_00440c60();
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_224) {
      FUN_0089120c(local_238);
    }
    pcVar3 = _strtok((char *)0x0,local_23c);
  }
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

