
void FUN_00753890(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x10);
  while (iVar2 != 0) {
    piVar1 = (int *)FUN_007537f0();
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x10))(1);
    }
    if (*(int *)(unaff_ESI + 0x10) != 0) {
      *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;
      if ((uint)(*(int *)(unaff_ESI + 8) * 4) <= *(uint *)(unaff_ESI + 0xc)) {
        *(undefined4 *)(unaff_ESI + 0xc) = 0;
      }
      iVar2 = *(int *)(unaff_ESI + 0x10) + -1;
      *(int *)(unaff_ESI + 0x10) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(unaff_ESI + 0xc) = 0;
      }
    }
    iVar2 = *(int *)(unaff_ESI + 0x10);
  }
  return;
}

