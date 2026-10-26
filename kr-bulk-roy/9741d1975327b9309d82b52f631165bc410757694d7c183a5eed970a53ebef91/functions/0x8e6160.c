
int FUN_008e6160(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  byte *in_ECX;
  uint uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(in_ECX + 8);
  if (in_EAX <= *piVar5) {
    return **(int **)(in_ECX + 4) << 0x10;
  }
  uVar4 = (uint)*in_ECX;
  iVar3 = 1;
  if (1 < uVar4) {
    do {
      piVar5 = piVar5 + 1;
      if (in_EAX <= *piVar5) {
        iVar1 = *(int *)(*(int *)(in_ECX + 8) + -4 + iVar3 * 4);
        piVar5 = (int *)(*(int *)(in_ECX + 4) + iVar3 * 4);
        iVar2 = piVar5[-1];
        iVar3 = FUN_008b7f40(in_EAX - iVar1,*(int *)(*(int *)(in_ECX + 8) + iVar3 * 4) - iVar1);
        return iVar3 * (*piVar5 - iVar2) + iVar2 * 0x10000;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar4);
  }
  return *(int *)(*(int *)(in_ECX + 4) + -4 + uVar4 * 4) << 0x10;
}

