
void FUN_005504c0(int param_1,FILE *param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) <= param_1) {
    _fread((void *)(in_ECX + 10),2,1,param_2);
  }
  return;
}

