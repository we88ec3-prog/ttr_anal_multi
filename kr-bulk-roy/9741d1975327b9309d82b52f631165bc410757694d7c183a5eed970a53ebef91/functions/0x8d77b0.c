
undefined4 FUN_008d77b0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 == 0xb) {
    (**(code **)(in_EAX + 0xc))();
    return *(undefined4 *)(unaff_ESI + 0xc);
  }
  if ((iVar1 != 9) && (iVar1 != 10)) {
    uVar2 = (**(code **)(unaff_ESI + 0x40))();
    return uVar2;
  }
  uVar2 = (**(code **)(unaff_ESI + 0x44))();
  return uVar2;
}

