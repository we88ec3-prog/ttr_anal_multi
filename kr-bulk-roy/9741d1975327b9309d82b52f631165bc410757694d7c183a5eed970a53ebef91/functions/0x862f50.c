
void FUN_00862f50(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x38) != 0) {
    do {
      if (*(int *)(in_ECX + 0x38) != 0) {
        uVar3 = *(int *)(in_ECX + 0x34) + -1 + *(int *)(in_ECX + 0x38);
        if (*(uint *)(in_ECX + 0x30) <= uVar3) {
          uVar3 = uVar3 - *(uint *)(in_ECX + 0x30);
        }
        puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x2c) + uVar3 * 4);
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[6] = 0xffffffff;
        puVar2[7] = 0;
        puVar2[8] = 0;
        piVar1 = (int *)(in_ECX + 0x38);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          *(undefined4 *)(in_ECX + 0x34) = 0;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(in_ECX + 0x38));
  }
  return;
}

