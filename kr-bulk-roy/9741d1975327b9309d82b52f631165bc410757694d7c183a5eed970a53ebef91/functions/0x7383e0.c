
void FUN_007383e0(char *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 extraout_EDX;
  int *unaff_ESI;
  int unaff_EDI;
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (unaff_EDI == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  unaff_ESI[2] = unaff_EDI;
  __splitpath(param_1,(char *)0x0,(char *)0x0,(char *)0x0,local_18);
  iVar1 = __stricmp(local_18,".iif");
  if (iVar1 == 0) {
    pcVar2 = *(code **)(*unaff_ESI + 4);
  }
  else {
    iVar1 = __stricmp(local_18,".iix");
    if (iVar1 == 0) {
      pcVar2 = (code *)((undefined4 *)*unaff_ESI)[2];
    }
    else {
      pcVar2 = *(code **)*unaff_ESI;
    }
  }
  (*pcVar2)();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,param_1);
  return;
}

