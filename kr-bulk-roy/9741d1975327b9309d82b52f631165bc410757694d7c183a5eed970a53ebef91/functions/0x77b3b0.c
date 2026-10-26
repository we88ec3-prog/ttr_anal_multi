
void FUN_0077b3b0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 != 0) && (*(int *)(in_ECX + 0x10) != 0)) {
    iVar2 = *(int *)(in_ECX + 0x10);
    (**(code **)(**(int **)(in_ECX + 8) + 0xbc))
              (*(int *)(iVar1 + 8),*(int *)(iVar1 + 0xc),
               (*(int *)(iVar2 + 0x30) - *(int *)(iVar2 + 0x28)) + *(int *)(iVar1 + 8),
               (*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x2c)) + *(int *)(iVar1 + 0xc));
  }
  return;
}

