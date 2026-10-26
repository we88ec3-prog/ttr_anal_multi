
undefined4 FUN_004e2ad0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((*(byte *)(param_1 + 2) < 10) &&
      (iVar1 = (uint)*(byte *)(param_1 + 2) * 0x210 + *(int *)(in_ECX + 0x6924),
      *(int *)(iVar1 + 0x5c) != 0)) && (iVar1 != 0)) {
    *(uint *)(iVar1 + 0xdc) = (uint)*(byte *)(param_1 + 3);
  }
  return 0;
}

