
int FUN_00574a80(int param_1)

{
  int in_EAX;
  int in_ECX;
  
  for (; in_EAX != param_1; in_EAX = in_EAX + 0x1c) {
    FUN_00403040(in_EAX,0,0xffffffff);
    in_ECX = in_ECX + 0x1c;
  }
  return in_ECX;
}

