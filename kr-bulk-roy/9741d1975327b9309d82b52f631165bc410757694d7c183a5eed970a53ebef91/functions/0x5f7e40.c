
void FUN_005f7e40(uint param_1)

{
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  undefined4 *puVar3;
  
  uVar1 = unaff_ESI[1] - *unaff_ESI >> 2;
  if (uVar1 <= param_1) {
    if (uVar1 < param_1) {
      FUN_006d6240();
      puVar3 = (undefined4 *)unaff_ESI[1];
      iVar2 = param_1 - ((int)puVar3 - *unaff_ESI >> 2);
      if (iVar2 != 0) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
      }
      unaff_ESI[1] = unaff_ESI[1] + (param_1 - (unaff_ESI[1] - *unaff_ESI >> 2)) * 4;
    }
    return;
  }
  FUN_004088c0(unaff_ESI,*unaff_ESI + param_1 * 4,unaff_ESI[1]);
  return;
}

