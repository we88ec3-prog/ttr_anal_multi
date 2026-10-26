
void FUN_00756010(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *_Str1;
  int *in_ECX;
  undefined4 ***pppuVar3;
  undefined4 local_4c;
  uint local_38;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920350;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = FUN_004297b0(local_14);
  local_8 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  FUN_00402bb0(uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  pppuVar3 = (undefined4 ***)local_30[0];
  if (local_1c < 0x10) {
    pppuVar3 = local_30;
  }
  (**(code **)(*in_ECX + 0x14))();
  iVar2 = FUN_007300a0(pppuVar3);
  if (iVar2 == 0) {
    _Str1 = (char *)0x0;
  }
  else {
    _Str1 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      _Str1 = *(char **)_Str1;
    }
  }
  if (param_1 != (undefined1 *)0x0) {
    if (_Str1 == (char *)0x0) {
      *param_1 = 0;
    }
    else {
      iVar2 = __stricmp(_Str1,"true");
      *param_1 = iVar2 == 0;
    }
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

