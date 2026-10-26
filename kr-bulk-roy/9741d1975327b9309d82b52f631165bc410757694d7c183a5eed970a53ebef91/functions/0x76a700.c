
void FUN_0076a700(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_EAX;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  undefined4 *local_8;
  
  if (*(int *)(in_ECX + 0xd4) == 0) {
    local_8 = (undefined4 *)FUN_00891268(0x1c);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      local_8[1] = 0xffffffff;
      local_8[2] = 0xffffffff;
      local_8[3] = 0;
      local_8[4] = 0x6a4;
      *local_8 = FoxUI::FXUIEventI1P1::vftable;
      local_8[5] = in_EAX;
      local_8[6] = 0;
    }
    local_8[3] = *(undefined4 *)(in_ECX + 0xd0);
    iVar5 = *(int *)(in_ECX + 0x24);
    iVar2 = *(int *)(iVar5 + 0x142c);
    iVar3 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&local_8);
    if (*(int *)(iVar5 + 0x1430) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(iVar5 + 0x1430) = *(int *)(iVar5 + 0x1430) + 1;
    *(int *)(iVar2 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    local_8 = (undefined4 *)FUN_00891268(0x1c);
    iVar5 = 0;
    if (local_8 == (undefined4 *)0x0) goto LAB_0076a7de;
    local_8[1] = 0xffffffff;
    local_8[2] = 0xffffffff;
    local_8[3] = 0;
    local_8[4] = 0x6a4;
  }
  else {
    local_8 = (undefined4 *)FUN_00891268(0x1c);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 0xd4);
      uVar1 = *(undefined4 *)(iVar5 + 0x10);
      local_8[1] = 0xffffffff;
      local_8[2] = 0xffffffff;
      local_8[3] = 0;
      local_8[4] = uVar1;
      *local_8 = FoxUI::FXUIEventI1P1::vftable;
      local_8[5] = in_EAX;
      local_8[6] = iVar5;
    }
    local_8[3] = *(undefined4 *)(in_ECX + 0xd0);
    iVar5 = *(int *)(in_ECX + 0x24);
    iVar2 = *(int *)(iVar5 + 0x142c);
    iVar3 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&local_8);
    if (*(int *)(iVar5 + 0x1430) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(iVar5 + 0x1430) = *(int *)(iVar5 + 0x1430) + 1;
    *(int *)(iVar2 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    local_8 = (undefined4 *)FUN_00891268(0x1c);
    if (local_8 == (undefined4 *)0x0) {
LAB_0076a7de:
      local_8 = (undefined4 *)0x0;
      goto LAB_0076a7e0;
    }
    iVar5 = *(int *)(in_ECX + 0xd4);
    uVar1 = *(undefined4 *)(iVar5 + 0x10);
    local_8[1] = 0xffffffff;
    local_8[2] = 0xffffffff;
    local_8[3] = 0;
    local_8[4] = uVar1;
  }
  *local_8 = FoxUI::FXUIEventI1P1::vftable;
  local_8[5] = 0x387;
  local_8[6] = iVar5;
LAB_0076a7e0:
  local_8[3] = *(undefined4 *)(in_ECX + 0xd0);
  iVar5 = *(int *)(in_ECX + 0x24);
  iVar2 = *(int *)(iVar5 + 0x142c);
  iVar3 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&local_8);
  if (*(int *)(iVar5 + 0x1430) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x1430) = *(int *)(iVar5 + 0x1430) + 1;
  *(int *)(iVar2 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  piVar4 = (int *)FUN_00891268(0x14);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = (int)FoxUI::FXUIEvent::vftable;
    piVar4[1] = -1;
    piVar4[2] = -1;
    piVar4[3] = 0;
    piVar4[4] = 0x387;
  }
  if (*(int *)(in_ECX + 0x60) != 0) {
    piVar4[1] = *(int *)(in_ECX + 0x20);
    piVar4[2] = *(int *)(in_ECX + 0x48);
    (**(code **)(**(int **)(in_ECX + 0x60) + 0x148))(piVar4);
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x10))(1);
  }
  return;
}

