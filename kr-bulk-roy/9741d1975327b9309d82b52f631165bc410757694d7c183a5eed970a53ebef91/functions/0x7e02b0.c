
void FUN_007e02b0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *in_EAX;
  int iVar4;
  
  if (in_EAX != param_1) {
    uVar1 = (param_1[1] - *param_1) / 0x18;
    if (uVar1 == 0) {
      if (*in_EAX != in_EAX[1]) {
        iVar4 = FUN_007e0540(in_EAX[1]);
        FUN_00512f50(in_EAX[1]);
        in_EAX[1] = iVar4;
        return;
      }
    }
    else {
      iVar4 = *in_EAX;
      uVar2 = (in_EAX[1] - iVar4) / 0x18;
      if (uVar1 <= uVar2) {
        FUN_007e0540(param_1[1]);
        FUN_00512f50(in_EAX[1]);
        in_EAX[1] = *in_EAX + ((param_1[1] - *param_1) / 0x18) * 0x18;
        return;
      }
      if (uVar1 <= (uint)((in_EAX[2] - iVar4) / 0x18)) {
        FUN_007e0540(*param_1 + uVar2 * 0x18);
        iVar4 = FUN_007e0640(param_1[1],in_EAX[1],uVar1);
        in_EAX[1] = iVar4;
        return;
      }
      if (iVar4 != 0) {
        FUN_00512f50(in_EAX[1]);
        FUN_0089120c(*in_EAX);
      }
      cVar3 = FUN_007e0420();
      if (cVar3 != '\0') {
        iVar4 = FUN_007e0640(param_1[1],*in_EAX,uVar1);
        in_EAX[1] = iVar4;
      }
    }
  }
  return;
}

