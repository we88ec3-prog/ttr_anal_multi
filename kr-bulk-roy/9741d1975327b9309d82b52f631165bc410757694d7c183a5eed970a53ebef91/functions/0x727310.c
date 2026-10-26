
undefined4 FUN_00727310(void)

{
  uint in_EAX;
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
    if (*(int *)(unaff_ESI + 0x20) == 0) {
      *(code **)(unaff_ESI + 0x20) = FUN_0072b9c0;
      *(undefined4 *)(unaff_ESI + 0x28) = 0;
    }
    if (*(int *)(unaff_ESI + 0x24) == 0) {
      *(code **)(unaff_ESI + 0x24) = FUN_0072b9e0;
    }
    iVar1 = (**(code **)(unaff_ESI + 0x20))(*(undefined4 *)(unaff_ESI + 0x28),1,0x2530);
    if (iVar1 == 0) {
      return 0xfffffffc;
    }
    *(int *)(unaff_ESI + 0x1c) = iVar1;
    if ((int)in_EAX < 0) {
      *(undefined4 *)(iVar1 + 8) = 0;
      in_EAX = -in_EAX;
    }
    else {
      *(int *)(iVar1 + 8) = ((int)in_EAX >> 4) + 1;
      if ((int)in_EAX < 0x30) {
        in_EAX = in_EAX & 0xf;
      }
    }
    if (in_EAX - 8 < 8) {
      *(uint *)(iVar1 + 0x24) = in_EAX;
      *(undefined4 *)(iVar1 + 0x34) = 0;
      uVar2 = FUN_007272b0();
      return uVar2;
    }
    (**(code **)(unaff_ESI + 0x24))(*(undefined4 *)(unaff_ESI + 0x28),iVar1);
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  }
  return 0xfffffffe;
}

