
undefined4 FUN_004e6f70(int param_1)

{
  float fVar1;
  DWORD DVar2;
  int in_ECX;
  
  fVar1 = (float)*(int *)(param_1 + 2);
  if (*(int *)(param_1 + 2) < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  *(float *)(in_ECX + 0x68d4) = fVar1;
  DVar2 = timeGetTime();
  *(DWORD *)(in_ECX + 0x68d8) = DVar2;
  *(undefined4 *)(in_ECX + 0x68dc) = 0;
  return 0;
}

