
void FUN_007b6280(void)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916b68;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_8 = 0;
  local_14 = uVar2;
  do {
    cVar1 = FUN_007b6af0(local_30);
  } while (cVar1 != '\0');
  if (*(int *)(in_ECX + 0xa4) != 0) {
    FUN_007b70b0(in_ECX + 0x9c,uVar2);
  }
  FUN_00552640(in_ECX + 0xac);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

