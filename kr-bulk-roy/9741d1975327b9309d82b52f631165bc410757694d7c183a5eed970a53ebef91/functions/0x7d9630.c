
void FUN_007d9630(void)

{
  float *pfVar1;
  int iVar2;
  int in_EDX;
  float local_8;
  
  if (*(int *)(in_EDX + 0x114) != *(int *)(in_EDX + 0x118)) {
    local_8 = 0.0;
    if (0 < *(int *)(in_EDX + 0xbc)) {
      iVar2 = *(int *)(in_EDX + 0xbc);
      pfVar1 = (float *)(*(int *)(in_EDX + 0xc0) + 0x10);
      do {
        iVar2 = iVar2 + -1;
        local_8 = pfVar1[-1] + local_8 + *pfVar1;
        pfVar1 = pfVar1 + 5;
      } while (iVar2 != 0);
    }
    *(float *)(in_EDX + 0x10c) = local_8;
  }
  return;
}

