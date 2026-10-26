
void FUN_006dacd0(UINT *param_1)

{
  uint uVar1;
  UINT UVar2;
  int iVar3;
  LPCSTR **pppCVar4;
  LPCSTR *local_38 [5];
  uint local_24;
  int local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915f09;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 1;
  param_1[1] = 0;
  local_18 = uVar1;
  _eh_vector_constructor_iterator_(param_1 + 2,0x10,4,FUN_006db280,FUN_006dade0);
  local_8 = 0;
  param_1[0x12] = 0;
  param_1[0x14] = 0;
  param_1[0x13] = 0x3c;
  FUN_006edd50(uVar1);
  local_8._0_1_ = 1;
  pppCVar4 = (LPCSTR **)local_38[0];
  if (local_24 < 0x10) {
    pppCVar4 = local_38;
  }
  UVar2 = GetPrivateProfileIntA("LOG","Packet",0,(LPCSTR)pppCVar4);
  *param_1 = UVar2;
  if (UVar2 != 0) {
    iVar3 = FUN_00891268(4);
    local_8._0_1_ = 2;
    if (iVar3 == 0) {
      UVar2 = 0;
    }
    else {
      UVar2 = FUN_006f0100();
    }
    param_1[1] = UVar2;
  }
  if (local_1c != 0) {
    pppCVar4 = (LPCSTR **)local_38[0];
    if (local_24 < 0x10) {
      pppCVar4 = local_38;
    }
    WritePrivateProfileStringA((LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)pppCVar4);
  }
  if (0xf < local_24) {
    FUN_0089120c(local_38[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

