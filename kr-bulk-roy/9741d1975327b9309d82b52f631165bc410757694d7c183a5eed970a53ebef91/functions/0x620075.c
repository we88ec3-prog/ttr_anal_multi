
void FUN_00620075(void)

{
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  
  DAT_00faadd0 = DAT_00faadd0 | 1;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0074d990();
  _atexit((_func_4879 *)&LAB_00bccc70);
  *(undefined4 *)(unaff_EBP + -4) = unaff_EBX;
  FUN_007532b0(&DAT_00f94810,unaff_ESI,*(undefined4 *)(unaff_EBP + -0x10),
               *(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

