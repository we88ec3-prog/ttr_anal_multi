
void FUN_00408170(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (uVar4 = 0, *(int *)(in_ECX + 0xf4) - *(int *)(in_ECX + 0xf0) >> 2 != 0)) {
    do {
      iVar1 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
      if (iVar1 != 0) {
        for (piVar2 = *(int **)(iVar1 + 0xa8); piVar2 != *(int **)(iVar1 + 0xac);
            piVar2 = piVar2 + 1) {
          iVar3 = *piVar2;
          if (*(uint *)(iVar3 + 0x20) == uVar4) goto LAB_004081d0;
        }
      }
      iVar3 = 0;
LAB_004081d0:
      if (*(int *)(iVar3 + 0x20) == *(int *)(param_1 + 8)) {
        FUN_004093d0();
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)(in_ECX + 0xf4) - *(int *)(in_ECX + 0xf0) >> 2));
  }
  return;
}

