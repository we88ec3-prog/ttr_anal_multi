
void FUN_004d2310(short param_1,short param_2)

{
  int in_ECX;
  
  if (param_1 == 5) {
    *(int *)(in_ECX + 0xd0) = (int)param_2;
    return;
  }
  if (param_1 != 6) {
    FUN_006edb60(&DAT_00c0ca70);
    return;
  }
  *(float *)(in_ECX + 0xcc) = (float)(int)param_2;
  return;
}

