
void FUN_006dd590(undefined4 param_1)

{
  int in_ECX;
  undefined4 in_XMM2_Da;
  
  if (*(char *)(in_ECX + 0x2c) == '\0') {
    *(undefined4 *)(in_ECX + 0x34) = in_XMM2_Da;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x48) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = param_1;
    *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x60) = 0;
    *(undefined4 *)(in_ECX + 0x68) = 0;
    *(float *)(in_ECX + 100) = *(float *)(in_ECX + 0x4c) - *(float *)(in_ECX + 0x34);
    *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 100) * 0.4 + *(float *)(in_ECX + 0x20);
    FUN_006dd6f0();
  }
  return;
}

