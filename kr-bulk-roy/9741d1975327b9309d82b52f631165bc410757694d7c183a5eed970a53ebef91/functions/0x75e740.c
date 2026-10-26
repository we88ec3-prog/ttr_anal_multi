
void FUN_0075e740(void)

{
  int iVar1;
  int in_ECX;
  
  if (0.5 < *(float *)(*(int *)(in_ECX + 0x24) + 0x1330) - *(float *)(in_ECX + 0xdc)) {
    iVar1 = *(int *)(in_ECX + 0xc4) + *(int *)(in_ECX + 0xd8);
    if (*(int *)(in_ECX + 0xb8) <= iVar1) {
      iVar1 = *(int *)(in_ECX + 0xb8);
    }
    *(int *)(in_ECX + 0xc4) = iVar1;
  }
  return;
}

