
void FUN_007c5300(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  uint uVar3;
  code *pcVar4;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xe8) == 0) {
    if (in_EAX == 0) {
      if ((*(int *)(unaff_EDI + 0xdc) != 0) &&
         (piVar1 = (int *)**(int **)(unaff_EDI + 0xd8), piVar1 != *(int **)(unaff_EDI + 0xd8))) {
        do {
          uVar3 = (**(code **)(*(int *)piVar1[4] + 8))();
          if (uVar3 < 0x10) {
            pcVar4 = *(code **)(*(int *)piVar1[4] + 0x24);
          }
          else {
            pcVar4 = *(code **)(*(int *)piVar1[4] + 0x28);
          }
          (*pcVar4)();
          FUN_0049e6a0();
        } while (piVar1 != (int *)*(int *)(unaff_EDI + 0xd8));
        return;
      }
    }
    else if (in_EAX == 1) {
      if ((*(int *)(unaff_EDI + 0xdc) != 0) &&
         (piVar1 = (int *)**(int **)(unaff_EDI + 0xd8), piVar1 != *(int **)(unaff_EDI + 0xd8))) {
        do {
          uVar3 = (**(code **)(*(int *)piVar1[4] + 8))();
          if ((uVar3 < 100) || (uVar3 = (**(code **)(*(int *)piVar1[4] + 8))(), 0xf4 < uVar3)) {
            pcVar4 = *(code **)(*(int *)piVar1[4] + 0x24);
          }
          else {
            pcVar4 = *(code **)(*(int *)piVar1[4] + 0x28);
          }
          (*pcVar4)();
          FUN_0049e6a0();
        } while (piVar1 != (int *)*(int *)(unaff_EDI + 0xd8));
        return;
      }
    }
    else if ((in_EAX == 2) && (*(int *)(unaff_EDI + 0xdc) != 0)) {
      piVar1 = *(int **)(unaff_EDI + 0xd8);
      piVar2 = (int *)*piVar1;
      while (piVar2 != piVar1) {
        (**(code **)(*(int *)piVar2[4] + 0x24))();
        FUN_0049e6a0();
        piVar1 = *(int **)(unaff_EDI + 0xd8);
      }
    }
  }
  return;
}

