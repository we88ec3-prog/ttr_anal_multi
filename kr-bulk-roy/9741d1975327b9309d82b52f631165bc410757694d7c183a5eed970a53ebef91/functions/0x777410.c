
undefined4 FUN_00777410(void)

{
  ushort uVar1;
  ushort *in_EAX;
  int iVar2;
  
  uVar1 = *in_EAX;
  if (((0xe00 < uVar1) && (uVar1 < 0xe5c)) && (0xe2e < uVar1)) {
    if ((uVar1 == 0xe2f) || (uVar1 == 0xe3f)) {
      return 2;
    }
    if ((0xe3f < uVar1) && (uVar1 < 0xe45)) {
      return 3;
    }
    if ((0xe4f < uVar1) && (uVar1 < 0xe5a)) {
      return 4;
    }
    if (uVar1 == 0xe30) {
      return 5;
    }
    iVar2 = FUN_007771a0();
    if (iVar2 != 0) {
      return 5;
    }
    if ((uVar1 == 0xe31) || ((0xe33 < uVar1 && (uVar1 < 0xe38)))) {
      return 6;
    }
    if ((0xe37 < uVar1) && (uVar1 < 0xe3a)) {
      return 7;
    }
    if ((uVar1 == 0xe47) || (uVar1 == 0xe4c)) {
      return 8;
    }
    if ((0xe47 < uVar1) && (uVar1 < 0xe4c)) {
      return 9;
    }
  }
  return 1;
}

