
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b04c0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  if (param_1[4] == 0x70b) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      piVar2 = (int *)0x0;
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    param_1 = (int *)CONCAT13((char)piVar2[5] + '\x01',CONCAT21(0xca,param_1._0_1_));
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 1,3);
    }
  }
  return;
}

