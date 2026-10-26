
void FUN_0059aad0(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_ESI;
  
  if (param_1 != (int *)0x0) {
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 == 0x105ba) goto LAB_0059ab08;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  param_1 = (int *)0x0;
LAB_0059ab08:
  iVar3 = FUN_00443da0();
  uVar1 = *(undefined4 *)(iVar3 + 8);
  iVar3 = FUN_00443da0();
  uVar2 = *(undefined4 *)(iVar3 + 4);
  *(int *)(*(int *)(unaff_ESI + 0x184) + 0xfc) = param_1[5];
  *(int *)(*(int *)(unaff_ESI + 0x184) + 0xf8) = param_1[6];
  FUN_00749970(uVar1,uVar2);
  (**(code **)(**(int **)(unaff_ESI + 0x184) + 0xd0))();
  (**(code **)(**(int **)(unaff_ESI + 0x188) + 0xd4))();
  return;
}

