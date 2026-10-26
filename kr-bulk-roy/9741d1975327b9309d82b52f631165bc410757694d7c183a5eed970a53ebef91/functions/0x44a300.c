
void FUN_0044a300(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  uVar2 = 0;
  uVar1 = *(int *)(unaff_EDI + 0x10c) - *(int *)(unaff_EDI + 0x108) >> 2;
  if (uVar1 != 0) {
    puVar3 = *(undefined4 **)(unaff_EDI + 0x108);
    do {
      if (*(int *)*puVar3 == *(int *)(*(int *)(unaff_EDI + 0x104) + 0x11c)) goto LAB_0044a344;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < uVar1);
  }
  uVar2 = 0xffffffff;
LAB_0044a344:
  if (param_1 < 1) {
    if (-1 < param_1) goto LAB_0044a365;
    if ((int)uVar2 < 1) {
      uVar2 = uVar1 - 1;
      goto LAB_0044a365;
    }
  }
  else if (uVar1 - 1 <= uVar2) {
    uVar2 = 0;
    goto LAB_0044a365;
  }
  uVar2 = uVar2 + param_1;
LAB_0044a365:
  FUN_00446b30(**(undefined4 **)(*(int *)(unaff_EDI + 0x108) + uVar2 * 4));
  FUN_0044a3a0(unaff_EDI,**(undefined4 **)(*(int *)(unaff_EDI + 0x108) + uVar2 * 4));
  return;
}

