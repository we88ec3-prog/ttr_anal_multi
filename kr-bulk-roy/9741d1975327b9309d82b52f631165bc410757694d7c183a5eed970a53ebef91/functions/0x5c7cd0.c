
void FUN_005c7cd0(int *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *unaff_ESI;
  uint uVar4;
  
  if (unaff_ESI != param_1) {
    iVar2 = *unaff_ESI;
    uVar4 = param_1[1] - *param_1 >> 5;
    if (uVar4 == 0) {
      if (iVar2 != unaff_ESI[1]) {
        iVar2 = FUN_005c7ee0(unaff_ESI[1]);
        FUN_006ab960(param_1);
        unaff_ESI[1] = iVar2;
        return;
      }
    }
    else {
      uVar3 = unaff_ESI[1] - iVar2 >> 5;
      if (uVar4 <= uVar3) {
        FUN_005c7ee0(param_1[1]);
        FUN_006ab960(param_1);
        unaff_ESI[1] = (param_1[1] - *param_1 & 0xffffffe0U) + *unaff_ESI;
        return;
      }
      if (uVar4 <= (uint)(unaff_ESI[2] - iVar2 >> 5)) {
        FUN_005c7ee0(*param_1 + uVar3 * 0x20);
        iVar2 = FUN_005285b0(param_1[1],unaff_ESI[1],param_1);
        unaff_ESI[1] = iVar2;
        return;
      }
      if (iVar2 != 0) {
        FUN_006ab960(param_1);
        FUN_0089120c(*unaff_ESI);
      }
      cVar1 = FUN_005c7de0();
      if (cVar1 != '\0') {
        iVar2 = FUN_005285b0(param_1[1],*unaff_ESI,param_1);
        unaff_ESI[1] = iVar2;
      }
    }
  }
  return;
}

