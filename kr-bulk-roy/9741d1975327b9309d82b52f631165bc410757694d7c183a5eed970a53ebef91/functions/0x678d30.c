
void FUN_00678d30(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00755e50();
  FUN_006729f0();
  FUN_0043c570(21000);
  FUN_00680660();
  FUN_0043c570(0xaf0);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x198))(0x5277);
  iVar1 = 0x5655;
  puVar2 = (undefined4 *)(in_ECX + 0x100);
  do {
    FUN_00615fc0(iVar1);
    (**(code **)(*(int *)*puVar2 + 0x198))(iVar1 + 1);
    iVar1 = iVar1 + 100;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x5849);
  return;
}

