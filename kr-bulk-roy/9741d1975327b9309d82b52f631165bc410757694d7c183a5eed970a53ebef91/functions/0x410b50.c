
void FUN_00410b50(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *in_EAX;
  int iVar3;
  int unaff_ESI;
  
  if (in_EAX != (int *)0x0) {
    iVar3 = (**(code **)(*in_EAX + 4))();
    if (iVar3 == 0x105bc) goto LAB_00410b7d;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_00410b7d:
  iVar3 = *(int *)(unaff_ESI + 0x110);
  uVar1 = *(undefined1 *)(unaff_ESI + 0x144);
  uVar2 = *(undefined1 *)(unaff_ESI + 0x145);
  *(int *)(iVar3 + 0x108) = in_EAX[5];
  *(undefined1 *)(iVar3 + 0x104) = uVar2;
  *(undefined1 *)(iVar3 + 0x105) = uVar1;
  FUN_004704c0(iVar3);
                    /* WARNING: Could not recover jumptable at 0x00410bb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_ESI + 0x110) + 200))();
  return;
}

