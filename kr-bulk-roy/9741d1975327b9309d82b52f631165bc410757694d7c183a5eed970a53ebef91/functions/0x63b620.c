
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063b620(void)

{
  int iVar1;
  int in_ECX;
  wchar_t *_Src;
  undefined2 local_34;
  wchar_t local_32 [21];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(in_ECX + 0xf4);
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation");
  }
  if (*(int *)(iVar1 + 0x118) != 0) {
    iVar1 = *(int *)(in_ECX + 0xf4);
    if (*(char *)(iVar1 + 0x141) == '\0') {
      _Src = (wchar_t *)(iVar1 + 0x108);
      if (7 < *(uint *)(iVar1 + 0x11c)) {
        _Src = *(wchar_t **)_Src;
      }
    }
    else {
      FUN_006edb10("Not supported operation");
      if (*(uint *)(iVar1 + 0x11c) < 8) {
        _Src = (wchar_t *)(iVar1 + 0x108);
      }
      else {
        _Src = *(wchar_t **)(iVar1 + 0x108);
      }
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_34 = 0xbca;
    _wcscpy_s(local_32,0x15,_Src);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,&local_34,0x2c);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

