
undefined4 FUN_004e2a90(int param_1)

{
  int in_ECX;
  int iVar1;
  
  if (((*(byte *)(param_1 + 0x2e) < 10) &&
      (iVar1 = (uint)*(byte *)(param_1 + 0x2e) * 0x210 + *(int *)(in_ECX + 0x6924),
      *(int *)(iVar1 + 0x5c) != 0)) && (iVar1 != 0)) {
    FUN_004d4020();
  }
  return 0;
}

