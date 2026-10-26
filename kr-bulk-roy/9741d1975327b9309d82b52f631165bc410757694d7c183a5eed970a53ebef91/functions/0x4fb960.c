
int FUN_004fb960(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int unaff_EDI;
  
  iVar2 = *(int *)(in_EAX + 0xc) - *(int *)(in_EAX + 8);
  iVar1 = iVar2 >> 0x1f;
  iVar2 = iVar2 / 0x3c + iVar1;
  uVar3 = 0;
  if (iVar2 != iVar1) {
    piVar4 = (int *)(*(int *)(in_EAX + 8) + 0xc);
    do {
      if ((piVar4[-2] == param_1) && (*piVar4 == unaff_EDI)) {
        return *(int *)(in_EAX + 8) + uVar3 * 0x3c;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 0xf;
    } while (uVar3 < (uint)(iVar2 - iVar1));
  }
  return 0;
}

