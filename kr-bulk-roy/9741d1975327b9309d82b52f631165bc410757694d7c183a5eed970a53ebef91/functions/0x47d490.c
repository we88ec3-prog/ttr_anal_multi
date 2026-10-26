
void FUN_0047d490(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  FUN_0047cb00(unaff_ESI,*(undefined4 *)(unaff_ESI + 0x11c));
  iVar2 = *(int *)(*(int *)(unaff_ESI + 0xfc) + 0xcc);
  if (iVar2 != 0) {
    for (piVar1 = *(int **)(iVar2 + 0xa8); piVar1 != *(int **)(iVar2 + 0xac); piVar1 = piVar1 + 1) {
      piVar3 = (int *)*piVar1;
      if (piVar3[8] == *(int *)(unaff_ESI + 0x124)) {
        if (piVar3 != (int *)0x0) {
          iVar2 = (**(code **)(*piVar3 + 4))();
          if (iVar2 == 0x12d) goto LAB_0047d503;
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        }
        break;
      }
    }
  }
  piVar3 = (int *)0x0;
LAB_0047d503:
  if (*(int *)(*(int *)(unaff_ESI + 0xfc) + 0xcc) != 0) {
    FUN_0042c8e0(*(undefined4 *)(unaff_ESI + 0x124));
  }
  FUN_0047d810(unaff_ESI,piVar3);
  return;
}

