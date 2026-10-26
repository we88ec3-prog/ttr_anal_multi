
undefined4 FUN_0054a7e0(int param_1)

{
  undefined4 in_EAX;
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  int *piVar3;
  
  uVar2 = 0;
  switch(in_EAX) {
  case 0:
    piVar3 = (int *)(in_ECX + 0xa8 + *(int *)(in_ECX + 0x108) * 0x10);
    break;
  case 1:
    iVar1 = *(int *)(in_ECX + 0x6c);
    piVar3 = (int *)0x0;
    if (iVar1 == 0) {
LAB_0054a88e:
      iVar1 = *(int *)(in_ECX + 0x54);
LAB_0054a84f:
      piVar3 = (int *)0x0;
      if ((iVar1 != 0) && (iVar1 = FUN_005495f0(in_ECX), iVar1 != -1)) {
        piVar3 = (int *)(in_ECX + 0xa8 + iVar1 * 0x10);
      }
    }
    else if ((iVar1 == 1) || (iVar1 == 2)) goto LAB_0054a838;
    break;
  case 2:
    iVar1 = *(int *)(in_ECX + 0x6c);
    piVar3 = (int *)0x0;
    if (iVar1 == 0) {
LAB_0054a838:
      iVar1 = *(int *)(in_ECX + 0x50);
      goto LAB_0054a84f;
    }
    if (iVar1 == 1) goto LAB_0054a88e;
    if (iVar1 == 2) goto LAB_0054a84c;
    break;
  case 3:
    iVar1 = *(int *)(in_ECX + 0x6c);
    piVar3 = (int *)0x0;
    if ((iVar1 == 0) || (iVar1 == 1)) {
LAB_0054a84c:
      iVar1 = *(int *)(in_ECX + 0x58);
      goto LAB_0054a84f;
    }
    if (iVar1 == 2) goto LAB_0054a88e;
    break;
  case 4:
    iVar1 = FUN_005495f0(in_ECX);
    if (iVar1 == -1) {
      return 0;
    }
    piVar3 = (int *)(in_ECX + 0xa8 + iVar1 * 0x10);
    break;
  default:
    goto switchD_0054a7f4_default;
  }
  if (piVar3 != (int *)0x0) {
    if (param_1 == 0) {
      param_1 = *piVar3;
    }
    else if (param_1 == 1) {
      param_1 = piVar3[2];
    }
    else {
      if (param_1 != 2) {
        return 0;
      }
      param_1 = piVar3[3];
    }
    if (param_1 != 0) {
      iVar1 = FUN_0040f060();
      FUN_0082ef00(&param_1);
      if (in_ECX == *(int *)(iVar1 + 0xc)) {
        return 0;
      }
      uVar2 = *(undefined4 *)(in_ECX + 0x10);
    }
  }
switchD_0054a7f4_default:
  return uVar2;
}

