
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059d6f0(void)

{
  int iVar1;
  int *unaff_ESI;
  undefined2 local_c;
  undefined4 local_a;
  undefined1 local_6;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bd) goto LAB_0059d724;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059d724:
  if (unaff_ESI[5] == 0x6a7) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_c = 0x8b;
    local_a = 0;
    local_6 = 0;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,7);
    }
  }
  return;
}

