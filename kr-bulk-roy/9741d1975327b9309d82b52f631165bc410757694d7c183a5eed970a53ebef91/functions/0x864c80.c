
void FUN_00864c80(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    iVar1 = *(int *)(in_ECX + 0xc) + param_1 * 0x14;
    (**(code **)(**(int **)(in_ECX + 4) + 0x148))
              (*(int **)(in_ECX + 4),4,*(undefined4 *)(iVar1 + 0xc),0,*(undefined4 *)(iVar1 + 0x10),
               *(int *)(iVar1 + 4) * 3,*(undefined4 *)(iVar1 + 8));
  }
  return;
}

