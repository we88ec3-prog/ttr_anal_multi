
void FUN_006bcf60(byte param_1)

{
  void *in_ECX;
  
  FUN_006bcf90(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

