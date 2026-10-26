
void FUN_0068c340(char param_1)

{
  code *pcVar1;
  int unaff_ESI;
  
  pcVar1 = *(code **)(**(int **)(unaff_ESI + 0xfc) + 0xa0);
  if (param_1 != '\0') {
    (*pcVar1)(1);
    (**(code **)(**(int **)(unaff_ESI + 0x100) + 0xa0))(0);
    return;
  }
  (*pcVar1)(0);
  (**(code **)(**(int **)(unaff_ESI + 0x100) + 0xa0))(1);
  return;
}

