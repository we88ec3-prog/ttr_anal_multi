
void FUN_0061d5c0(void)

{
  int *in_EAX;
  int iVar1;
  int *unaff_ESI;
  
  if (in_EAX == (int *)0x0) {
LAB_0061d5f3:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0061d5f3;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  if (((int *)in_EAX[6] != (int *)0x0) &&
     (iVar1 = (**(code **)(*(int *)in_EAX[6] + 4))(), iVar1 != 0x105b9)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_0075cd30(unaff_ESI[0x45]);
  (**(code **)(*(int *)unaff_ESI[0x45] + 200))();
  if (*(int *)(unaff_ESI[0x45] + 0x24c) != 0) {
    iVar1 = *(int *)(*(int *)(unaff_ESI[0x45] + 0x24c) + 0xcc);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0x20);
      goto LAB_0061d67e;
    }
  }
  iVar1 = -1;
LAB_0061d67e:
  unaff_ESI[0x87] = iVar1;
  unaff_ESI[0x85] = 0;
  FUN_00823850();
  FUN_0061c660();
  (**(code **)(*unaff_ESI + 200))();
  return;
}

