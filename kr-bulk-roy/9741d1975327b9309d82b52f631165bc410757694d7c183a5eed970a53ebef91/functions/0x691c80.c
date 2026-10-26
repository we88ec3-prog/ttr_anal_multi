
int FUN_00691c80(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_EAX + 0xcc);
  if (iVar1 == 0) {
    return 0;
  }
  piVar3 = *(int **)(iVar1 + 0xa8);
  while( true ) {
    if (piVar3 == *(int **)(iVar1 + 0xac)) {
      return 0;
    }
    iVar2 = *piVar3;
    if (*(int *)(iVar2 + 0x20) == unaff_EDI) break;
    piVar3 = piVar3 + 1;
  }
  if (iVar2 == 0) {
    return 0;
  }
  *(int *)(iVar2 + 0x20) = in_ECX;
  uVar4 = in_ECX + 1U;
  if (in_ECX + 1U <= *(uint *)(iVar1 + 0xe4)) {
    uVar4 = *(uint *)(iVar1 + 0xe4);
  }
  *(uint *)(iVar1 + 0xe4) = uVar4;
  return iVar2;
}

