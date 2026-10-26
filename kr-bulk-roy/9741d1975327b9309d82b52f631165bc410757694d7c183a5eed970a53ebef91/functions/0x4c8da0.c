
void FUN_004c8da0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x38c) = param_1;
  if ((*(int *)(in_ECX + 0x15c) != 0) && (*(int *)(in_ECX + 0x370) != 0)) {
    FUN_007a6970(param_1,param_2);
  }
  return;
}

