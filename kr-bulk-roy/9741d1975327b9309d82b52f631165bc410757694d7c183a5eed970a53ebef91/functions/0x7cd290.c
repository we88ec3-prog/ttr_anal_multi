
int FUN_007cd290(void)

{
  int *in_ECX;
  uint in_EDX;
  
  if ((uint)(in_ECX[1] - *in_ECX >> 2) <= in_EDX) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  return *in_ECX + in_EDX * 4;
}

