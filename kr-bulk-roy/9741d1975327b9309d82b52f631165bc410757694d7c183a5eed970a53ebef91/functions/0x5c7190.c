
void FUN_005c7190(void)

{
  short sVar1;
  short *psVar2;
  short *in_EDX;
  int unaff_EDI;
  int local_28;
  uint local_24;
  undefined4 local_14;
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_24 = local_24 & 0xffff0000;
  local_10 = 7;
  local_14 = 0;
  psVar2 = in_EDX;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(in_EDX,(int)psVar2 - (int)(in_EDX + 1) >> 1);
  FUN_005c72f0(&local_28);
  if (7 < local_10) {
    FUN_0089120c(local_24);
  }
  if (local_28 != *(int *)(unaff_EDI + 8)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

