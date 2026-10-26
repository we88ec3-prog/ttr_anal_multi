
void FUN_0071bb60(void)

{
  undefined4 *in_EAX;
  int *in_ECX;
  
  if (*in_ECX != 0) {
    *in_EAX = *(undefined4 *)(*in_ECX + 4);
    return;
  }
  *in_EAX = 0;
  return;
}

