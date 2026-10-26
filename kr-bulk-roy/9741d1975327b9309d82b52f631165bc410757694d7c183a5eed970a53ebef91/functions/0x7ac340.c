
void FUN_007ac340(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  undefined4 *puVar3;
  
  uVar1 = unaff_ESI[1] - *unaff_ESI >> 2;
  if (uVar1 < 0xb) {
    if (uVar1 < 10) {
      FUN_0079bf10();
      puVar3 = (undefined4 *)unaff_ESI[1];
      iVar2 = 10 - ((int)puVar3 - *unaff_ESI >> 2);
      if (iVar2 != 0) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
      }
      unaff_ESI[1] = unaff_ESI[1] + (10 - (unaff_ESI[1] - *unaff_ESI >> 2)) * 4;
    }
    return;
  }
  FUN_004088c0(unaff_ESI,*unaff_ESI + 0x28,unaff_ESI[1]);
  return;
}

