
void FUN_00776700(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_ECX;
  
  *in_ECX = FoxUI::FXUIImageSetItemLink::vftable;
  if (7 < (uint)in_ECX[0xe]) {
    FUN_0089120c(in_ECX[9]);
  }
  in_ECX[0xe] = 7;
  in_ECX[0xd] = 0;
  *(undefined2 *)(in_ECX + 9) = 0;
  if (7 < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 7;
  in_ECX[6] = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
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

