
undefined4 FUN_0047da00(int param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  if ((*(int *)(in_ECX[0x3f] + 0xcc) == 0) ||
     (piVar1 = *(int **)(*(int *)(in_ECX[0x3f] + 0xcc) + 0xdc), piVar1 == (int *)0x0)) {
    piVar1 = (int *)0x0;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 0x12d) {
      if ((char)piVar1[0x9b] != '\0') {
        return 0;
      }
    }
    else {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      piVar1 = (int *)0x0;
    }
  }
  if (param_1 != 0x2af9) {
    return 0;
  }
  if (piVar1 != (int *)0x0) {
    FUN_0047b6b0(piVar1);
  }
  (**(code **)(*in_ECX + 0xd4))();
  return 1;
}

