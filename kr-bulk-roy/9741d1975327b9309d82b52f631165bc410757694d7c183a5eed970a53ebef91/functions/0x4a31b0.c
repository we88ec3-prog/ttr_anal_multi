
void FUN_004a31b0(void)

{
  wchar_t ****_Src;
  wchar_t *pwVar1;
  wchar_t *in_ECX;
  int iVar2;
  wchar_t local_13e [51];
  wchar_t local_d8 [51];
  undefined4 local_72;
  undefined4 local_6e;
  uint local_54;
  wchar_t ***local_4c [4];
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
  puStack_c = &LAB_00920038;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_72 = 0x10001;
  local_6e = 0x34;
  FUN_0047f540();
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_00733dd0();
  FUN_00403040(local_30,0,0xffffffff);
  FUN_0046e3c0();
  local_8 = CONCAT31(local_8._1_3_,2);
  local_6e = CONCAT22(*(undefined2 *)(DAT_00fb1318 + 0xbf80),(undefined2)local_6e);
  _wcscpy_s(local_13e,0x33,in_ECX);
  _Src = (wchar_t ****)local_4c[0];
  if (local_38 < 8) {
    _Src = local_4c;
  }
  _wcscpy_s(local_d8,0x33,(wchar_t *)_Src);
  (**(code **)(*DAT_00fba854 + 0x10))();
  iVar2 = 0x66;
  pwVar1 = local_13e;
  do {
    *(undefined1 *)pwVar1 = 0;
    pwVar1 = (wchar_t *)((int)pwVar1 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0x66;
  pwVar1 = local_d8;
  do {
    *(undefined1 *)pwVar1 = 0;
    pwVar1 = (wchar_t *)((int)pwVar1 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (7 < local_38) {
    FUN_0089120c();
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (wchar_t ***)((uint)local_4c[0] & 0xffff0000);
  if (0xf < local_1c) {
    FUN_0089120c();
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (0xf < local_54) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

