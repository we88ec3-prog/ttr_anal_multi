
void FUN_00619960(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x10) != 0x641) {
    return;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0x24c);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0xcc);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(iVar1 + 0xdc);
    }
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 4))();
      if (iVar1 == 0x4b4) goto LAB_006199c1;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  piVar2 = (int *)0x0;
LAB_006199c1:
  *(undefined1 *)(in_ECX + 0xfc) = *(undefined1 *)((int)piVar2 + 0x249);
  FUN_00619150(*(undefined1 *)(in_ECX + 0xfd));
  return;
}

