
void FUN_00483be0(void)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x118) != 0) {
    FUN_007597b0(0);
    (**(code **)(**(int **)(unaff_ESI + 0x104) + 200))();
    FUN_007597b0(0);
    (**(code **)(**(int **)(unaff_ESI + 0x100) + 200))();
  }
  return;
}

