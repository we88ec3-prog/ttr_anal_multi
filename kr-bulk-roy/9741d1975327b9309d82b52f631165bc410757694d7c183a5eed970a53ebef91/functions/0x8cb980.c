
void FUN_008cb980(void)

{
  int *piVar1;
  int *in_ECX;
  int *in_EDX;
  
  piVar1 = (int *)*in_ECX;
  while ((piVar1 != (int *)0x0 && (*piVar1 <= *in_EDX))) {
    in_ECX = piVar1 + 1;
    piVar1 = (int *)*in_ECX;
  }
  in_EDX[1] = (int)piVar1;
  *in_ECX = (int)in_EDX;
  return;
}

