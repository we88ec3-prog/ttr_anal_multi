
int * FUN_00745c40(void)

{
  char cVar1;
  int *in_EAX;
  
  cVar1 = (**(code **)(*in_EAX + 0x88))();
  while( true ) {
    if (cVar1 != '\0') {
      return in_EAX;
    }
    in_EAX = (int *)in_EAX[0x18];
    if (in_EAX == (int *)0x0) break;
    cVar1 = (**(code **)(*in_EAX + 0x88))();
  }
  return (int *)0x0;
}

