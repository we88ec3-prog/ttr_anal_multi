
void FUN_0055e740(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x14) = param_1;
  *(undefined4 *)(in_ECX + 0x18) = param_2;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 1;
  *(uint *)(in_ECX + 0x10) = -(uint)(param_1 != 0) & 0xff;
  return;
}

