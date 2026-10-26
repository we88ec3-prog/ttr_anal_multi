
void FUN_006c1400(byte param_1)

{
  void *in_ECX;
  
  FUN_006c1430();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

