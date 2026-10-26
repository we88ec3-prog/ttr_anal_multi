
void FUN_005ff150(byte param_1)

{
  void *in_ECX;
  
  FUN_005ff180();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

