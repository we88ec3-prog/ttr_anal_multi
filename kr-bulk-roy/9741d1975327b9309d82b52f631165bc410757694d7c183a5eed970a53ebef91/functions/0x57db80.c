
void FUN_0057db80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0x7c) = (uint)(*(int *)(*(int *)(in_ECX + 0xc) + 0x48) == param_5);
  *(int *)(*(int *)(in_ECX + 0xc) + 0x48) = param_5;
  *(undefined4 *)(in_ECX + 0xb4) = param_1;
  *(undefined4 *)(in_ECX + 0xb8) = param_2;
  *(undefined4 *)(in_ECX + 0xbc) = param_3;
  *(undefined4 *)(in_ECX + 0xc0) = param_4;
  FUN_0057d5d0(0);
  FUN_0057dda0();
  return;
}

