
void FUN_0064ba50(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  undefined1 in_AL;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xd5) = in_AL;
  *(float *)(in_ECX + 0xb8) = (float)((param_4 - param_2) / 2 - *(int *)(in_ECX + 0xc));
  *(float *)(in_ECX + 0xb4) = (float)((param_3 - param_1) / 2 - *(int *)(in_ECX + 8));
  *(float *)(in_ECX + 0xbc) = (float)((param_7 - param_5) / 2 + param_5);
  *(float *)(in_ECX + 0xc0) = (float)((param_8 - param_6) / 2 + param_6);
  *(float *)(in_ECX + 0xc4) = *(float *)(in_ECX + 0xbc) - *(float *)(in_ECX + 0xb4);
  *(float *)(in_ECX + 200) = *(float *)(in_ECX + 0xc0) - *(float *)(in_ECX + 0xb8);
  *(float *)(in_ECX + 0xd0) = (float)*(int *)(in_ECX + 0xc);
  *(float *)(in_ECX + 0xcc) = (float)*(int *)(in_ECX + 8);
  *(undefined1 *)(in_ECX + 0xd4) = 1;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  return;
}

