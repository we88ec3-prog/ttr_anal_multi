
void FUN_008fd4d0(void)

{
  int *unaff_ESI;
  
  FUN_00571b10();
  FUN_005719c0();
  if (unaff_ESI[3] != 0) {
    FUN_00571e60();
    unaff_ESI[3] = 0;
  }
  if ((undefined4 *)*unaff_ESI != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*unaff_ESI)(1);
    *unaff_ESI = 0;
  }
  if ((undefined4 *)unaff_ESI[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)unaff_ESI[4])(1);
    unaff_ESI[4] = 0;
  }
  return;
}

