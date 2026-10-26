
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b9e80(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  undefined2 local_18;
  int local_16;
  undefined4 local_12;
  undefined2 local_e;
  int local_c;
  undefined4 local_8;
  
  if (in_EAX == (int *)0x0) {
LAB_005b9eb9:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005b9eb9;
    }
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_005b9ee4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_005b9ee4:
  if (in_EAX[5] == 0x6a7) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_c = piVar2[5];
    local_e = 0xcb;
    local_8 = 1;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_e,10);
    }
  }
  if (in_EAX[5] == 0x6a8) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_16 = piVar2[5];
    local_18 = 0xcb;
    local_12 = 0;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_18,10);
    }
  }
  return;
}

