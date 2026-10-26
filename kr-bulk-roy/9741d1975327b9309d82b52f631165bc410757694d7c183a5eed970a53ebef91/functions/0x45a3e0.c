
void FUN_0045a3e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    uVar4 = 0;
    if (*(int *)(in_ECX + 0xf4) - *(int *)(in_ECX + 0xf0) >> 2 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
        if (iVar1 != 0) {
          for (piVar2 = *(int **)(iVar1 + 0xa8); piVar2 != *(int **)(iVar1 + 0xac);
              piVar2 = piVar2 + 1) {
            iVar3 = *piVar2;
            if (*(uint *)(iVar3 + 0x20) == uVar4) goto LAB_0045a460;
          }
        }
        iVar3 = 0;
LAB_0045a460:
        if (((*(int *)(iVar3 + 0x20) == *(int *)(param_1 + 8)) &&
            (iVar1 = *(int *)(*(int *)(in_ECX + 0xf0) + uVar4 * 4), *(int *)(iVar1 + 0x2c0) != -1))
           && (*(int *)(iVar1 + 0x2c4) != -1)) {
          FUN_0045a210(iVar1);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(*(int *)(in_ECX + 0xf4) - *(int *)(in_ECX + 0xf0) >> 2));
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0xf4420) {
    FUN_0045acd0();
    return;
  }
  return;
}

