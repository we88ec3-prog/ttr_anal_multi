
void FUN_005f96f0(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  FUN_005f5ed0(param_1);
  iVar1 = param_1[4];
  if (iVar1 == 0xf4375) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    (**(code **)(*in_ECX + 0x1ac))(param_1[5],0);
    return;
  }
  if (iVar1 == 0xf436f) {
    FUN_005f9d60(in_ECX,param_1[7],param_1[8]);
    return;
  }
  if (iVar1 == 0xf4370) {
    FUN_005f9e70(in_ECX,param_1[5],param_1[6]);
    return;
  }
  if ((iVar1 == 0xf4371) && (param_1[5] == 0xf43a5)) {
    FUN_005fa0f0(*(undefined4 *)(param_1[7] + 0xc),*(undefined4 *)(param_1[7] + 0x10),param_1[6]);
  }
  return;
}

