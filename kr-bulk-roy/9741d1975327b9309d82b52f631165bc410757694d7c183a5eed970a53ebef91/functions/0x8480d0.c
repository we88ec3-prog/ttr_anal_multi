
void FUN_008480d0(int *param_1)

{
  uint uVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[1];
  uVar1 = (iVar2 - *param_1) / 100;
  if (in_EAX < uVar1) {
    iVar3 = in_EAX * 100 + *param_1;
    if (iVar3 != iVar2) {
      iVar2 = FUN_00848b00(iVar2,iVar3,param_1);
      FUN_00848b60(param_1);
      param_1[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_00848370(in_EAX - uVar1);
    FUN_008489c0(param_1[1],in_EAX - (param_1[1] - *param_1) / 100,param_1);
    param_1[1] = (in_EAX - (param_1[1] - *param_1) / 100) * 100 + param_1[1];
  }
  return;
}

