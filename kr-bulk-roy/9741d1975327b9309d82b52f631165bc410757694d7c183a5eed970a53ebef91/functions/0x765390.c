
void FUN_00765390(void)

{
  int *in_ECX;
  
  if (((uint)in_ECX[10] >> 9 & 1) == 0) {
    (**(code **)(*in_ECX + 0xa0))(1);
  }
  return;
}

