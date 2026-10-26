
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c5e70(void)

{
  int iVar1;
  wchar_t *_Src;
  int *in_ECX;
  int *piVar2;
  undefined2 local_40;
  wchar_t local_3e [21];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928ace;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
LAB_006c5ec5:
    in_ECX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 4))(local_14);
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006c5ec5;
    }
  }
  if (in_ECX[5] != 0x6a7) goto LAB_006c5f8f;
  piVar2 = (int *)in_ECX[6];
  if (piVar2 == (int *)0x0) {
LAB_006c5efb:
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006c5efb;
    }
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _Src = (wchar_t *)FUN_004f6a30(piVar2[5]);
  local_40 = 0xbca;
  _wcscpy_s(local_3e,0x15,_Src);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_40,0x2c);
  }
LAB_006c5f8f:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

