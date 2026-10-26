
void FUN_005b3f60(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_005b87b0();
  if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x2f8) + 0x16c))();
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x2fc) + 0x28) >> 8 & 1) != 0) {
    FUN_0064c710(*(int *)(in_ECX + 0x2fc));
  }
  iVar1 = *(int *)(in_ECX + 0x30c);
  if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) {
    FUN_00427fb0(iVar1);
    FUN_00428100(iVar1);
  }
  if (*(int *)(in_ECX + 0x300) != 0) {
    FUN_006971d0(*(int *)(in_ECX + 0x300));
  }
  return;
}

