
undefined4 FUN_004e41f0(int param_1)

{
  DWORD DVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x5f68) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 0x5f70) = *(undefined4 *)(param_1 + 2);
  DVar1 = timeGetTime();
  *(DWORD *)(in_ECX + 0x5f6c) = DVar1;
  return 0;
}

