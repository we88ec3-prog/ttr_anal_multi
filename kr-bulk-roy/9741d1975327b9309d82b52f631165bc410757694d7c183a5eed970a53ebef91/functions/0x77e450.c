
void FUN_0077e450(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (*(int *)(iVar1 + 0x208) != 0) {
    (**(code **)(**(int **)(iVar1 + 0x208) + 0xe8))
              (*(int **)(iVar1 + 0x208),*(undefined4 *)(in_ECX + 8));
    (**(code **)(**(int **)(iVar1 + 0x208) + 0xfc))(*(int **)(iVar1 + 0x208),0,0);
    (**(code **)(**(int **)(iVar1 + 0x208) + 0x100))(*(int **)(iVar1 + 0x208),param_1);
  }
  return;
}

