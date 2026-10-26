
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c6310(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  undefined2 local_c;
  int local_a;
  
  if (in_EAX == (int *)0x0) {
LAB_006c6348:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006c6348;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_006c637c;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_006c637c:
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_a = piVar2[5];
  local_c = 0xbe;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,6);
  }
  return;
}

