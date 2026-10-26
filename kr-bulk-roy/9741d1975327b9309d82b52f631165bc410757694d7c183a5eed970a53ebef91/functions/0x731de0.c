
void FUN_00731de0(undefined4 *param_1,char *param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  wchar_t ****_Source;
  char *pcVar2;
  undefined4 uVar3;
  char *_Dest;
  int in_ECX;
  undefined4 in_EDX;
  undefined4 uVar4;
  undefined4 local_484;
  wchar_t ***local_480 [4];
  undefined4 local_470;
  uint local_46c;
  char local_464 [1024];
  char local_64;
  undefined1 local_63 [51];
  char local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f1ab;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = '\0';
  local_30[8] = '\0';
  local_30[9] = '\0';
  local_30[10] = '\0';
  local_30[0xb] = '\0';
  local_30[0xc] = '\0';
  local_30[0xd] = '\0';
  local_30[0xe] = '\0';
  local_30[0xf] = '\0';
  local_30[0x10] = '\0';
  local_30[0x11] = '\0';
  local_30[0x12] = '\0';
  local_30[0x13] = '\0';
  local_30[0x14] = '\0';
  local_30[0x15] = '\0';
  local_30[0x16] = '\0';
  local_30[0x17] = '\0';
  local_30[0x18] = '\0';
  local_14 = uVar1;
  if (param_2 == (char *)0x0) {
    builtin_strncpy(local_30,"(none)",7);
  }
  else if (param_4 == 1) {
    local_46c = 7;
    local_470 = 0;
    local_480[0] = (wchar_t ***)((uint)local_480[0] & 0xffff0000);
    local_8 = 0;
    local_64 = '\0';
    _memset(local_63,0,0x30);
    FUN_00731c90(param_2);
    _Source = (wchar_t ****)local_480[0];
    if (local_46c < 8) {
      _Source = local_480;
    }
    _wcstombs(&local_64,(wchar_t *)_Source,0x18);
    _strncpy_s(local_30,0x19,&local_64,0xffffffff);
    local_8 = 0xffffffff;
    if (7 < local_46c) {
      FUN_0089120c(local_480[0],uVar1);
    }
    local_46c = 7;
    local_470 = 0;
    local_480[0] = (wchar_t ***)((uint)local_480[0] & 0xffff0000);
  }
  else {
    _strncpy_s(local_30,0x19,param_2,0xffffffff);
  }
  pcVar2 = _strchr(local_30,10);
  if (pcVar2 != (char *)0x0) {
    *pcVar2 = '\0';
  }
  uVar4 = 0xffffffff;
  local_484 = 0xffffffff;
  if (param_3 != (undefined4 *)0x0) {
    local_484 = param_3[1];
    uVar4 = *param_3;
  }
  local_464[0] = '\0';
  _memset(local_464 + 1,0,0x3ff);
  uVar3 = FUN_00731bd0();
  _sprintf(local_464,"TiXmlLoad Error loading %s: %s",in_EDX,uVar3);
  if (in_ECX != 2) {
    pcVar2 = local_464;
    do {
      _Dest = pcVar2;
      pcVar2 = _Dest + 1;
    } while (*_Dest != '\0');
    _sprintf(_Dest,"\n - parsing pos: (%d,%d) \'%s\'",uVar4,local_484,local_30);
  }
  (**(code **)*param_1)(local_464);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

