
void FUN_00443520(void)

{
  int *piVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xf4) != 0) && ((*(uint *)(*(int *)(in_ECX + 0xf4) + 0x28) >> 8 & 1) != 0))
  {
    (**(code **)(**(int **)(in_ECX + 0xf4) + 0xd4))();
  }
  piVar1 = *(int **)(in_ECX + 0xf8);
  if ((piVar1 != (int *)0x0) && (((uint)piVar1[10] >> 8 & 1) != 0)) {
    (**(code **)(*piVar1 + 0xd4))();
  }
  FUN_004067f0();
  return;
}

