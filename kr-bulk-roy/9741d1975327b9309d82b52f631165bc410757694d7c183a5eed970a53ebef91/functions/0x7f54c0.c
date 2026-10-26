
int * FUN_007f54c0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 4);
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    piVar1 = (int *)*piVar1;
  }
  return piVar1;
}

