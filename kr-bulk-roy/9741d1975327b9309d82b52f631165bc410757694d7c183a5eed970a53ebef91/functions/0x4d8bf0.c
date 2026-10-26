
void FUN_004d8bf0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  int *in_EDX;
  
  piVar1 = (int *)*in_EDX;
  *in_EAX = 0;
  in_EAX[1] = 0;
  if ((piVar1 != (int *)0x0) && (puVar2 = (undefined4 *)*piVar1, puVar2 != (undefined4 *)0x0)) {
    *in_EAX = *puVar2;
  }
  in_EAX[2] = in_EDX[2];
  return;
}

