
void FUN_004ca030(void)

{
  int *in_ECX;
  int iVar1;
  
  iVar1 = 0x19;
  do {
    in_ECX = in_ECX + 1;
    if (*in_ECX != 0) {
      (**(code **)(*(int *)*in_ECX + 0x10))();
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

