
void FUN_00550550(int param_1,FILE *param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) <= param_1) {
    _fread((void *)(in_ECX + 0xc),4,1,param_2);
  }
  return;
}

