
void FUN_00841790(void)

{
  int *piVar1;
  int *in_EAX;
  int *unaff_EDI;
  
  for (; in_EAX != unaff_EDI; in_EAX = in_EAX + 0xd) {
    piVar1 = (int *)*in_EAX;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *in_EAX = 0;
    }
  }
  return;
}

