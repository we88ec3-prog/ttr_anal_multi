
undefined4 FUN_008db350(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int in_EDX;
  int unaff_ESI;
  
  iVar1 = *(int *)(in_EDX + 8);
  if (iVar1 == 0xb) {
    (**(code **)(in_EDX + 0xc))();
    return *(undefined4 *)(unaff_ESI + 0xc);
  }
  switch(*(undefined4 *)(in_EDX + 4)) {
  case 0:
    break;
  default:
    if ((*(int *)(unaff_ESI + 0x60) < 0) || (*(int *)(in_EAX + 300) <= *(int *)(unaff_ESI + 0x60)))
    {
      return 0xa0;
    }
    break;
  case 2:
    break;
  case 3:
    break;
  case 5:
  }
  if ((iVar1 != 9) && (iVar1 != 10)) {
    uVar2 = (**(code **)(unaff_ESI + 0x40))();
    return uVar2;
  }
  uVar2 = (**(code **)(unaff_ESI + 0x44))();
  return uVar2;
}

