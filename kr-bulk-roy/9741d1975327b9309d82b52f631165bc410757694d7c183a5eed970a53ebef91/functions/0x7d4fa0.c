
void FUN_007d4fa0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_EAX;
  uint local_8;
  
  iVar3 = param_1;
  if (in_EAX == 0) {
    return;
  }
  *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(param_1 + 0x38);
  local_8 = 0;
  if (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28) >> 2 != 0) {
    do {
      param_1 = (**(code **)(**(int **)(*(int *)(iVar3 + 0x28) + local_8 * 4) + 4))();
      puVar1 = *(undefined4 **)(in_EAX + 0x1c);
      if (&param_1 < puVar1) {
        puVar2 = *(undefined4 **)(in_EAX + 0x18);
        if (&param_1 < puVar2) goto LAB_007d501c;
        if (puVar1 == *(undefined4 **)(in_EAX + 0x20)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(in_EAX + 0x1c) != (undefined4 *)0x0) {
          **(undefined4 **)(in_EAX + 0x1c) =
               *(undefined4 *)(*(int *)(in_EAX + 0x18) + ((int)&param_1 - (int)puVar2 >> 2) * 4);
        }
      }
      else {
LAB_007d501c:
        if (puVar1 == *(undefined4 **)(in_EAX + 0x20)) {
          FUN_00797930();
        }
        if (*(int **)(in_EAX + 0x1c) != (int *)0x0) {
          **(int **)(in_EAX + 0x1c) = param_1;
        }
      }
      *(int *)(in_EAX + 0x1c) = *(int *)(in_EAX + 0x1c) + 4;
      local_8 = local_8 + 1;
    } while (local_8 < (uint)(*(int *)(iVar3 + 0x2c) - *(int *)(iVar3 + 0x28) >> 2));
  }
  *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) + 1;
  return;
}

