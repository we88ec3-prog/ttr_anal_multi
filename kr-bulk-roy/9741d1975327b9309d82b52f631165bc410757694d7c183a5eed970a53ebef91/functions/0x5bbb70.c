
void FUN_005bbb70(int param_1)

{
  char cVar1;
  int iVar2;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_ESI + 4))();
    if (iVar2 == 0x105b9) goto LAB_005bbba4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005bbba4:
  cVar1 = (char)unaff_ESI[5];
  iVar2 = *(int *)(param_1 + 0x2c0);
  if (cVar1 == '\0') {
    FUN_0043d930(*(undefined4 *)(iVar2 + 0xf8));
  }
  else {
    if (cVar1 == '\x01') {
      FUN_004395a0(*(undefined4 *)(iVar2 + 0x100));
      return;
    }
    if (cVar1 == '\x02') {
      FUN_00437f10(*(undefined4 *)(iVar2 + 0xfc));
      return;
    }
  }
  return;
}

