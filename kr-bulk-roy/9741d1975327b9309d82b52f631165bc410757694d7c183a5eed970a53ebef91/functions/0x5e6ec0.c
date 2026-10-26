
void FUN_005e6ec0(uint param_1)

{
  short sVar1;
  short *psVar2;
  short local_208;
  undefined1 local_206 [510];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_0040aeb0(L"<#%02x%02x%02x>",param_1 >> 0x10 & 0xff,param_1 >> 8 & 0xff,param_1 & 0xff);
  psVar2 = &local_208;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00404300(&local_208,(int)psVar2 - (int)local_206 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

