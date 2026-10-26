
void FUN_00645420(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_EAX;
  int *piVar5;
  int local_c;
  
  piVar5 = (int *)(in_EAX + 0x128);
  local_c = 5;
  do {
    FUN_00776380(param_1);
    piVar1 = *(int **)(*piVar5 + 0x118);
    puVar2 = (undefined4 *)piVar1[0x19];
    for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
      iVar4 = puVar3[2];
      if ((*(int *)(iVar4 + 0x60) != 0) && ((*(int **)(iVar4 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar4 + 0x1c) + 0x30))(iVar4);
      }
    }
    (**(code **)(*piVar1 + 0x128))();
    piVar5 = piVar5 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  return;
}

