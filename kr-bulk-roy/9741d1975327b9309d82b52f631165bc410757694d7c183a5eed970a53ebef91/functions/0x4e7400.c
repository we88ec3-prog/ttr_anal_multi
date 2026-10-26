
void FUN_004e7400(void)

{
  uint *in_EAX;
  int in_ECX;
  uint local_c;
  
  for (; in_ECX != 0; in_ECX = in_ECX + -1) {
    local_c = local_c & 0xffff0000;
    if (in_EAX != (uint *)0x0) {
      *in_EAX = local_c;
      in_EAX[1] = 0;
    }
    in_EAX = in_EAX + 2;
  }
  return;
}

