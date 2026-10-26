
void FUN_007a0e20(int *param_1)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (in_EAX != param_1) {
    uVar3 = param_1[1] - *param_1 >> 3;
    if (uVar3 == 0) {
      if (*in_EAX != in_EAX[1]) {
        iVar2 = FUN_007a3720(in_EAX[1],*in_EAX,param_1);
        FUN_007a37a0(in_EAX[1],param_1);
        in_EAX[1] = iVar2;
        return;
      }
    }
    else {
      iVar2 = *in_EAX;
      uVar4 = in_EAX[1] - iVar2 >> 3;
      if (uVar3 <= uVar4) {
        FUN_007a3650(*param_1,param_1[1],param_1);
        FUN_007a37a0(in_EAX[1],param_1);
        in_EAX[1] = *in_EAX + (param_1[1] - *param_1 >> 3) * 8;
        return;
      }
      if (uVar3 <= (uint)(in_EAX[2] - iVar2 >> 3)) {
        iVar2 = *param_1 + uVar4 * 8;
        FUN_007a3650(*param_1,iVar2,param_1);
        iVar2 = FUN_007a3a10(iVar2,param_1[1],in_EAX[1],param_1);
        in_EAX[1] = iVar2;
        return;
      }
      if (iVar2 != 0) {
        FUN_007a37a0(in_EAX[1],param_1);
        FUN_0089120c(*in_EAX);
      }
      cVar1 = FUN_004bb3e0();
      if (cVar1 != '\0') {
        iVar2 = FUN_007a3a10(*param_1,param_1[1],*in_EAX,param_1);
        in_EAX[1] = iVar2;
      }
    }
  }
  return;
}

