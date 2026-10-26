
void FUN_00474fe0(void)

{
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xf4) != 0) {
    FUN_006dd470(*(float *)(*(int *)(unaff_EDI + 0x24) + 0x132c) -
                 *(float *)(*(int *)(unaff_EDI + 0x24) + 0x1330));
    FUN_006dd670();
    FUN_00475c10(unaff_EDI);
    (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0xcc))();
  }
  return;
}

