
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c5fb0(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  
  if (in_EAX == (int *)0x0) {
LAB_006c5fe2:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006c5fe2;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_006c6016;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_006c6016:
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  FUN_004f2980(piVar2[5]);
  return;
}

