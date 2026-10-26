
int FUN_008c9f80(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x68);
  iVar3 = (**(code **)(unaff_ESI + 0x1fc))();
  if (iVar3 == 0) {
    FUN_008b9850(uVar1);
    iVar2 = *(int *)(unaff_ESI + 0x1d4);
    iVar3 = FUN_008b9820(uVar1,0x20);
    if (iVar3 == 0) {
      if (iVar2 == 0x20000) {
        iVar3 = FUN_008c9c10();
        *(undefined1 *)(unaff_ESI + 0x264) = 1;
        return iVar3;
      }
      if (iVar2 == 0x28000) {
        iVar3 = FUN_008c9eb0();
        *(undefined1 *)(unaff_ESI + 0x264) = 1;
        return iVar3;
      }
      iVar3 = 3;
      *(undefined1 *)(unaff_ESI + 0x264) = 1;
    }
  }
  return iVar3;
}

