
void FUN_00867470(undefined4 *param_1)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 8) == 0) {
    uVar1 = FUN_00891268(4);
    *(undefined4 *)(unaff_ESI + 8) = uVar1;
  }
  **(undefined4 **)(unaff_ESI + 8) = *param_1;
  return;
}

