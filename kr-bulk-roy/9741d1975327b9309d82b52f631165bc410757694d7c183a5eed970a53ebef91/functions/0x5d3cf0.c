
void FUN_005d3cf0(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  int local_8;
  
  FUN_005d4270();
  FUN_0046b6f0(0x13ec);
  FUN_0043c570(0x1450);
  FUN_005d3310();
  FUN_0043c570(0x17d4);
  FUN_0046b6f0(0x1838);
  FUN_005d4360();
  FUN_0046b6f0(0x1518);
  local_8 = 0;
  iVar1 = 0x3e9;
  piVar2 = (int *)(in_ECX + 0xa0);
  do {
    FUN_00615fc0(iVar1);
    local_8 = local_8 + 1;
    *(int *)(*piVar2 + 0x2a0) = local_8;
    (**(code **)(*(int *)*piVar2 + 0x198))(iVar1 + 1);
    iVar1 = iVar1 + 1000;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x1389);
  iVar1 = *(int *)(in_ECX + 0x80);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  (**(code **)(**(int **)(in_ECX + 0x9c) + 0x90))(0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x98) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x94) + 0x94))(0);
  return;
}

