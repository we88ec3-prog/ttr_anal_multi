
void FUN_005dbee0(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x10) == 0x58c) {
    if (*(int *)(in_ECX + 0x260) == 0x1d) {
      piVar1 = (int *)FUN_00891268(0x20);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x254);
        piVar1[1] = -1;
        piVar1[2] = -1;
        piVar1[3] = 0;
        piVar1[4] = 0xf4324;
        *(undefined1 *)(piVar1 + 5) = 1;
        *piVar1 = (int)FoxUI::FXUIEventB1I2::vftable;
        piVar1[6] = iVar2;
        piVar1[7] = 1;
      }
      iVar2 = FUN_00404aa0();
      if (*(int *)(iVar2 + 0x13c4) != 0) {
        (**(code **)(**(int **)(iVar2 + 0x13c4) + 0x15c))(piVar1);
      }
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
    }
    else if (*(int *)(in_ECX + 0x260) == 0x1f) {
      uVar4 = *(undefined4 *)(in_ECX + 0x250);
      uVar3 = *(undefined4 *)(in_ECX + 0x254);
      FUN_00414720(uVar3,uVar4);
      FUN_00571580(uVar3,uVar4);
      return;
    }
  }
  return;
}

