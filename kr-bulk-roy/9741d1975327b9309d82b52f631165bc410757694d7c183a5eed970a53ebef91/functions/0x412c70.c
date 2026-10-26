
int FUN_00412c70(int param_1)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  
  if (in_EAX[0x29] != 0) {
    iVar1 = FUN_00408bf0();
    *(int *)(iVar1 + 0x20) = param_1;
    (**(code **)(*in_EAX + 0x70))(iVar1);
    FUN_00443d10();
    uVar2 = param_1 + 1U;
    if (param_1 + 1U <= (uint)in_EAX[0x39]) {
      uVar2 = in_EAX[0x39];
    }
    in_EAX[0x39] = uVar2;
    return iVar1;
  }
  return 0;
}

