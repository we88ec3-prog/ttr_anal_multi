
void FUN_005d6f30(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0046b6f0(param_1);
  iVar1 = *(int *)(in_ECX + 0x264);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x264);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x40000;
  return;
}

