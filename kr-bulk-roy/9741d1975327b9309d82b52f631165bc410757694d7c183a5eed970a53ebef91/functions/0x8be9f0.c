
void FUN_008be9f0(int param_1)

{
  char cVar1;
  char *_Src;
  char *pcVar2;
  int iVar3;
  undefined4 *in_ECX;
  int local_118;
  int local_110;
  undefined1 local_108 [256];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (((in_ECX == (undefined4 *)0x0) || ((char *)*in_ECX == (char *)0x0)) ||
     (*(char *)*in_ECX == '\0')) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_008bdf80(in_ECX[0x11022]);
  in_ECX[7] = *(undefined4 *)(param_1 + 0xc);
  _Src = (char *)*in_ECX;
  pcVar2 = _Src;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + (1 - (int)(_Src + 1));
  if (&DAT_00000100 <= pcVar2) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FID_conflict__memcpy(local_108,_Src,(size_t)pcVar2);
  iVar3 = FUN_008be0f0(local_108,pcVar2);
  if ((iVar3 == 0) && (local_110 == 0xf)) {
    switch(**(undefined1 **)(local_118 + 0x2c)) {
    case 0x43:
    case 99:
      in_ECX[7] = 0x20;
      FUN_008bdfa0();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    case 0x4d:
    case 0x6d:
      in_ECX[7] = 0x10;
      FUN_008bdfa0();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    case 0x50:
    case 0x70:
      in_ECX[7] = 8;
    }
  }
  FUN_008bdfa0();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

