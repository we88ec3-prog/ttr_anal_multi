
void FUN_00684010(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  undefined4 *puVar3;
  
  uVar1 = unaff_ESI[1] - *unaff_ESI >> 2;
  if (uVar1 < 10) {
    if (uVar1 < 9) {
      FUN_006d6240();
      puVar3 = (undefined4 *)unaff_ESI[1];
      iVar2 = 9 - ((int)puVar3 - *unaff_ESI >> 2);
      if (iVar2 != 0) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
      }
      unaff_ESI[1] = unaff_ESI[1] + (9 - (unaff_ESI[1] - *unaff_ESI >> 2)) * 4;
    }
    return;
  }
  FUN_004088c0(unaff_ESI,*unaff_ESI + 0x24,unaff_ESI[1]);
  return;
}

