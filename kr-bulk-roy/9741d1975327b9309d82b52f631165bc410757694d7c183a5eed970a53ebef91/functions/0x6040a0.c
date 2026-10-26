
void FUN_006040a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int *piVar5;
  int local_10;
  int local_8;
  
  iVar3 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
  if (iVar3 != 0) {
    FUN_00408920(iVar3,6);
  }
  iVar3 = *(int *)(*(int *)(in_ECX + 0x11c) + 0xcc);
  if (iVar3 != 0) {
    FUN_00408920(iVar3,6);
  }
  local_8 = 0;
  piVar5 = (int *)(in_ECX + 0x104);
  local_10 = 6;
  do {
    iVar3 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
    if ((((iVar3 == 0) || (local_8 < 0)) ||
        (*(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2 <= local_8)) ||
       (piVar4 = *(int **)((int)piVar5 + *(int *)(iVar3 + 0xa8) + (-0x104 - in_ECX)),
       piVar4 == (int *)0x0)) {
LAB_00604162:
      piVar4 = (int *)0x0;
    }
    else {
      iVar3 = (**(code **)(*piVar4 + 4))();
      if (iVar3 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00604162;
      }
    }
    *piVar5 = (int)piVar4;
    (**(code **)(*piVar4 + 0x198))(0x7595);
    *(int *)(*piVar5 + 0x2a8) = in_ECX;
    iVar3 = *(int *)(*(int *)(in_ECX + 0x11c) + 0xcc);
    if (((iVar3 == 0) || (local_8 < 0)) ||
       ((*(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2 <= local_8 ||
        (piVar4 = *(int **)(*(int *)(iVar3 + 0xa8) + (-0x104 - in_ECX) + (int)piVar5),
        piVar4 == (int *)0x0)))) {
LAB_006041e0:
      piVar4 = (int *)0x0;
    }
    else {
      iVar3 = (**(code **)(*piVar4 + 4))();
      if (iVar3 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_006041e0;
      }
    }
    piVar5[8] = (int)piVar4;
    (**(code **)(*piVar4 + 0x198))(0x9ca5);
    local_8 = local_8 + 1;
    piVar5 = piVar5 + 1;
    local_10 = local_10 + -1;
    if (local_10 == 0) {
      *(undefined4 *)(*(int *)(in_ECX + 0x18c) + 0x144) = 0x14;
      piVar5 = *(int **)(in_ECX + 0xfc);
      puVar1 = (undefined4 *)piVar5[0x19];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        iVar3 = puVar2[2];
        if ((*(int *)(iVar3 + 0x60) != 0) && ((*(int **)(iVar3 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar3 + 0x1c) + 0x30))(iVar3);
        }
      }
      (**(code **)(*piVar5 + 0x128))();
      piVar5 = *(int **)(in_ECX + 0x11c);
      puVar1 = (undefined4 *)piVar5[0x19];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        iVar3 = puVar2[2];
        if ((*(int *)(iVar3 + 0x60) != 0) && ((*(int **)(iVar3 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar3 + 0x1c) + 0x30))(iVar3);
        }
      }
      (**(code **)(*piVar5 + 0x128))();
      return;
    }
  } while( true );
}

