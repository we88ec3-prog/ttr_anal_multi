
void FUN_005c33b0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_0059b1f0();
  iVar1 = *(int *)(in_ECX + 0x21c);
  if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) {
    FUN_0064c710(iVar1);
  }
  iVar1 = *(int *)(in_ECX + 0x220);
  if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) && (*(int *)(iVar1 + 0xf4) != 0))
  {
    (**(code **)(**(int **)(iVar1 + 0xf4) + 200))();
  }
  if (*(int *)(*(int *)(in_ECX + 0x224) + 0x60) != 0) {
    FUN_00749f40(*(int *)(in_ECX + 0x224));
  }
  if (*(int *)(*(int *)(in_ECX + 0x22c) + 0x60) != 0) {
    FUN_00749f40(*(int *)(in_ECX + 0x22c));
  }
  if (*(int *)(*(int *)(in_ECX + 0x230) + 0x60) != 0) {
    FUN_00749f40(*(int *)(in_ECX + 0x230));
  }
  if ((~(byte)((uint)*(undefined4 *)(*(int *)(in_ECX + 0x224) + 0x28) >> 8) & 1) != 0) {
    iVar1 = *(int *)(in_ECX + 0x228);
    (**(code **)(**(int **)(iVar1 + 0xa8) + 0x94))(0);
    (**(code **)(**(int **)(iVar1 + 0xa4) + 0x94))(*(char *)(iVar1 + 0xdd) != '\0');
    *(undefined1 *)(iVar1 + 0xde) = 0;
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x228) + 0x28) >> 8 & 1) != 0) {
    FUN_006c0500(*(int *)(in_ECX + 0x228));
  }
  return;
}

