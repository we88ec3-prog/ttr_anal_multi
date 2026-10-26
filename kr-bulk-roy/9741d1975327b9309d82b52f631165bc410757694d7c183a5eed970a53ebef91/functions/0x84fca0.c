
void FUN_0084fca0(int *param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  int *in_EAX;
  int iVar6;
  
  piVar4 = param_1;
  if (in_EAX != param_1) {
    iVar6 = *in_EAX;
    uVar2 = (param_1[1] - *param_1) / 0x14;
    if (uVar2 == 0) {
      param_1 = (int *)uVar2;
      FUN_00850dc0(in_EAX,&param_1,iVar6,in_EAX[1]);
      return;
    }
    uVar3 = (in_EAX[1] - iVar6) / 0x14;
    if (uVar2 <= uVar3) {
      piVar1 = param_1 + 1;
      param_1 = (int *)uVar2;
      FUN_00852560(*piVar1);
      FUN_008508b0(in_EAX[1]);
      in_EAX[1] = *in_EAX + ((piVar4[1] - *piVar4) / 0x14) * 0x14;
      return;
    }
    if (uVar2 <= (uint)((in_EAX[2] - iVar6) / 0x14)) {
      iVar6 = *param_1;
      param_1 = (int *)uVar2;
      FUN_00852560(iVar6 + uVar3 * 0x14);
      iVar6 = FUN_00853cc0(piVar4[1],in_EAX[1],param_1);
      in_EAX[1] = iVar6;
      return;
    }
    param_1 = (int *)uVar2;
    if (iVar6 != 0) {
      FUN_008508b0(in_EAX[1]);
      FUN_0089120c(*in_EAX);
    }
    cVar5 = FUN_00850870();
    if (cVar5 != '\0') {
      iVar6 = FUN_00853cc0(piVar4[1],*in_EAX,param_1);
      in_EAX[1] = iVar6;
    }
  }
  return;
}

