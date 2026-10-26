
void FUN_007dca10(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *in_ECX;
  undefined4 in_EDX;
  undefined4 *local_38;
  undefined4 *local_34;
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
  FUN_007dcac0(in_EDX,&local_38,local_30);
  for (; local_38 != local_34; local_38 = (undefined4 *)*local_38) {
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

