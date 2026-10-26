
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059d860(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  undefined2 local_8;
  undefined1 local_6;
  undefined1 local_5;
  
  if (in_EAX == (int *)0x0) {
LAB_0059d897:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0059d897;
    }
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105ba) goto LAB_0059d8c2;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_0059d8c2:
  if (in_EAX[5] == 0x6a7) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    _local_8 = CONCAT13((char)piVar2[6],CONCAT12((char)piVar2[5],0xd8));
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
    }
  }
  return;
}

