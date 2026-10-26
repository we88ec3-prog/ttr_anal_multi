
void FUN_00839400(void)

{
  int *piVar1;
  undefined4 *unaff_ESI;
  
  piVar1 = (int *)unaff_ESI[0x14];
  *(undefined8 *)(unaff_ESI + 0x10) = 0;
  unaff_ESI[0x13] = 4;
  *unaff_ESI = 0;
  unaff_ESI[0xf] = 0;
  unaff_ESI[0x12] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    unaff_ESI[0x14] = 0;
  }
  piVar1 = (int *)unaff_ESI[0x15];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    unaff_ESI[0x15] = 0;
  }
  piVar1 = (int *)unaff_ESI[0x16];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    unaff_ESI[0x16] = 0;
  }
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0xe] = 0;
  return;
}

