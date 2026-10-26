
void FUN_00832ec0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_EAX;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  
  iVar3 = param_1;
  uVar5 = 0;
  uVar4 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2;
  if (uVar4 != 0) {
    piVar6 = *(int **)(in_EAX + 4);
    do {
      if (*piVar6 == param_1) {
        return;
      }
      uVar5 = uVar5 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar5 < uVar4);
  }
  puVar1 = *(undefined4 **)(in_EAX + 8);
  if (&param_1 < puVar1) {
    puVar2 = *(undefined4 **)(in_EAX + 4);
    if (puVar2 <= &param_1) {
      if (puVar1 == *(undefined4 **)(in_EAX + 0xc)) {
        FUN_006d6240();
      }
      if (*(undefined4 **)(in_EAX + 8) != (undefined4 *)0x0) {
        **(undefined4 **)(in_EAX + 8) =
             *(undefined4 *)(*(int *)(in_EAX + 4) + ((int)&param_1 - (int)puVar2 >> 2) * 4);
        *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 4;
        return;
      }
      goto LAB_00832f4d;
    }
  }
  if (puVar1 == *(undefined4 **)(in_EAX + 0xc)) {
    FUN_006d6240();
  }
  if (*(int **)(in_EAX + 8) != (int *)0x0) {
    **(int **)(in_EAX + 8) = iVar3;
  }
LAB_00832f4d:
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 4;
  return;
}

