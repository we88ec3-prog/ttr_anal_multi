
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c6050(void)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105bd) goto LAB_006c6084;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_006c6084:
  if (in_EAX[5] == 0x6a7) {
    if (((int *)in_EAX[6] != (int *)0x0) &&
       (iVar1 = (**(code **)(*(int *)in_EAX[6] + 4))(), iVar1 != 0x105b9)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    FUN_004a40e0();
  }
  return;
}

