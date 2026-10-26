
void FUN_00699130(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *in_EAX;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  (**(code **)(*param_1 + 0x90))(1);
  if (in_EAX != (int *)0x0) {
    puVar4 = (undefined1 *)(**(code **)(*in_EAX + 4))();
    if (puVar4 == &DAT_000f4282) goto LAB_0069917f;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0069917f:
  uVar7 = in_EAX[6] - in_EAX[5] >> 2;
  if (*(int *)(param_1[0x3d] + 0xcc) != 0) {
    FUN_00408920(*(int *)(param_1[0x3d] + 0xcc),uVar7);
  }
  uVar6 = 0;
  if (uVar7 != 0) {
    do {
      iVar5 = *(int *)(param_1[0x3d] + 0xcc);
      if (((iVar5 == 0) || ((int)uVar6 < 0)) ||
         (*(int *)(iVar5 + 0xac) - *(int *)(iVar5 + 0xa8) >> 2 <= (int)uVar6)) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*(int *)(iVar5 + 0xa8) + uVar6 * 4);
      }
      *(int **)(iVar5 + 600) = param_1;
      FUN_00697710(*(undefined4 *)(in_EAX[5] + uVar6 * 4));
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar7);
  }
  piVar1 = (int *)param_1[0x3d];
  puVar2 = (undefined4 *)piVar1[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar5 = puVar3[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*(int *)param_1[0x3d] + 200))();
  return;
}

