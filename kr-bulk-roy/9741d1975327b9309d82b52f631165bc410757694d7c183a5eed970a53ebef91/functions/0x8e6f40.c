
undefined4 FUN_008e6f40(void)

{
  int in_EAX;
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_ESI;
  
  piVar3 = *(int **)(in_EAX + 0x210);
  if ((piVar3 != (int *)0x0) && (*piVar3 == 0)) {
    piVar3 = (int *)0x0;
  }
  if (*(int *)(unaff_EBX + 8) == 0xb) {
    (**(code **)(unaff_EBX + 0xc))();
    return *(undefined4 *)(unaff_ESI + 0xc);
  }
  switch(*(undefined4 *)(unaff_EBX + 4)) {
  case 2:
  default:
    break;
  case 3:
    piVar1 = (int *)&stack0xfffffff8;
    if (piVar3 != (int *)0x0) {
      piVar1 = piVar3 + 0x24;
    }
    goto LAB_008e6ff0;
  case 4:
    piVar1 = (int *)&stack0xfffffff8;
    if (piVar3 != (int *)0x0) {
      piVar1 = piVar3 + 0x35;
    }
    goto LAB_008e6ff0;
  case 5:
    piVar1 = (int *)&stack0xfffffff8;
    if (piVar3 != (int *)0x0) {
      piVar1 = piVar3 + 0x47;
    }
    goto LAB_008e6ff0;
  case 6:
    break;
  case 8:
  }
  piVar1 = (int *)&stack0xfffffff8;
LAB_008e6ff0:
  if (*piVar1 == 0) {
    return 0;
  }
  if ((*(int *)(unaff_EBX + 8) != 9) && (*(int *)(unaff_EBX + 8) != 10)) {
    uVar2 = (**(code **)(unaff_ESI + 0x40))();
    return uVar2;
  }
  uVar2 = (**(code **)(unaff_ESI + 0x44))();
  return uVar2;
}

