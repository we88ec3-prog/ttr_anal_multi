
void FUN_0062a730(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(*(int *)(in_EAX + 0xec) + 0xcc);
  if ((iVar2 != 0) &&
     (piVar1 = (int *)FUN_00412c70(*(undefined4 *)(iVar2 + 0xe4)), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 0x12d) goto LAB_0062a77e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar1 = (int *)0x0;
LAB_0062a77e:
  *(undefined4 *)(piVar1[0x93] + 0x24c) = 0;
  *(undefined4 *)(piVar1[0x94] + 0x24c) = 0;
  piVar1[0x92] = 0;
  FUN_00757710();
  iVar2 = (**(code **)(*piVar1 + 0x58))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*piVar1 + 0x58))();
    if ((piVar3 != (int *)0x0) && (iVar2 = (**(code **)(*piVar3 + 4))(), iVar2 != 1000)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    FUN_00757710();
    FUN_00754510();
  }
  FUN_00629cd0();
  (**(code **)(*piVar1 + 200))();
  return;
}

