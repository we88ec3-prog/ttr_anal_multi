
void FUN_00764c50(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  char *_Filename;
  FILE *pFVar2;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e28;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Filename = (char *)FUN_0047f540(param_2,uVar1);
  local_8 = 0;
  if (0xf < *(uint *)(_Filename + 0x14)) {
    _Filename = *(char **)_Filename;
  }
  pFVar2 = _fopen(_Filename,"w");
  if (pFVar2 != (FILE *)0x0) {
    FUN_0072f5b0();
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

