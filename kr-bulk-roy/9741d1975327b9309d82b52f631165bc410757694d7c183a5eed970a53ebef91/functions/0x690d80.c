
void FUN_00690d80(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x134) + 0x24c);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0xcc);
    if (iVar2 == 0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)FUN_00412c70(*(undefined4 *)(iVar2 + 0xe4));
    }
    FUN_00757710();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      if (iVar2 == 0x4b4) goto LAB_00690df1;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  piVar1 = (int *)0x0;
LAB_00690df1:
  FUN_00691c80();
  piVar1[0x92] = param_3;
  return;
}

