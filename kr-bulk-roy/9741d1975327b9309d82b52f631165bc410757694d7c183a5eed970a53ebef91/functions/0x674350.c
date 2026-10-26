
void FUN_00674350(void)

{
  int in_ECX;
  int iVar1;
  
  FUN_00755e50();
  FUN_0044dd40(52000);
  FUN_0044dd40(61000);
  FUN_0044dd40(62000);
  FUN_00615fc0(70000);
  FUN_00615fc0(80000);
  FUN_00458240(100000);
  FUN_00677fa0(92000);
  FUN_00677fa0(94000);
  FUN_00677fa0(96000);
  FUN_00608b00();
  FUN_0043c570(200000);
  FUN_0043c570(220000);
  FUN_00458240(250000);
  FUN_00615fc0(40000);
  FUN_0043c570(20000);
  FUN_00615fc0(30000);
  FUN_0043c570(270000);
  FUN_00678090();
  FUN_00643ce0(310000);
  FUN_00643ce0(320000);
  FUN_0043c570(97000);
  FUN_00643ce0(330000);
  FUN_00643ce0(340000);
  iVar1 = 0x4bed8;
  do {
    FUN_006c09c0(iVar1);
    iVar1 = iVar1 + 1000;
  } while (iVar1 < 0x4d260);
  (**(code **)(**(int **)(in_ECX + 0x180) + 0x198))(0x3f7a1);
  *(undefined4 *)(*(int *)(in_ECX + 0xf8) + 0x144) = 3;
  *(undefined4 *)(*(int *)(in_ECX + 0xfc) + 0x144) = 3;
  return;
}

