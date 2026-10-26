
void FUN_0067b910(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  int local_8;
  
  FUN_00755e50();
  FUN_0067d5b0();
  FUN_0040ce30();
  FUN_0043c570(25000);
  FUN_0043c570(26000);
  FUN_0043c570(0x5654);
  FUN_006729f0();
  FUN_0043c570(27000);
  FUN_0043c570(0x960);
  local_8 = 0;
  iVar1 = 0x5276;
  piVar2 = (int *)(in_ECX + 0xfc);
  do {
    FUN_00615fc0(iVar1);
    *(int *)(*piVar2 + 0x29c) = in_ECX;
    *(int *)(*piVar2 + 0x298) = local_8;
    (**(code **)(*(int *)*piVar2 + 0x198))(iVar1 + 1);
    local_8 = local_8 + 1;
    iVar1 = iVar1 + 100;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x533e);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x198))(0x533f);
  (**(code **)(**(int **)(in_ECX + 0x104) + 0x198))(0x6217);
  return;
}

