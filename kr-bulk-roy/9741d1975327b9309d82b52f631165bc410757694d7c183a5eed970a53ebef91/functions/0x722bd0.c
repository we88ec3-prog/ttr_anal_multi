
void FUN_00722bd0(void)

{
  int *piVar1;
  int *piVar2;
  int *in_EAX;
  int *in_EDX;
  
  piVar2 = in_EAX;
  while ((piVar1 = piVar2 + 2, piVar1 < in_EDX && ((*in_EAX != *piVar1 || (piVar2[1] != piVar2[3])))
         )) {
    in_EAX = in_EAX + 2;
    piVar2 = piVar1;
  }
  piVar2 = in_EAX;
  if (in_EAX != in_EDX) {
    while (in_EAX = in_EAX + 2, in_EAX != in_EDX) {
      if ((*in_EAX != *piVar2) || (in_EAX[1] != piVar2[1])) {
        piVar2[2] = *in_EAX;
        piVar2[3] = in_EAX[1];
        piVar2 = piVar2 + 2;
      }
    }
  }
  return;
}

