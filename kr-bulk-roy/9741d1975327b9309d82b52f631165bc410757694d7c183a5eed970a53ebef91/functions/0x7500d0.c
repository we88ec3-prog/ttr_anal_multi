
void FUN_007500d0(float param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1330) = *(undefined4 *)(in_ECX + 0x132c);
  *(float *)(in_ECX + 0x132c) = param_1 + *(float *)(in_ECX + 0x132c);
  return;
}

