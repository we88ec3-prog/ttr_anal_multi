
void FUN_005ace30(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CMissionFieldPage::vftable;
  piVar1 = (int *)in_ECX[0x93];
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(undefined4 *)(in_ECX[0x93] + 4) = in_ECX[0x93];
  in_ECX[0x94] = 0;
  if (piVar2 != (int *)in_ECX[0x93]) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)in_ECX[0x93]);
  }
  FUN_0089120c(in_ECX[0x93]);
  *in_ECX = FUI::CChatablePage::vftable;
  FUN_00595c80();
  return;
}

