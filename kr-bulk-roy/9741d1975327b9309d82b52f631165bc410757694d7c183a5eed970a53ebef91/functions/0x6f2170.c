
void FUN_006f2170(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 in_EAX;
  HKL pHVar2;
  int in_ECX;
  DWORD DVar3;
  
  *(undefined4 *)(in_ECX + 0x74) = in_EAX;
  *(short *)(in_ECX + 0x72) = (short)in_EAX;
  FUN_006f1db0();
  uVar1 = FUN_006f1e90();
  *(undefined2 *)(in_ECX + 0x70) = uVar1;
  FUN_00402400(0,0xffffffff);
  DVar3 = 4;
  pHVar2 = GetKeyboardLayout(0);
  DVar3 = ImmGetProperty(pHVar2,DVar3);
  *(byte *)(in_ECX + 0x7c) = (byte)(DVar3 >> 0x13) & 1;
  FUN_006f2f80();
  FUN_006f2620();
  if (*(int *)(in_ECX + 0x74) == -0x1ffbf7fc) {
    *(undefined1 *)(in_ECX + 0x7c) = 1;
  }
  FUN_006f2890(param_1);
  return;
}

