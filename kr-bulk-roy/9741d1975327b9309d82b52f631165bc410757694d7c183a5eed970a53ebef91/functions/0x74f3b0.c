
void FUN_0074f3b0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x13e0);
  if (*(int *)(in_ECX + 0x13cc) != iVar2) {
    if (((iVar2 != 0) && (iVar2 != *(int *)(in_ECX + 0x13c4))) &&
       ((*(uint *)(iVar2 + 0x28) >> 7 & 1) != 0)) {
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x13e0);
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = *(int *)(iVar2 + 0x20);
        piVar1[2] = *(int *)(iVar2 + 0x48);
        piVar1[3] = iVar2;
        piVar1[4] = 0xcc;
      }
      (**(code **)(**(int **)(in_ECX + 0x13e0) + 0x140))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x13e0);
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = *(int *)(iVar2 + 0x20);
        piVar1[2] = *(int *)(iVar2 + 0x48);
        piVar1[3] = iVar2;
        piVar1[4] = 0xcc;
      }
      (**(code **)(**(int **)(in_ECX + 0x13e0) + 0x144))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
    }
    iVar2 = *(int *)(in_ECX + 0x13cc);
    if (((iVar2 != 0) && (iVar2 != *(int *)(in_ECX + 0x13c4))) &&
       ((*(uint *)(iVar2 + 0x28) >> 7 & 1) != 0)) {
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x13cc);
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = *(int *)(iVar2 + 0x20);
        piVar1[2] = *(int *)(iVar2 + 0x48);
        piVar1[3] = iVar2;
        piVar1[4] = 0xcb;
      }
      (**(code **)(**(int **)(in_ECX + 0x13cc) + 0x140))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x13cc);
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = *(int *)(iVar2 + 0x20);
        piVar1[2] = *(int *)(iVar2 + 0x48);
        piVar1[3] = iVar2;
        piVar1[4] = 0xcb;
      }
      (**(code **)(**(int **)(in_ECX + 0x13cc) + 0x144))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
    }
  }
  iVar2 = *(int *)(in_ECX + 0x13cc);
  if (((iVar2 != 0) && (iVar2 != *(int *)(in_ECX + 0x13c4))) &&
     ((*(uint *)(iVar2 + 0x28) >> 7 & 1) != 0)) {
    piVar1 = (int *)FUN_00891268(0x14);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 0x13cc);
      *piVar1 = (int)FoxUI::FXUIEvent::vftable;
      piVar1[1] = *(int *)(iVar2 + 0x20);
      piVar1[2] = *(int *)(iVar2 + 0x48);
      piVar1[3] = iVar2;
      piVar1[4] = 200;
    }
    (**(code **)(**(int **)(in_ECX + 0x13cc) + 0x140))(piVar1);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(1);
    }
  }
  if ((*(int *)(in_ECX + 0x13d4) != 0) && (*(int *)(in_ECX + 0xc4) != 0)) {
    piVar1 = (int *)FUN_00891268(0x14);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 0x13d4);
      *piVar1 = (int)FoxUI::FXUIEvent::vftable;
      piVar1[1] = *(int *)(iVar2 + 0x20);
      piVar1[2] = *(int *)(iVar2 + 0x48);
      piVar1[3] = iVar2;
      piVar1[4] = 0x82;
    }
    (**(code **)(**(int **)(in_ECX + 0x13d4) + 0x140))(piVar1);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(1);
    }
  }
  iVar2 = *(int *)(in_ECX + 0x13e4);
  if (*(int *)(in_ECX + 0x13d0) != iVar2) {
    if ((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 7 & 1) != 0)) {
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x13e4);
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = *(int *)(iVar2 + 0x20);
        piVar1[2] = *(int *)(iVar2 + 0x48);
        piVar1[3] = iVar2;
        piVar1[4] = 0xca;
      }
      (**(code **)(**(int **)(in_ECX + 0x13e4) + 0x140))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
    }
    iVar2 = *(int *)(in_ECX + 0x13d0);
    if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 7 & 1) != 0)) &&
       (iVar2 != *(int *)(in_ECX + 0x13c4))) {
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x13d0);
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = *(int *)(iVar2 + 0x20);
        piVar1[2] = *(int *)(iVar2 + 0x48);
        piVar1[3] = iVar2;
        piVar1[4] = 0xc9;
      }
      (**(code **)(**(int **)(in_ECX + 0x13d0) + 0x140))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
    }
  }
  iVar2 = *(int *)(in_ECX + 0x13c8);
  if ((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 7 & 1) != 0)) ||
      ((iVar2 = *(int *)(in_ECX + 0x13d0), iVar2 != 0 && ((*(uint *)(iVar2 + 0x28) >> 7 & 1) != 0)))
      ) && (iVar2 != 0)) {
    FUN_0074f1b0(in_ECX);
  }
  if (*(int *)(in_ECX + 0x13cc) != 0) {
    FUN_0074f0f0(in_ECX);
  }
  return;
}

