
undefined4 FUN_00810350(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (iVar1 != 0) {
    in_ECX[0x8009] = 0;
    in_ECX[0x800a] = 0;
    alSourcef(in_ECX[4],0x100a,(float)param_1 / 10000.0);
    FUN_00810080();
    return 1;
  }
  in_ECX[0x8009] = 1;
  in_ECX[0x800a] = param_1;
  return 0;
}

