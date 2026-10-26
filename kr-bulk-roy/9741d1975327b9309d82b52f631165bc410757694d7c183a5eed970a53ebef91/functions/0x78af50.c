
void FUN_0078af50(int param_1)

{
  int in_EAX;
  int in_ECX;
  
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x3c) {
    if (in_EAX != 0) {
      FUN_007866a0();
    }
    in_EAX = in_EAX + 0x3c;
  }
  return;
}

