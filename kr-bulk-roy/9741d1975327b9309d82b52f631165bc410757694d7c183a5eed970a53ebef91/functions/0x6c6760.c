
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c6760(void)

{
  int iVar1;
  int *unaff_ESI;
  undefined1 local_6 [2];
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bd) goto LAB_006c6792;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_006c6792:
  if (unaff_ESI[5] == 0x6a7) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,local_6,2);
    }
  }
  return;
}

