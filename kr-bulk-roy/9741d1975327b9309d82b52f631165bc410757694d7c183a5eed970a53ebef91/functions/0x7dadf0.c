
float10 FUN_007dadf0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xd0) != 0) {
    return (float10)*(float *)(*(int *)(in_ECX + 0xd0) + 4);
  }
  return (float10)*(float *)(in_ECX + 0xb0);
}

