
void FUN_0079be00(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *unaff_EDI;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093250e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *unaff_EDI = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x44));
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  puVar2 = (undefined4 *)(**(code **)(*DAT_00fb76a8 + 0x54))(local_14,param_1);
  *unaff_EDI = *puVar2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x44));
  ExceptionList = local_10;
  return;
}

