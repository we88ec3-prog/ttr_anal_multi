
void FUN_005541a0(void)

{
  int *unaff_ESI;
  
  if (unaff_ESI[2] != 0) {
    if ((undefined4 *)*unaff_ESI != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*unaff_ESI)(1);
      *unaff_ESI = 0;
    }
    if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)unaff_ESI[1])(1);
      unaff_ESI[1] = 0;
    }
    unaff_ESI[2] = 0;
  }
  return;
}

