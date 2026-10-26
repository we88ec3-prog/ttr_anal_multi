
void FUN_0075fca0(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    piVar2 = (int *)FUN_00891268(0x18);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      iVar1 = *(int *)(param_1 + 4);
      piVar2[1] = -1;
      piVar2[2] = -1;
      piVar2[3] = 0;
      piVar2[4] = 0x76c;
      *piVar2 = (int)FoxUI::FXUIEventI1::vftable;
      piVar2[5] = iVar1;
    }
    if (*(int *)(in_ECX + 0x60) != 0) {
      piVar2[1] = *(int *)(in_ECX + 0x20);
      piVar2[2] = *(int *)(in_ECX + 0x48);
      (**(code **)(**(int **)(in_ECX + 0x60) + 0x148))(piVar2);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x10))(1);
    }
  }
  return;
}

