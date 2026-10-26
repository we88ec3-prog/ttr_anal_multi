
void FUN_006d9da0(undefined4 param_1)

{
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  if (*(int *)(unaff_ESI + 0x34) != 0) {
    FUN_006d9280(param_1);
    FUN_00402a70(&DAT_00bf2375,0);
  }
  *(undefined4 *)(unaff_ESI + 0xa0) = 0;
  if (*(int *)(unaff_ESI + 0x6c) != 0) {
    FUN_006d9280(param_1);
    FUN_00402a70(&DAT_00bf2375,0);
  }
  return;
}

