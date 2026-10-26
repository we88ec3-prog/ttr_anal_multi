
void FUN_00550490(int param_1,FILE *param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) <= param_1) {
    _fwrite((void *)(in_ECX + 9),1,1,param_2);
  }
  return;
}

