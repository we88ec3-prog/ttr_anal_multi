
void FUN_00718220(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) == (int *)0x0) {
    FID_conflict__wprintf("File is not opened!\n");
    return;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x34))(param_1,param_2);
  if ((iVar1 < 0) && (*(int **)(in_ECX + 0xc) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))();
  }
  return;
}

