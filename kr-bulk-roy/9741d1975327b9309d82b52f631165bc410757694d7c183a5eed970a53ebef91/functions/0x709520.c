
void FUN_00709520(undefined4 param_1)

{
  char *pcVar1;
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  pcVar1 = _tmpnam(local_18);
  if (pcVar1 == (char *)0x0) {
    FUN_006f5f30(param_1,"unable to generate a unique filename");
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006f5510(local_18);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

