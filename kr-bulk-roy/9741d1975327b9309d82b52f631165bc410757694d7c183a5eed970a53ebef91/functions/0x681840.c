
void FUN_00681840(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI < 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0xa0))(0);
    (**(code **)(**(int **)(unaff_ESI + 0x110) + 0xa0))(0);
    (**(code **)(**(int **)(unaff_ESI + 0x114) + 0xa0))(0);
    *(undefined4 *)(unaff_ESI + 0x100) = 0xffffffff;
    return;
  }
  if (*(int *)(*(int *)(unaff_ESI + 0x10c + unaff_EDI * 4) + 0x25c) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x10c) + 0xa0))(0);
    (**(code **)(**(int **)(unaff_ESI + 0x110) + 0xa0))(0);
    (**(code **)(**(int **)(unaff_ESI + 0x114) + 0xa0))(0);
    (**(code **)(**(int **)(unaff_ESI + 0x10c + unaff_EDI * 4) + 0xa0))(1);
    *(int *)(unaff_ESI + 0x100) = unaff_EDI;
    (**(code **)(**(int **)(unaff_ESI + 0x120) + 0x90))(1);
  }
  return;
}

