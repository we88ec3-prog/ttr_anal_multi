
void FUN_006dd790(int *param_1)

{
  uint uVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (in_EAX != param_1) {
    iVar3 = param_1[1] - *param_1 >> 0x1f;
    iVar5 = (param_1[1] - *param_1) / 0xc + iVar3;
    uVar4 = iVar5 - iVar3;
    if (iVar5 == iVar3) {
      FUN_006dd8b0();
      return;
    }
    uVar1 = (in_EAX[1] - *in_EAX) / 0xc;
    if (uVar4 <= uVar1) {
      FUN_006dd8e0(*in_EAX);
      in_EAX[1] = *in_EAX + ((param_1[1] - *param_1) / 0xc) * 0xc;
      return;
    }
    iVar3 = *in_EAX;
    if (uVar4 <= (uint)((in_EAX[2] - *in_EAX) / 0xc)) {
      iVar5 = *param_1;
      FUN_006dd8e0(iVar3);
      iVar3 = FUN_006ee5a0(iVar5 + uVar1 * 0xc,param_1);
      in_EAX[1] = iVar3;
      return;
    }
    if (iVar3 != 0) {
      FUN_0089120c(iVar3);
    }
    cVar2 = FUN_0085e190();
    if (cVar2 != '\0') {
      iVar3 = FUN_006ee5a0(*param_1,param_1);
      in_EAX[1] = iVar3;
    }
  }
  return;
}

