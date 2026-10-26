
void FUN_0071c770(double param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int *in_ECX;
  char *pcVar3;
  char *_Dst;
  int local_254;
  int *local_250;
  char *local_24c;
  char local_248;
  char local_247 [575];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_250 = in_ECX;
  iVar1 = FUN_0071c660(param_1);
  if (iVar1 != 0) {
    *in_ECX = iVar1;
    *(undefined1 *)(in_ECX + 1) = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_0071c710(param_1,&local_24c,&local_254);
  pcVar3 = &local_248;
  if (param_1 < 0.0) {
    local_248 = '-';
    pcVar3 = local_247;
  }
  if (local_254 < 1) {
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    do {
      cVar2 = *local_24c;
      if (cVar2 == '\0') {
        cVar2 = '0';
      }
      else {
        local_24c = local_24c + 1;
      }
      *pcVar3 = cVar2;
      local_254 = local_254 + -1;
      pcVar3 = pcVar3 + 1;
    } while (0 < local_254);
  }
  cVar2 = *local_24c;
  if (cVar2 != '\0') {
    *pcVar3 = '.';
    _Dst = pcVar3 + 1;
    if (local_254 < 0) {
      _memset(_Dst,0x30,-local_254);
      _Dst = _Dst + -local_254;
      in_ECX = local_250;
    }
    pcVar3 = _Dst;
    do {
      *pcVar3 = cVar2;
      cVar2 = pcVar3[(int)(local_24c + (1 - (int)_Dst))];
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
  }
  *pcVar3 = '\0';
  FUN_0071bfa0(in_ECX,param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

