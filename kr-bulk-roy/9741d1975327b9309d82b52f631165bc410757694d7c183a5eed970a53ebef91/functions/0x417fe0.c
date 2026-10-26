
void FUN_00417fe0(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  
  if (param_1[4] == 0x578) {
    iVar1 = 0;
    piVar2 = (int *)(in_ECX + 0x84);
    do {
      if (param_1[2] == *(int *)(*piVar2 + 0x20)) {
        uVar3 = FUN_0075d720();
        FUN_00414fc0(uVar3,0);
        FUN_00414ef0(in_ECX,0);
        FUN_00415690();
        return;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < 7);
    uVar4 = 0;
    piVar2 = (int *)(in_ECX + 0x9c);
    while (param_1[2] != *(int *)(*piVar2 + 0x20)) {
      uVar4 = uVar4 + 1;
      piVar2 = piVar2 + 1;
      if (6 < uVar4) {
        return;
      }
    }
    FUN_00414fc0(*(undefined4 *)(in_ECX + 0x1a0),uVar4);
    FUN_00414ef0(in_ECX,uVar4);
    FUN_00415690();
  }
  else if (param_1[4] == 0x70b) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    FUN_004180d0(in_ECX);
    return;
  }
  return;
}

