
void FUN_005cb7a0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x14);
  if ((piVar1 != (int *)0x0) && (piVar1[0x3d] != 0)) {
    (**(code **)(*piVar1 + 0x1a8))();
    (**(code **)(*piVar1 + 0x1ac))();
    if (*(int *)(in_ECX + 0x24) < 1) {
      FUN_008fed10();
    }
    FUN_008fed10();
    FUN_008fed10();
    FUN_008fed10();
    FUN_008fed10();
    FUN_008fed10();
    FUN_005cb290(0x7dffffff);
  }
  return;
}

