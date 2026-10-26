
undefined4 FUN_0041d5c0(void)

{
  int *piVar1;
  int *in_EAX;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar1 = (int *)*in_EAX;
  uVar2 = in_EAX[1] - (int)piVar1 >> 3;
  uVar3 = 0;
  piVar4 = piVar1;
  if (uVar2 != 0) {
    do {
      if (*piVar4 == unaff_EDI) {
        return CONCAT22((short)(in_EAX[1] - (int)piVar1 >> 0x13),(short)piVar1[uVar3 * 2 + 1]);
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 2;
    } while (uVar3 < uVar2);
  }
  return 0;
}

