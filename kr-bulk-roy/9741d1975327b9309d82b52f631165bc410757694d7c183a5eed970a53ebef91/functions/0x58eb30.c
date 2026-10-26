
void FUN_0058eb30(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  wchar_t ***_Str1;
  int iVar3;
  undefined4 in_ECX;
  wchar_t **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (wchar_t **)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  local_14 = uVar2;
  FUN_00402160(L"false",5);
  local_8 = 0;
  cVar1 = FUN_0058ef10(in_ECX,param_1);
  if (cVar1 == '\0') {
    if (7 < local_1c) {
      FUN_0089120c(local_30[0],uVar2);
    }
  }
  else {
    _Str1 = (wchar_t ***)local_30[0];
    if (local_1c < 8) {
      _Str1 = local_30;
    }
    iVar3 = __wcsicmp((wchar_t *)_Str1,L"true");
    *(bool *)param_2 = iVar3 == 0;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0],uVar2);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

