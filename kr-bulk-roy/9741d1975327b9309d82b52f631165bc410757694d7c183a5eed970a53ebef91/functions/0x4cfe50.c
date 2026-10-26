
void FUN_004cfe50(short param_1,short param_2)

{
  int in_ECX;
  
  if (param_1 == 5) {
    *(int *)(in_ECX + 0xd0) = (int)param_2;
  }
  else if (param_1 == 6) {
    *(float *)(in_ECX + 0xcc) = (float)(int)param_2;
    return;
  }
  return;
}

