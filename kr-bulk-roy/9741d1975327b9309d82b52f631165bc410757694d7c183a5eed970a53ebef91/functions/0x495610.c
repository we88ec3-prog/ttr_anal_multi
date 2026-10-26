
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00495610(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *unaff_ESI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941c7c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  DAT_00f941c0 = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  _wcsncpy_s((wchar_t *)&DAT_00f941c4,0xb,L"",10);
  if (param_3 == 0) {
    if (*(int *)(param_1 + 0xbf60) != 0) {
      ExceptionList = local_14;
      return 1;
    }
  }
  else {
    if ((_DAT_00fd8bf8 & 1) == 0) {
      _DAT_00fd8bf8 = _DAT_00fd8bf8 | 1;
      _DAT_00fd8bfc = 0;
      _atexit((_func_4879 *)&DAT_00bce310);
    }
    DAT_00fd8c00 = 0;
    _DAT_00fd8bfc = 0;
    (**(code **)(*DAT_00fba854 + 0x20))(0,1);
    (**(code **)(*DAT_00fba854 + 0x20))(2,1);
    if (*(int *)(param_1 + 0xbf60) != 0) {
      FUN_006edb60(&DAT_00c05a04);
      (**(code **)(*DAT_00fba854 + 0x20))(1,1);
      *(undefined4 *)(param_1 + 0xbf60) = 0;
    }
  }
  iVar2 = (**(code **)(*DAT_00fba854 + 0x18))(param_2,0x20df,1,2);
  if (iVar2 != 0) {
    (**(code **)(*DAT_00fba854 + 0x14))(iVar2);
    *(int *)(param_1 + 0xbf60) = iVar2;
    Sleep(500);
    ExceptionList = local_14;
    return 1;
  }
  PostQuitMessage(0);
  ExceptionList = unaff_ESI;
  return 0;
}

