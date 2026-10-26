
int FUN_006a3320(void)

{
  int in_EAX;
  
  if (0x7fffffff < in_EAX) {
    return 0x7fffffff;
  }
  if (in_EAX < -0x80000000) {
    in_EAX = -0x80000000;
  }
  return in_EAX;
}

