
void FUN_007b3b00(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}

