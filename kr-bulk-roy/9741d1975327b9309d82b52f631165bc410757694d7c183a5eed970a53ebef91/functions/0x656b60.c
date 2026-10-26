
void FUN_00656b60(void)

{
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_10;
  
  puVar1 = (undefined4 *)(in_ECX + 200);
  puVar2 = (undefined4 *)(in_ECX + 0xe8);
  local_10 = 4;
  do {
    iVar3 = 5;
    do {
      (**(code **)(*(int *)*puVar2 + 0x1ac))(0xffffffff,0xffffffff,0,0,0xffffffff);
      (**(code **)(*(int *)*puVar2 + 200))();
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    (**(code **)(*(int *)puVar1[4] + 0x94))(0);
    (**(code **)(*(int *)*puVar1 + 0x94))(0);
    puVar1 = puVar1 + 1;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  *(undefined1 *)(in_ECX + 0xa8) = 0;
  (**(code **)(**(int **)(in_ECX + 0xac) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0xb0) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0xb4) + 0x94))(1);
  return;
}

