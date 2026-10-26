
void FUN_00441dd0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int local_8;
  
  FUN_00755e50();
  local_8 = 0;
  iVar2 = 0x97f;
  piVar4 = (int *)(in_ECX + 0x140);
  do {
    FUN_00615fc0(iVar2 + -1);
    (**(code **)(*(int *)*piVar4 + 0x198))(iVar2);
    iVar1 = *piVar4;
    *(int *)(iVar1 + 0x298) = in_ECX;
    *(int *)(iVar1 + 0x29c) = local_8;
    (**(code **)(*(int *)*piVar4 + 0x94))(1);
    local_8 = local_8 + 1;
    iVar2 = iVar2 + 100;
    piVar4 = piVar4 + 1;
  } while (iVar2 < 0xa47);
  FUN_00615fc0(0x91a);
  FUN_00615fc0(0xa46);
  puVar3 = (undefined4 *)(in_ECX + 0x150);
  iVar2 = 0x910;
  do {
    FUN_0046b6f0(iVar2);
    iVar2 = iVar2 + 100;
  } while (iVar2 < 0xaa0);
  FUN_0046b6f0(0x898);
  FUN_0046b6f0(0x91b);
  FUN_0043c570(0x91c);
  FUN_0043c570(0xc8a);
  FUN_00443c20();
  FUN_00615fc0(4000);
  FUN_00615fc0(5000);
  iVar2 = 3;
  do {
    (**(code **)(*(int *)*puVar3 + 0xd8))(0x3f333333);
    (**(code **)(*(int *)*puVar3 + 200))();
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (**(code **)(**(int **)(in_ECX + 0x148) + 0x198))(0x91b);
  (**(code **)(**(int **)(in_ECX + 0x14c) + 0x198))(0xa47);
  return;
}

