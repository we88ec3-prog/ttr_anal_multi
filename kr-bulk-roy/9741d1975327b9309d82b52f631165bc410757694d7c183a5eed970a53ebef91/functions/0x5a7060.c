
void FUN_005a7060(byte param_1)

{
  void *in_ECX;
  
  FUN_005a7000();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

