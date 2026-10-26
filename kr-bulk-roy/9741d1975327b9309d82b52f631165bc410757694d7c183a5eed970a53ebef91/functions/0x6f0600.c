
void FUN_006f0600(void)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  
  FUN_006f0f40();
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_EAX + 3));
  piVar1 = (int *)*in_EAX;
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*in_EAX + 4) = *in_EAX;
  in_EAX[1] = 0;
  if (piVar2 != (int *)*in_EAX) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*in_EAX);
  }
  FUN_0089120c(*in_EAX);
  return;
}

