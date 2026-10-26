
void FUN_00427610(void)

{
  wchar_t wVar1;
  uint uVar2;
  wchar_t *pwVar3;
  undefined4 *in_ECX;
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_3c [4];
  int local_2c;
  uint local_28;
  wchar_t local_20;
  undefined1 local_1e [10];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091bdc0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = 7;
  local_2c = 0;
  local_3c[0] = local_3c[0] & 0xffff0000;
  local_8 = 0;
  local_14 = uVar2;
  __ultow_s((uint)*(byte *)*in_ECX,&local_20,5,10);
  pwVar3 = &local_20;
  do {
    wVar1 = *pwVar3;
    pwVar3 = pwVar3 + 1;
  } while (wVar1 != L'\0');
  FUN_00404300(&local_20,(int)pwVar3 - (int)local_1e >> 1);
  if (local_2c < (int)in_ECX[1]) {
    local_44 = 7;
    local_48 = 0;
    local_58[0] = local_58[0] & 0xffff0000;
    local_8._0_1_ = 1;
    FUN_00402340(in_ECX[1] - local_2c,in_ECX[2]);
    FUN_004041f0(local_3c,0,0xffffffff);
    FUN_004026e0(local_58,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_44) {
      FUN_0089120c(local_58[0]);
    }
  }
  FUN_004041f0(local_3c,0,0xffffffff);
  if (7 < local_28) {
    FUN_0089120c(local_3c[0],uVar2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

