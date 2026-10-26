
void FUN_00403fd0(void)

{
  wchar_t wVar1;
  uint uVar2;
  wchar_t *pwVar3;
  undefined4 *in_ECX;
  uint local_4c [4];
  int local_3c;
  uint local_38;
  uint local_30;
  wchar_t local_2c;
  undefined1 local_2a [10];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091be80;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_8 = 0;
  local_14 = uVar2;
  __itow_s(*(int *)*in_ECX,&local_2c,0xc,10);
  pwVar3 = &local_2c;
  do {
    wVar1 = *pwVar3;
    pwVar3 = pwVar3 + 1;
  } while (wVar1 != L'\0');
  FUN_00404300(&local_2c,(int)pwVar3 - (int)local_2a >> 1);
  if (local_3c < (int)in_ECX[1]) {
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    local_8._0_1_ = 1;
    FUN_00402340(in_ECX[1] - local_3c,in_ECX[2]);
    FUN_004041f0(local_4c,0,0xffffffff);
    FUN_004026e0(&local_30,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  FUN_004041f0(local_4c,0,0xffffffff);
  if (7 < local_38) {
    FUN_0089120c(local_4c[0],uVar2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

