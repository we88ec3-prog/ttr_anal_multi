
void FUN_00721400(void)

{
  int *in_EAX;
  int *in_ECX;
  int local_8;
  
  if (in_ECX[1] == 0) {
    if (*in_ECX != 0) {
      *in_EAX = *(int *)(*in_ECX + 4);
      return;
    }
    local_8 = 0;
    in_ECX = &local_8;
  }
  *in_EAX = *in_ECX;
  return;
}

