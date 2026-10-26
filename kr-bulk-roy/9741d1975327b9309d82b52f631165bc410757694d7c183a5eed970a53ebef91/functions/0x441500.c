
void FUN_00441500(void)

{
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xf4) != 0) {
    FUN_006dd470(*(float *)(*(int *)(unaff_EDI + 0x24) + 0x132c) -
                 *(float *)(*(int *)(unaff_EDI + 0x24) + 0x1330));
    FUN_006dd670();
    FUN_00441560(unaff_EDI);
    (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0xcc))();
  }
  return;
}

