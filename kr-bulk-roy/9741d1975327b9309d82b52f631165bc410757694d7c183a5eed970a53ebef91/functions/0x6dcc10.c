
void FUN_006dcc10(void)

{
  int *piVar1;
  int *unaff_ESI;
  
  if (0 < *unaff_ESI) {
    piVar1 = (int *)unaff_ESI[0x23];
    *unaff_ESI = 1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      unaff_ESI[0x23] = 0;
    }
    piVar1 = (int *)unaff_ESI[0x22];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      unaff_ESI[0x22] = 0;
    }
    piVar1 = (int *)unaff_ESI[0x21];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      unaff_ESI[0x21] = 0;
    }
  }
  return;
}

