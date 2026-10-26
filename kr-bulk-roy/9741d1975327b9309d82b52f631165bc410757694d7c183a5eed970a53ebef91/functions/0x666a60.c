
void FUN_00666a60(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_EAX;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  
  if (in_EAX != (int *)0x0) {
    iVar3 = (**(code **)(*in_EAX + 4))();
    if (iVar3 == 0x105ca) goto LAB_00666a99;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_00666a99:
  iVar3 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar3 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(iVar3 + 0xa8);
  }
  piVar6 = (int *)*piVar4;
  uVar5 = piVar4[1] - (int)piVar6 >> 2;
  uVar7 = 0;
  if (uVar5 != 0) {
    do {
      if ((*(int *)(*piVar6 + 0x260) == in_EAX[6]) && (*(int *)(*piVar6 + 0x264) == in_EAX[7])) {
        if (*(int *)(*(int *)(param_1 + 0xec) + 0xcc) != 0) {
          FUN_00666b70();
        }
        break;
      }
      uVar7 = uVar7 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar7 < uVar5);
  }
  piVar4 = *(int **)(param_1 + 0xec);
  puVar1 = (undefined4 *)piVar4[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    if ((*(int *)(iVar3 + 0x60) != 0) && ((*(int **)(iVar3 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar3 + 0x1c) + 0x30))(iVar3);
    }
  }
  (**(code **)(*piVar4 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  return;
}

