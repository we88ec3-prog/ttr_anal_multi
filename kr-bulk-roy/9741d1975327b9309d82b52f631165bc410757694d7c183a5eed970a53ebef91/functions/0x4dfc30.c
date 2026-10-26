
void FUN_004dfc30(int param_1)

{
  int in_ECX;
  int unaff_ESI;
  
  FUN_008438c0(&param_1);
  if (in_ECX != *(int *)(unaff_ESI + 0x1c)) {
    if ((*(int **)(unaff_ESI + 0xf8) != (int *)0x0) && (**(int **)(unaff_ESI + 0xf8) == param_1)) {
      *(undefined4 *)(unaff_ESI + 0xf8) = 0;
    }
    if (*(int *)(in_ECX + 0x10) != 0) {
      FUN_0089120c(*(int *)(in_ECX + 0x10));
    }
    FUN_007b6890(unaff_ESI + 0x18,&param_1,in_ECX);
  }
  return;
}

