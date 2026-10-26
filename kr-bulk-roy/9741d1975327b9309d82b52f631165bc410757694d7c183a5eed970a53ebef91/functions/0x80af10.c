
void FUN_0080af10(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *in_ECX;
  bool bVar4;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c3f4;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar4 = false;
  if (in_ECX == (char *)0x0) {
    FUN_0080ae20();
  }
  else {
    iVar2 = FUN_00891268(0x2c,local_14);
    local_8 = 0;
    if (iVar2 != 0) {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      pcVar3 = in_ECX;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_0040b310(in_ECX);
      local_8 = CONCAT31(local_8._1_3_,1);
      bVar4 = true;
      FUN_0080e230(iVar2,local_30);
    }
    if ((bVar4) && (0xf < local_1c)) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

