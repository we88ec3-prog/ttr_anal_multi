
void FUN_0071bbe0(void)

{
  undefined4 *in_EAX;
  int *in_ECX;
  
  if (*in_ECX != 0) {
    *in_EAX = *(undefined4 *)(*in_ECX + 0x10);
    return;
  }
  *in_EAX = 0;
  return;
}

