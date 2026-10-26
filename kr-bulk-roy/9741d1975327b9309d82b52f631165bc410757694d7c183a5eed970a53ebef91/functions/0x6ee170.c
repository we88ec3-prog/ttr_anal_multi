
void FUN_006ee170(uint param_1)

{
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if (*unaff_ESI == 0) {
    iVar2 = FUN_0087dc3d(4);
    *unaff_ESI = iVar2;
    unaff_ESI[1] = 2;
    unaff_ESI[2] = 0;
  }
  if ((unaff_EDI <= (uint)unaff_ESI[2]) &&
     (uVar1 = param_1, unaff_EDI + param_1 <= (uint)unaff_ESI[2])) {
    for (; uVar1 < unaff_EDI + param_1; uVar1 = uVar1 + 1) {
      *(undefined2 *)(*unaff_ESI + uVar1 * 2) = 0;
    }
    FUN_006ee010((unaff_ESI[2] - unaff_EDI) - param_1);
    unaff_ESI[2] = unaff_ESI[2] - unaff_EDI;
  }
  return;
}

