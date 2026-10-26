
void FUN_004cbcb0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x68))(0x23,0x3f800000);
  FUN_004c9010(*(undefined4 *)(in_ECX + 4));
  (**(code **)(**(int **)(in_ECX + 4) + 0x4c))();
  if ((*(int *)(*(int *)(in_ECX + 4) + 0x15c) != 0) && (*(int *)(*(int *)(in_ECX + 4) + 0x370) != 0)
     ) {
    FUN_007a7100();
  }
  return;
}

