
void FUN_00439dd0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar2 = param_1;
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 900) {
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf443c;
      FUN_004072a0();
      return;
    }
  }
  else {
    if (iVar1 != 0x578) {
      if (iVar1 != 0x76c) {
        return;
      }
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
        return;
      }
      FUN_0043a080();
      return;
    }
    if (*(int *)(param_1 + 8) == (*(int **)(in_ECX + 0x104))[8]) {
      (**(code **)(**(int **)(in_ECX + 0x104) + 0x90))(0);
      (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
      (**(code **)(**(int **)(in_ECX + 0x10c) + 0x94))(0);
      (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
      param_1 = CONCAT13(*(undefined1 *)(in_ECX + 0x110),CONCAT21(0xff,(undefined1)param_1));
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 1,3);
      }
    }
    if (*(int *)(iVar2 + 8) != *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
      return;
    }
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf4345;
      FUN_004072a0();
      return;
    }
  }
  FUN_004072a0();
  return;
}

