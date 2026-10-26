
void FUN_004a3360(void)

{
  LPCWSTR ***lpWideCharStr;
  int iVar1;
  char *lpMultiByteStr;
  undefined1 *puVar2;
  LPCWSTR in_ECX;
  undefined1 auStack_f4 [4];
  undefined1 *local_f0;
  LPSTR pCStack_ec;
  LPCWSTR local_e8;
  LPCWSTR **local_e4;
  undefined4 uStack_e0;
  uint uStack_dc;
  uint uStack_d4;
  uint local_d0;
  undefined1 local_c8 [4];
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  uint uStack_a4;
  undefined1 auStack_9a [10];
  undefined2 local_90;
  char acStack_8e [39];
  undefined1 auStack_67 [12];
  char acStack_5b [51];
  uint uStack_28;
  undefined2 local_22;
  void *pvStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091fff1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_f4;
  ExceptionList = &local_14;
  local_90 = 0xe8;
  local_22 = *(undefined2 *)(DAT_00fb1318 + 0xbf80);
  local_e8 = in_ECX;
  FUN_0047f540();
  local_b4 = 0xf;
  local_b8 = 0;
  local_c8[0] = 0;
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  FUN_00733dd0();
  local_f0 = &stack0xfffffee0;
  FUN_00403040(local_c8,0,0xffffffff);
  FUN_0046e3c0();
  local_c = CONCAT31(local_c._1_3_,2);
  local_f0 = (undefined1 *)WideCharToMultiByte(0,0,in_ECX,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  lpWideCharStr = (LPCWSTR ***)local_e4;
  if (local_d0 < 8) {
    lpWideCharStr = &local_e4;
  }
  iVar1 = WideCharToMultiByte(0,0,(LPCWSTR)lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  pCStack_ec = (LPSTR)FUN_0087dc3d();
  lpMultiByteStr = (char *)FUN_0087dc3d();
  WideCharToMultiByte(0,0,local_e8,-1,pCStack_ec,(int)local_f0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (local_d0 < 8) {
    local_e4 = (LPCWSTR **)&local_e4;
  }
  WideCharToMultiByte(0,0,(LPCWSTR)local_e4,-1,lpMultiByteStr,iVar1,(LPCSTR)0x0,(LPBOOL)0x0);
  _strcpy_s(acStack_8e,0x33,pCStack_ec);
  _strcpy_s(acStack_5b,0x33,lpMultiByteStr);
  (**(code **)(*DAT_00fba854 + 0x10))();
  iVar1 = 0x33;
  puVar2 = auStack_9a;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 0x33;
  puVar2 = auStack_67;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (7 < uStack_dc) {
    FUN_0089120c();
  }
  uStack_dc = 7;
  uStack_e0 = 0;
  local_f0 = (undefined1 *)((uint)local_f0 & 0xffff0000);
  if (0xf < uStack_c0) {
    FUN_0089120c();
  }
  uStack_c0 = 0xf;
  uStack_c4 = 0;
  uStack_d4 = uStack_d4 & 0xffffff00;
  if (0xf < uStack_a4) {
    FUN_0089120c();
  }
  ExceptionList = pvStack_20;
  __security_check_cookie(uStack_28 ^ (uint)&stack0xffffff00);
  return;
}

