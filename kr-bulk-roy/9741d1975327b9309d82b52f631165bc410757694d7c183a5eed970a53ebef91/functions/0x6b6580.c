
void FUN_006b6580(void)

{
  int in_ECX;
  
  FUN_0040f570(200);
  FUN_0040f570(300);
  *(undefined4 *)(*(int *)(in_ECX + 0x80) + 0xd8) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x84) + 0xd8) = 0;
  return;
}

