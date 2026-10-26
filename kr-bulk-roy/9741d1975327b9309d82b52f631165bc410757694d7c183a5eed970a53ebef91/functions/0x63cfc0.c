
int FUN_0063cfc0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int in_EDX;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0xcc);
  if (iVar1 == 0) {
    return 0;
  }
  if ((-1 < in_EAX) && (in_EAX < *(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2)) {
    iVar2 = *(int *)(*(int *)(iVar1 + 0xa8) + in_EAX * 4);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x20) = in_EDX;
      uVar3 = in_EDX + 1U;
      if (in_EDX + 1U <= *(uint *)(iVar1 + 0xe4)) {
        uVar3 = *(uint *)(iVar1 + 0xe4);
      }
      *(uint *)(iVar1 + 0xe4) = uVar3;
      return iVar2;
    }
  }
  return 0;
}

