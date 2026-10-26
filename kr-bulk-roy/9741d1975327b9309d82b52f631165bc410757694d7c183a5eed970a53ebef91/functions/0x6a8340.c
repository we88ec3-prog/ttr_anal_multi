
void FUN_006a8340(void)

{
  int in_ECX;
  
  FUN_00755e50();
  FUN_0063b9e0();
  FUN_00619ae0();
  FUN_00615fc0(30000);
  FUN_00615fc0(40000);
  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x144) = 10;
  *(undefined1 *)(*(int *)(in_ECX + 0xf4) + 0xca) = 1;
  return;
}

