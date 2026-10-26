
void FUN_00872f80(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *in_EAX;
  int *unaff_EDI;
  
  for (; in_EAX != unaff_EDI; in_EAX = in_EAX + 1) {
    puVar2 = (undefined4 *)*in_EAX;
    if (puVar2 != (undefined4 *)0x0) {
      piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*puVar2)(1);
      }
    }
  }
  return;
}

