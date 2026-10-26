
void FUN_00708940(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_006f6140("FILE*");
  if (*piVar1 == 0) {
    FUN_006f5f30(param_1,"attempt to use a closed file");
  }
  FUN_007086f0(param_1,*piVar1,2);
  return;
}

