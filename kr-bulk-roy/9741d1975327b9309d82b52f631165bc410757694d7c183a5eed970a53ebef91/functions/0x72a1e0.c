
uint FUN_0072a1e0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  if ((unaff_ESI == 0) || (iVar1 = *(int *)(unaff_ESI + 0x1c), iVar1 == 0)) {
    return 0xfffffffe;
  }
  iVar2 = *(int *)(iVar1 + 4);
  if ((((iVar2 != 0x2a) && (iVar2 != 0x45)) && (iVar2 != 0x49)) &&
     (((iVar2 != 0x5b && (iVar2 != 0x67)) && ((iVar2 != 0x71 && (iVar2 != 0x29a)))))) {
    return 0xfffffffe;
  }
  if (*(int *)(iVar1 + 8) != 0) {
    (**(code **)(unaff_ESI + 0x24))(*(undefined4 *)(unaff_ESI + 0x28),*(int *)(iVar1 + 8));
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x44);
  if (iVar1 != 0) {
    (**(code **)(unaff_ESI + 0x24))(*(undefined4 *)(unaff_ESI + 0x28),iVar1);
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x40);
  if (iVar1 != 0) {
    (**(code **)(unaff_ESI + 0x24))(*(undefined4 *)(unaff_ESI + 0x28),iVar1);
  }
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x38);
  if (iVar1 != 0) {
    (**(code **)(unaff_ESI + 0x24))(*(undefined4 *)(unaff_ESI + 0x28),iVar1);
  }
  (**(code **)(unaff_ESI + 0x24))
            (*(undefined4 *)(unaff_ESI + 0x28),*(undefined4 *)(unaff_ESI + 0x1c));
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  return (iVar2 != 0x71) - 1 & 0xfffffffd;
}

