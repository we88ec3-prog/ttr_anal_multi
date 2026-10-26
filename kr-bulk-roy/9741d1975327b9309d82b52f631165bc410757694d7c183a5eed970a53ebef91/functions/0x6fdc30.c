
void FUN_006fdc30(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int in_EDX;
  
  *(uint *)(in_ECX + 8) = (*(int *)(in_ECX + 8) - in_EDX & 0xfffffff0U) + *(int *)(in_ECX + 0x20);
  for (puVar1 = *(undefined4 **)(in_ECX + 0x68); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    puVar1[2] = (puVar1[2] - in_EDX & 0xfffffff0U) + *(int *)(in_ECX + 0x20);
  }
  piVar2 = *(int **)(in_ECX + 0x28);
  if (*(int **)(in_ECX + 0x28) <= *(int **)(in_ECX + 0x14)) {
    do {
      piVar3 = piVar2 + 6;
      piVar2[2] = (piVar2[2] - in_EDX & 0xfffffff0U) + *(int *)(in_ECX + 0x20);
      *piVar2 = (*piVar2 - in_EDX & 0xfffffff0U) + *(int *)(in_ECX + 0x20);
      piVar2[1] = (piVar2[1] - in_EDX & 0xfffffff0U) + *(int *)(in_ECX + 0x20);
      piVar2 = piVar3;
    } while (piVar3 <= *(int **)(in_ECX + 0x14));
  }
  *(uint *)(in_ECX + 0xc) =
       (*(int *)(in_ECX + 0xc) - in_EDX & 0xfffffff0U) + *(int *)(in_ECX + 0x20);
  return;
}

