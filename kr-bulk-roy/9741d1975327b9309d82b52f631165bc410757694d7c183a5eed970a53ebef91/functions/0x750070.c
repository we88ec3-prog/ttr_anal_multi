
void FUN_00750070(void)

{
  int *piVar1;
  int *piVar2;
  code *in_EDX;
  int unaff_EBX;
  int *unaff_ESI;
  int unaff_EDI;
  
  while( true ) {
    (*in_EDX)();
    (**(code **)(**(int **)(unaff_ESI[2] + 8) + 0xcc))();
    unaff_ESI = (int *)*unaff_ESI;
    if (unaff_ESI == (int *)unaff_EBX) break;
    in_EDX = *(code **)(*(int *)unaff_ESI[2] + 0x40);
  }
  piVar1 = *(int **)(unaff_EDI + 0x1480);
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*(int *)(unaff_EDI + 0x1480) + 4) = *(int *)(unaff_EDI + 0x1480);
  *(undefined4 *)(unaff_EDI + 0x1484) = 0;
  if (piVar2 != *(int **)(unaff_EDI + 0x1480)) {
    do {
      piVar2 = (int *)*piVar2;
      FUN_0089120c();
    } while (piVar2 != (int *)*(int *)(unaff_EDI + 0x1480));
  }
  return;
}

