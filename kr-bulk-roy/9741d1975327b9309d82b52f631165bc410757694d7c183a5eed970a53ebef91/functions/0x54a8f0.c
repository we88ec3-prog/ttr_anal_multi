
void FUN_0054a8f0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_ESI;
  int local_8;
  
  local_8 = -1;
  iVar2 = 0;
  piVar4 = (int *)(unaff_ESI + 0xa8);
  do {
    iVar5 = iVar2;
    if (*piVar4 == param_1) break;
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 4;
    iVar5 = local_8;
  } while (iVar2 < 3);
  local_8 = iVar5;
  iVar2 = 0;
  piVar4 = (int *)(unaff_ESI + 0xa8);
  do {
    iVar5 = iVar2;
    if (*piVar4 == param_2) break;
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 4;
    iVar5 = -1;
  } while (iVar2 < 3);
  if (local_8 == -1) {
    if (iVar5 == -1) {
      return;
    }
    param_2 = param_1;
    iVar3 = FUN_0040f060();
    FUN_0082ef00(&param_2);
    iVar2 = iRam0000000f;
    if (*(int *)(iVar3 + 0xc) == -1) {
      iVar2 = 0;
    }
    cVar1 = (char)*(undefined2 *)(iVar2 + 4);
    if ((cVar1 != '\x01') && (cVar1 != '\0')) {
      return;
    }
    cVar1 = FUN_004c96b0(iVar2);
    if (cVar1 == '\0') {
      return;
    }
    if (*(int *)(iVar2 + 0x158) == 0) {
      return;
    }
    if (*(int *)(*(int *)(iVar2 + 0x158) + 0x34) != 0) {
      return;
    }
    iVar2 = *(int *)(unaff_ESI + (iVar5 + 0xb) * 0x10);
    *(int *)(unaff_ESI + 0xb4 + iVar5 * 0x10) = param_1;
    if (iVar2 != 0) {
      return;
    }
    *(int *)(unaff_ESI + (iVar5 + 0xb) * 0x10) = param_1;
    return;
  }
  iVar2 = *(int *)(unaff_ESI + 0x6c);
  piVar4 = (int *)0x0;
  if (iVar2 == 0) {
    iVar2 = *(int *)(unaff_ESI + 0x54);
  }
  else {
    if ((iVar2 != 1) && (iVar2 != 2)) goto LAB_0054a97b;
    iVar2 = *(int *)(unaff_ESI + 0x50);
  }
  if (iVar2 == 0) {
    return;
  }
  iVar2 = FUN_005495f0(unaff_ESI);
  if (iVar2 == -1) {
    return;
  }
  piVar4 = (int *)(unaff_ESI + 0xa8 + iVar2 * 0x10);
LAB_0054a97b:
  if ((piVar4 != (int *)0x0) && (*(int *)(unaff_ESI + 0xa8 + local_8 * 0x10) == *piVar4)) {
    if ((local_8 == 0) || (*(int *)(unaff_ESI + 0xb0) == 0)) {
      *(int *)(unaff_ESI + 0xb0) = param_2;
    }
    if ((local_8 == 1) || (*(int *)(unaff_ESI + 0xc0) == 0)) {
      *(int *)(unaff_ESI + 0xc0) = param_2;
    }
    if ((local_8 == 2) || (*(int *)(unaff_ESI + 0xd0) == 0)) {
      *(int *)(unaff_ESI + 0xd0) = param_2;
      return;
    }
  }
  return;
}

