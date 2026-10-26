
int FUN_006abb40(void)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = (int *)*in_EAX;
  iVar1 = in_EAX[1] - (int)piVar4 >> 0x1f;
  iVar3 = (in_EAX[1] - (int)piVar4) / 0x33 + iVar1;
  uVar2 = 0;
  if (iVar3 != iVar1) {
    do {
      if (*piVar4 == unaff_EDI) {
        return uVar2 + 1;
      }
      uVar2 = uVar2 + 1;
      piVar4 = (int *)((int)piVar4 + 0x33);
    } while (uVar2 < (uint)(iVar3 - iVar1));
  }
  return 0;
}

