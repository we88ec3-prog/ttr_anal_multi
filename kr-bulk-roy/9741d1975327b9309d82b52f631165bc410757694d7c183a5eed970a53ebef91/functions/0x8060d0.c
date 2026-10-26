
undefined4 FUN_008060d0(void *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090995e;
  local_10 = ExceptionList;
  if (300 < *(int *)(in_ECX + 0xa0a4)) {
    return 0;
  }
  ExceptionList = &local_10;
  if ((DAT_00fe3354 & 1) == 0) {
    DAT_00fe3354 = DAT_00fe3354 | 1;
    local_8 = 0;
    FUN_00807120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bd0b90);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_00807470();
  if (param_2 < 0x1001) {
    FID_conflict__memcpy((void *)(iVar1 + 8),param_1,param_2);
    *(uint *)(iVar1 + 4) = param_2;
  }
  uVar2 = FUN_00806060(iVar1);
  ExceptionList = local_10;
  return uVar2;
}

