
void FUN_00480dd0(void)

{
  int in_ECX;
  
  FUN_00755e50();
  FUN_006729f0();
  FUN_00615fc0(0x52da);
  FUN_00615fc0(0x5276);
  FUN_00451db0();
  FUN_0043c570(24000);
  FUN_0043c570(0x56b8);
  FUN_0043c570(30000);
  FUN_0043c570(40000);
  FUN_0043c570(20000);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x198))(0x52db);
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0x198))(0x5277);
  *(int *)(*(int *)(in_ECX + 0xf8) + 0x298) = in_ECX;
  *(int *)(*(int *)(in_ECX + 0xfc) + 0x298) = in_ECX;
  *(undefined1 *)(*(int *)(in_ECX + 0xf8) + 0x29c) = 1;
  *(undefined1 *)(*(int *)(in_ECX + 0xfc) + 0x29c) = 0;
  (**(code **)(**(int **)(in_ECX + 0x10c) + 0x94))(0);
  return;
}

