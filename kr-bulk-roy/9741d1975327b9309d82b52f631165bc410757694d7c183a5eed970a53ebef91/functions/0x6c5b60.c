
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c5b60(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  undefined2 local_c;
  undefined1 local_a;
  int local_9;
  
  if (in_EAX == (int *)0x0) {
LAB_006c5b98:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006c5b98;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_006c5bcc;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_006c5bcc:
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_9 = piVar2[5];
  local_c = 0x54;
  local_a = 0;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,7);
  }
  return;
}

