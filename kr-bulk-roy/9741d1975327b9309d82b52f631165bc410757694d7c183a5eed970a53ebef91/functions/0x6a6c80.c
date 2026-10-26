
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a6c80(undefined4 param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bd) {
      FUN_006a6ce0(param_1,unaff_ESI[5]);
      return;
    }
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_006a6ce0(param_1,_DAT_00000014);
  return;
}

