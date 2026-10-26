
float10 FUN_004d0f50(void)

{
  int in_ECX;
  
  return (float10)((float)*(int *)(in_ECX + 0xd0) * 0.01 * *(float *)(in_ECX + 0xcc) *
                  *(float *)(in_ECX + 0x434));
}

