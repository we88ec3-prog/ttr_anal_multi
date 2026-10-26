
undefined4 FUN_00810420(undefined4 *param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2001c) == 0) {
    return 0;
  }
  alSource3f(*(undefined4 *)(in_ECX + 0x10),0x1004,*param_1,param_1[1],param_1[2]);
  alGetError();
  FUN_00810080();
  return 1;
}

