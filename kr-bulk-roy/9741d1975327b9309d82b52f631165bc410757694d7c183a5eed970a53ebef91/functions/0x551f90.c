
void FUN_00551f90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 in_ECX;
  int *in_EDX;
  undefined4 unaff_ESI;
  
  iVar1 = *in_EDX;
  if (-1 < iVar1) {
    if (iVar1 < 3) {
      FUN_00551b80(in_EDX[2],in_EDX[3]);
    }
    else if ((iVar1 == 3) && (in_EDX[4] != 0)) {
      FUN_00551cd0();
    }
  }
  FUN_00551dd0(in_ECX,param_1,unaff_ESI,param_2,param_3,0);
  return;
}

