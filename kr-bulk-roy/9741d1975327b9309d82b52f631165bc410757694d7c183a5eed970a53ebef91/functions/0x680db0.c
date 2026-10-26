
void FUN_00680db0(void)

{
  int in_ECX;
  
  FUN_00755e50();
  FUN_00680660();
  FUN_0043c570(21000);
  FUN_00615fc0(0x5a46);
  FUN_00615fc0(0x5aaa);
  FUN_00615fc0(0x5b0e);
  FUN_0043c570(0x5654);
  FUN_006729f0();
  FUN_0043c570(0x834);
  (**(code **)(**(int **)(in_ECX + 0x104) + 0x198))(0x5277);
  *(int *)(*(int *)(in_ECX + 0x104) + 0x298) = in_ECX;
  (**(code **)(**(int **)(in_ECX + 0x10c) + 0x198))(0x5a47);
  (**(code **)(**(int **)(in_ECX + 0x110) + 0x198))(0x5aab);
  (**(code **)(**(int **)(in_ECX + 0x114) + 0x198))(0x5b0f);
  return;
}

