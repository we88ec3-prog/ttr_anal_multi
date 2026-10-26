
void FUN_006a4d60(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1[4] == 0x76c) {
    if (param_1[2] == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      FUN_006a4ef0();
    }
    return;
  }
  if (param_1[4] != 0xf43e7) {
    return;
  }
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x105bd) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    param_1 = (int *)0x0;
  }
  piVar2 = (int *)param_1[6];
  if (piVar2 == (int *)0x0) {
LAB_006a4dd5:
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 != 0x105ba) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006a4dd5;
    }
  }
  if (param_1[5] == 0x6a7) {
    FUN_0044fd50();
    iVar1 = piVar2[6];
    iVar3 = piVar2[5];
    uVar4 = 1;
  }
  else {
    if (param_1[5] != 0x6a8) goto LAB_006a4e0f;
    FUN_0044fd50();
    iVar1 = piVar2[6];
    iVar3 = piVar2[5];
    uVar4 = 0;
  }
  FUN_004ec750(iVar3,iVar1,uVar4);
LAB_006a4e0f:
  FUN_005bc100(in_ECX + 0x10c);
  return;
}

