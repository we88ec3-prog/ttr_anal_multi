
void FUN_006a12e0(void)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  
  if (in_EAX == (int *)0x0) {
LAB_006a1313:
    in_EAX = (int *)0x0;
  }
  else {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006a1313;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  piVar3 = (int *)in_EAX[6];
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 4))();
    if (iVar2 == 0x105b9) goto LAB_006a1347;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar3 = (int *)0x0;
LAB_006a1347:
  cVar1 = FUN_006a11d0(piVar3[5],piVar3[5] >> 0x1f);
  if (cVar1 != '\0') {
    FUN_004e14f0();
    FUN_00534a30(piVar3[5],piVar3[5] >> 0x1f);
  }
  return;
}

