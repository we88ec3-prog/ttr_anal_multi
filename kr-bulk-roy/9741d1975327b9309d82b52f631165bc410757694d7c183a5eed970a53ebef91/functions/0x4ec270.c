
undefined4 * FUN_004ec270(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  uVar4 = 0;
  uVar2 = *(int *)(in_ECX + 0x5eb0) - *(int *)(in_ECX + 0x5eac) >> 2;
  if (uVar2 != 0) {
    piVar5 = *(int **)(in_ECX + 0x5eac);
    do {
      if (*(int *)(*piVar5 + 4) == in_EAX) {
        return *(undefined4 **)(*(int *)(in_ECX + 0x5eac) + uVar4 * 4);
      }
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar4 < uVar2);
  }
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  puVar6 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0;
    puVar3[1] = 0;
    *(undefined1 *)(puVar3 + 2) = 0;
    puVar3[6] = 0;
    *(undefined4 *)((int)puVar3 + 10) = 0;
    *(undefined1 *)((int)puVar3 + 0xe) = 10;
    *(undefined2 *)(puVar3 + 4) = 0;
    *(undefined1 *)((int)puVar3 + 0x12) = 0;
    *(undefined2 *)(puVar3 + 5) = 0;
    *(undefined1 *)((int)puVar3 + 0x16) = 3;
    puVar6 = puVar3;
  }
  puVar6[1] = in_EAX;
  puVar3 = *(undefined4 **)(in_ECX + 0x5eb0);
  param_1 = puVar6;
  if (&param_1 < puVar3) {
    puVar1 = *(undefined4 **)(in_ECX + 0x5eac);
    if (puVar1 <= &param_1) {
      if (puVar3 == *(undefined4 **)(in_ECX + 0x5eb4)) {
        FUN_004deab0();
      }
      if (*(undefined4 **)(in_ECX + 0x5eb0) != (undefined4 *)0x0) {
        **(undefined4 **)(in_ECX + 0x5eb0) =
             *(undefined4 *)(*(int *)(in_ECX + 0x5eac) + ((int)&param_1 - (int)puVar1 >> 2) * 4);
        *(int *)(in_ECX + 0x5eb0) = *(int *)(in_ECX + 0x5eb0) + 4;
        return puVar6;
      }
      goto LAB_004ec385;
    }
  }
  if (puVar3 == *(undefined4 **)(in_ECX + 0x5eb4)) {
    FUN_004deab0();
  }
  if (*(undefined4 **)(in_ECX + 0x5eb0) != (undefined4 *)0x0) {
    **(undefined4 **)(in_ECX + 0x5eb0) = puVar6;
  }
LAB_004ec385:
  *(int *)(in_ECX + 0x5eb0) = *(int *)(in_ECX + 0x5eb0) + 4;
  return puVar6;
}

