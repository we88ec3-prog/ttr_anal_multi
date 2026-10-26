
void FUN_008edc30(void)

{
  int *in_EAX;
  int in_ECX;
  
  if (-1 < *in_EAX) {
    *(int *)(in_ECX + 0x154) = *in_EAX;
  }
  return;
}

