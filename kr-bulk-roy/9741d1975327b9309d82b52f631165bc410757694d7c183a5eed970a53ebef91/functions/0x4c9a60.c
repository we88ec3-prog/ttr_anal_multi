
void FUN_004c9a60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0x15c) != 0) && (*(int *)(unaff_ESI + 0x370) != 0)) {
    FUN_007a7cc0(*(int *)(unaff_ESI + 0x15c),0);
    FUN_007a7bf0(param_1,param_2,param_3,param_4);
  }
  return;
}

