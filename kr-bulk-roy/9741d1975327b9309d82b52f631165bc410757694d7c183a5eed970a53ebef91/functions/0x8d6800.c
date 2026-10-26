
void FUN_008d6800(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 500);
  if (*(int *)(*(int *)(param_1 + 4) + 0x54) == 0) {
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar1 + 0x54);
    return;
  }
  FUN_008bb230(iVar1,&param_1);
  *(int *)(iVar2 + 0xa0) = param_1;
  return;
}

