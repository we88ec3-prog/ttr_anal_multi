
void FUN_006cc5d0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)(in_ECX + 0x24c);
  FUN_0046b6f0(*(int *)(in_ECX + 0x20) + 8);
  if ((*piVar2 != 0) && (iVar1 = (**(code **)(*(int *)*piVar2 + 0x58))(), iVar1 != 0)) {
    piVar2 = (int *)(**(code **)(*(int *)*piVar2 + 0x58))();
    if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 4))(), iVar1 != 1000)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    FUN_0046b6f0(*(int *)(in_ECX + 0x20) + 0x2326);
    FUN_0046b6f0(*(int *)(in_ECX + 0x20) + 0x238a);
    FUN_0043c570(*(int *)(in_ECX + 0x20) + 0x23ee);
    FUN_0043c570(*(int *)(in_ECX + 0x20) + 0x2452);
    FUN_0043c570(*(int *)(in_ECX + 0x20) + 0x251a);
  }
  return;
}

