
void FUN_006bd400(void)

{
  int iVar1;
  int *unaff_EDI;
  
  iVar1 = unaff_EDI[0x27];
  if (iVar1 != 0) {
    if (unaff_EDI[0x25] != 0) {
      if (*(int *)(iVar1 + 8) == 1) {
        if ((*(int *)(iVar1 + 0xc) != 0) &&
           (iVar1 = FUN_00527040(*(int *)(iVar1 + 0xc)), iVar1 != 0)) {
          FUN_00757710();
        }
        (**(code **)(*unaff_EDI + 0xd0))();
        return;
      }
      FUN_006bd720();
      return;
    }
    unaff_EDI[0x26] = unaff_EDI[0x26] + 1;
    unaff_EDI[0x28] = *(int *)(iVar1 + 0x10) + unaff_EDI[0x26] * 0xc;
    if ((*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0x10)) / 0xc <= unaff_EDI[0x26] + 1) {
      unaff_EDI[0x25] = 1;
    }
    FUN_006bd050(unaff_EDI);
  }
  return;
}

