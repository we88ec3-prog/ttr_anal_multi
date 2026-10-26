
void FUN_00507610(undefined4 param_1,int param_2,uint param_3,char *param_4)

{
  uint uVar1;
  wchar_t *_Src;
  int *piVar2;
  int iVar3;
  uint local_7c;
  int local_78;
  uint local_74;
  char local_68 [20];
  wchar_t local_54 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091732e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_74 = param_3;
  local_14 = uVar1;
  _strcpy_s(local_68,0x14,param_4);
  if ((DAT_00fe1b30 & 1) == 0) {
    DAT_00fe1b30 = DAT_00fe1b30 | 1;
    local_8 = 0;
    FUN_0047faf0(uVar1);
    _atexit((_func_4879 *)&LAB_00bceab0);
    local_8 = 0xffffffff;
  }
  local_7c = param_2 << 0x10 | param_3 & 0xffff;
  FUN_0047fdf0(&local_7c);
  if (local_78 == DAT_00fe1b48) {
    _Src = (wchar_t *)(&PTR_u______00d6a12c)[param_3 & 0xffff];
  }
  else {
    _Src = (wchar_t *)(local_78 + 0x10);
    if (7 < *(uint *)(local_78 + 0x24)) {
      _Src = *(wchar_t **)_Src;
    }
  }
  _wcsncpy_s(local_54,0x1e,_Src,0xffffffff);
  FUN_00542210(param_2);
  piVar2 = (int *)FUN_0050b4b0(param_2);
  iVar3 = 0;
  if ((int *)*piVar2 != (int *)0x0) {
    iVar3 = *(int *)*piVar2;
  }
  uVar1 = piVar2[2];
  if (*(uint *)(iVar3 + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(iVar3 + 8);
  }
  FUN_00507b10(*(int *)(*(int *)(iVar3 + 4) + uVar1 * 4) + 0x40);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

