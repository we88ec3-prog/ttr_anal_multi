
void FUN_008388d0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = gbDxVB::vftable;
  if ((in_ECX[5] != 0) && (piVar1 = (int *)in_ECX[2], piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x30))(piVar1);
    in_ECX[5] = 0;
  }
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}

