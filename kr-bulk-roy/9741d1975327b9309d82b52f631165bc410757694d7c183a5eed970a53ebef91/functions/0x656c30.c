
void FUN_00656c30(void)

{
  int unaff_ESI;
  
  *(undefined1 *)(unaff_ESI + 0xa8) = 0;
  (**(code **)(**(int **)(unaff_ESI + 0xac) + 0x94))(0);
  (**(code **)(**(int **)(unaff_ESI + 0xb0) + 0x94))(0);
  (**(code **)(**(int **)(unaff_ESI + 0xb4) + 0x94))(1);
  FUN_00656c80(unaff_ESI);
  return;
}

