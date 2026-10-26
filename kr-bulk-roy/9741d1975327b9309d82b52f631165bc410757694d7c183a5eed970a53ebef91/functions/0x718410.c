
void FUN_00718410(byte param_1)

{
  int iVar1;
  int in_ECX;
  
  param_1 = param_1 ^ *(byte *)(in_ECX + 0x208);
  if (*(int **)(in_ECX + 4) == (int *)0x0) {
    FID_conflict__wprintf("File is not opened!\n");
    return;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))(&param_1,1,1);
  if ((iVar1 != 1) && (*(int **)(in_ECX + 4) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  }
  return;
}

