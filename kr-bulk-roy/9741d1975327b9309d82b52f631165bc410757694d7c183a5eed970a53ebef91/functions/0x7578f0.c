
void FUN_007578f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *unaff_ESI;
  
  unaff_ESI[4] = 0;
  puVar2 = unaff_ESI;
  if (7 < (uint)unaff_ESI[5]) {
    puVar2 = (undefined4 *)*unaff_ESI;
  }
  *(undefined2 *)puVar2 = 0;
  piVar1 = (int *)unaff_ESI[7];
  piVar3 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(undefined4 *)(unaff_ESI[7] + 4) = unaff_ESI[7];
  unaff_ESI[8] = 0;
  if (piVar3 != (int *)unaff_ESI[7]) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != (int *)unaff_ESI[7]);
  }
  FUN_00597b70();
  return;
}

