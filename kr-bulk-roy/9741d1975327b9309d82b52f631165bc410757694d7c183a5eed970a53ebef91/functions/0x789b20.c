
void FUN_00789b20(void)

{
  int in_EAX;
  int in_ECX;
  
  for (; in_EAX != 0; in_EAX = in_EAX + -1) {
    if (in_ECX != 0) {
      FUN_007866a0();
    }
    in_ECX = in_ECX + 0x3c;
  }
  return;
}

