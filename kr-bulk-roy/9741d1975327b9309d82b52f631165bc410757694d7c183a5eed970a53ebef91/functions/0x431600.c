
void FUN_00431600(void)

{
  undefined4 *in_ECX;
  
  if ((void *)*in_ECX != (void *)0x0) {
    _free((void *)*in_ECX);
  }
  *in_ECX = 0;
  return;
}

