
void FUN_0065d920(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  if (*(int *)(unaff_EDI[0x3d] + 0xcc) != 0) {
    iVar2 = *(int *)(*(int *)(unaff_EDI[0x3d] + 0xcc) + 0xdc);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x20);
    }
    if ((iVar2 != -1) && (unaff_EDI[0x5b] != iVar2)) {
      iVar1 = FUN_00404ba0();
      iVar2 = iVar2 + 1;
      if (((-1 < iVar2) &&
          (((iVar2 < 10 &&
            (iVar2 = *(int *)(iVar1 + 0x6924) + iVar2 * 0x210, *(int *)(iVar2 + 0x5c) != 0)) &&
           (iVar2 != 0)))) && (*(int *)(iVar2 + 0x5c) != 0)) {
        FUN_00414680();
        FUN_004a3660();
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0065d994. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_EDI + 0xd4))();
  return;
}

