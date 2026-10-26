
undefined4 * FUN_004f2740(undefined4 *param_1)

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
  uVar2 = *(int *)(in_ECX + 0x5ec0) - *(int *)(in_ECX + 0x5ebc) >> 2;
  if (uVar2 != 0) {
    piVar5 = *(int **)(in_ECX + 0x5ebc);
    do {
      if (*(int *)(*piVar5 + 4) == in_EAX) {
        return *(undefined4 **)(*(int *)(in_ECX + 0x5ebc) + uVar4 * 4);
      }
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar4 < uVar2);
  }
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar3 = (undefined4 *)FUN_00891268(8);
  puVar6 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar6 = puVar3;
  }
  puVar6[1] = in_EAX;
  puVar3 = *(undefined4 **)(in_ECX + 0x5ec0);
  param_1 = puVar6;
  if (&param_1 < puVar3) {
    puVar1 = *(undefined4 **)(in_ECX + 0x5ebc);
    if (puVar1 <= &param_1) {
      if (puVar3 == *(undefined4 **)(in_ECX + 0x5ec4)) {
        FUN_004deab0();
      }
      if (*(undefined4 **)(in_ECX + 0x5ec0) != (undefined4 *)0x0) {
        **(undefined4 **)(in_ECX + 0x5ec0) =
             *(undefined4 *)(*(int *)(in_ECX + 0x5ebc) + ((int)&param_1 - (int)puVar1 >> 2) * 4);
        *(int *)(in_ECX + 0x5ec0) = *(int *)(in_ECX + 0x5ec0) + 4;
        return puVar6;
      }
      goto LAB_004f2835;
    }
  }
  if (puVar3 == *(undefined4 **)(in_ECX + 0x5ec4)) {
    FUN_004deab0();
  }
  if (*(undefined4 **)(in_ECX + 0x5ec0) != (undefined4 *)0x0) {
    **(undefined4 **)(in_ECX + 0x5ec0) = puVar6;
  }
LAB_004f2835:
  *(int *)(in_ECX + 0x5ec0) = *(int *)(in_ECX + 0x5ec0) + 4;
  return puVar6;
}

