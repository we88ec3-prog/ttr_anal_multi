
void FUN_00590720(int param_1,byte param_2)

{
  undefined2 *unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *unaff_ESI = 0;
  FUN_004026e0(param_1 + (uint)param_2 * 0x1c,0,0xffffffff);
  return;
}

