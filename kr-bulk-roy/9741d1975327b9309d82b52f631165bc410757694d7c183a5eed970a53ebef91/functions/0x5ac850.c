
void FUN_005ac850(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_ESI + 4))();
    if (iVar2 == 0x105cb) goto LAB_005ac87e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_005ac87e:
  piVar1 = *(int **)(unaff_EDI + 0x220);
  if (((uint)piVar1[10] >> 8 & 1) != 0) {
    return;
  }
  iVar2 = unaff_ESI[5];
  piVar1[0x30] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(*piVar1 + 0xd4))();
  }
                    /* WARNING: Could not recover jumptable at 0x005ac8b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 0x220) + 0xd0))();
  return;
}

