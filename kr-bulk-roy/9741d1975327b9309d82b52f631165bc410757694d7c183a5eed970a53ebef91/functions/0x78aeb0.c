
void FUN_0078aeb0(int param_1)

{
  int in_EAX;
  int in_ECX;
  
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x44) {
    if (in_EAX != 0) {
      FUN_00786620();
    }
    in_EAX = in_EAX + 0x44;
  }
  return;
}

