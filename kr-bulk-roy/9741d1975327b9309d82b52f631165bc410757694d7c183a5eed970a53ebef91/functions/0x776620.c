
void FUN_00776620(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIImageSetItemRef::vftable;
  if (in_ECX[1] != 0) {
    piVar2 = *(int **)(in_ECX[1] + 8);
    if (piVar2 != (int *)0x0) {
      piVar1 = piVar2 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 0x28))();
      }
    }
    in_ECX[1] = 0;
  }
  return;
}

