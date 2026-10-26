
void FUN_00552d90(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_c [8];
  
  if (**(int **)(in_ECX + 4) != param_1) {
    iVar1 = *(int *)(param_1 + 4);
    do {
      iVar2 = **(int **)(in_ECX + 4);
      FUN_00552b00(in_ECX,local_c,iVar2 + 8,iVar2);
    } while (iVar2 != iVar1);
  }
  return;
}

