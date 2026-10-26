
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0048e630(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  LPCWSTR lpText;
  HWND hWnd;
  int *piVar4;
  LPCWSTR lpCaption;
  UINT uType;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00925354;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1a34 & 1) == 0) {
    DAT_00fc1a34 = DAT_00fc1a34 | 1;
    local_8 = 0;
    FUN_00737210(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce000);
  }
  local_8 = 0xffffffff;
  FUN_00737af0(&DAT_00fc1a44);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8 = 1;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8 = 0xffffffff;
  }
  FUN_00735900(&DAT_00fb7b70);
  (**(code **)(*DAT_00fb7b78 + 0x10))();
  (**(code **)(*DAT_00fb7b78 + 8))();
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_8 = 2;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_8 = 0xffffffff;
  }
  if (DAT_00fc1074 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fc1074)(1);
    DAT_00fc1074 = (undefined4 *)0x0;
  }
  if ((_DAT_00fc1698 & 1) == 0) {
    _DAT_00fc1698 = _DAT_00fc1698 | 1;
    FUN_0080c8a0();
    _atexit((_func_4879 *)&LAB_00bce320);
  }
  piVar4 = &DAT_00fc16a0;
  do {
    if ((int *)*piVar4 != (int *)0x0) {
      (**(code **)(*(int *)*piVar4 + 8))();
      if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar4)(1);
        *piVar4 = 0;
      }
    }
    iVar2 = DAT_00fba80c;
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0xfc16e0);
  if (DAT_00fba80c != 0) {
    FUN_006f1590(DAT_00fba80c);
    FUN_0089120c(iVar2);
  }
  DAT_00fba80c = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 3;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_005885b0();
  if ((DAT_00faafd4 & 1) == 0) {
    DAT_00faafd4 = DAT_00faafd4 | 1;
    local_8 = 4;
    FUN_0044dfb0();
    _atexit(FUN_00bccd10);
    local_8 = 0xffffffff;
  }
  (**(code **)(DAT_00faafd8 + 0x24))();
  if ((_DAT_00fd8c04 & 1) == 0) {
    _DAT_00fd8c04 = _DAT_00fd8c04 | 1;
    DAT_00fd8c1c = 7;
    DAT_00fd8c18 = 0;
    DAT_00fd8c08._0_2_ = 0;
    _atexit((_func_4879 *)&LAB_00bce360);
  }
  if (DAT_00fd8c18 != 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 5;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_14 = 0x199;
    FUN_005740f0(&local_14);
    if (local_18 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    if (*(uint *)(local_18 + 0x24) < 8) {
      lpCaption = (LPCWSTR)(local_18 + 0x10);
    }
    else {
      lpCaption = *(LPCWSTR *)(local_18 + 0x10);
    }
    lpText = (LPCWSTR)FUN_0048a600();
    if (7 < *(uint *)(lpText + 10)) {
      lpText = *(LPCWSTR *)lpText;
    }
    uType = 0;
    hWnd = (HWND)FUN_006dfd60();
    MessageBoxW(hWnd,lpText,lpCaption,uType);
  }
  ExceptionList = local_10;
  return 0;
}

