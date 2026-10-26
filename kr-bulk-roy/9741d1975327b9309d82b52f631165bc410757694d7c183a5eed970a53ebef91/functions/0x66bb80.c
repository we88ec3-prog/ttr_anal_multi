
int * FUN_0066bb80(void)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
  
  iVar3 = *(int *)(in_EAX + 0x100) - *(int *)(in_EAX + 0xfc);
  iVar1 = iVar3 >> 0x1f;
  iVar3 = iVar3 / 0x50 + iVar1;
  uVar2 = 0;
  if (iVar3 != iVar1) {
    piVar4 = *(int **)(in_EAX + 0xfc);
    do {
      if (*piVar4 == unaff_EDI) {
        return *(int **)(in_EAX + 0xfc) + uVar2 * 0x14;
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 0x14;
    } while (uVar2 < (uint)(iVar3 - iVar1));
  }
  return (int *)0x0;
}

