
void FUN_004d7e80(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *unaff_ESI;
  int *local_10;
  undefined4 local_8;
  
  FUN_00542210();
  piVar1 = (int *)0x0;
  if ((local_10 != (int *)0x0) && ((undefined4 *)*local_10 != (undefined4 *)0x0)) {
    piVar1 = *(int **)*local_10;
  }
  piVar2 = (int *)0x0;
  if ((piVar1 != (int *)0x0) && ((undefined4 *)*piVar1 != (undefined4 *)0x0)) {
    piVar2 = *(int **)*piVar1;
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  if (piVar2 != (int *)0x0) {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      *unaff_ESI = *(undefined4 *)*piVar2;
      unaff_ESI[2] = local_8;
      return;
    }
    unaff_ESI[2] = local_8;
    return;
  }
  unaff_ESI[2] = local_8;
  return;
}

