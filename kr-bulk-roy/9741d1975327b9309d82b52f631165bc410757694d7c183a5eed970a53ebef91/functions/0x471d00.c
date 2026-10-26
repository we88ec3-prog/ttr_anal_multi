
void FUN_00471d00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
    if (*(int *)(in_ECX + 0xdc) == *(int *)(param_1 + 0xc)) {
      FUN_0042c8e0(uVar2);
    }
    else {
      FUN_0042c8e0(uVar2);
      piVar4 = (int *)FUN_00891268(0x1c);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        iVar1 = *(int *)(param_1 + 0xc);
        iVar3 = *(int *)(iVar1 + 0x20);
        piVar4[1] = -1;
        piVar4[2] = -1;
        piVar4[3] = 0;
        piVar4[4] = 0x709;
        *piVar4 = (int)FoxUI::FXUIEventI1P1::vftable;
        piVar4[5] = iVar3;
        piVar4[6] = iVar1;
      }
      if (*(int *)(in_ECX + 0x60) != 0) {
        piVar4[1] = *(int *)(in_ECX + 0x20);
        piVar4[2] = *(int *)(in_ECX + 0x48);
        (**(code **)(**(int **)(in_ECX + 0x60) + 0x148))(piVar4);
      }
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x10))(1);
      }
    }
    piVar4 = (int *)FUN_00891268(0x1c);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x20);
      piVar4[6] = *(int *)(param_1 + 0xc);
      piVar4[1] = -1;
      piVar4[2] = -1;
      piVar4[3] = 0;
      piVar4[4] = 0x70b;
      *piVar4 = (int)FoxUI::FXUIEventI1P1::vftable;
      piVar4[5] = iVar1;
    }
    if (*(int *)(in_ECX + 0x60) != 0) {
      piVar4[1] = *(int *)(in_ECX + 0x20);
      piVar4[2] = *(int *)(in_ECX + 0x48);
      (**(code **)(**(int **)(in_ECX + 0x60) + 0x148))(piVar4);
    }
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x10))(1);
      return;
    }
  }
  else if (iVar1 == 0x57a) {
    piVar4 = (int *)FUN_00891268(0x1c);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x20);
      piVar4[6] = *(int *)(param_1 + 0xc);
      piVar4[1] = -1;
      piVar4[2] = -1;
      piVar4[3] = 0;
      piVar4[4] = 0x70a;
      *piVar4 = (int)FoxUI::FXUIEventI1P1::vftable;
      piVar4[5] = iVar1;
    }
    if (*(int *)(in_ECX + 0x60) != 0) {
      piVar4[1] = *(int *)(in_ECX + 0x20);
      piVar4[2] = *(int *)(in_ECX + 0x48);
      (**(code **)(**(int **)(in_ECX + 0x60) + 0x148))(piVar4);
    }
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x10))(1);
      return;
    }
  }
  else if (iVar1 == 0x58c) {
    puVar5 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar5 != (undefined4 *)0x0) {
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
      puVar5[6] = *(int *)(param_1 + 0xc);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0x70c;
      *puVar5 = FoxUI::FXUIEventI1P1::vftable;
      puVar5[5] = uVar2;
      FUN_007489e0();
      return;
    }
    FUN_007489e0();
  }
  return;
}

