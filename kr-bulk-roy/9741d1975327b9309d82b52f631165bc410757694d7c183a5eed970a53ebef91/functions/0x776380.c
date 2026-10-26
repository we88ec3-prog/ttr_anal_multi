
void FUN_00776380(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EDI;
  int local_c;
  undefined4 local_8;
  
  if ((unaff_EDI[8] != -1) && (iVar2 = *unaff_EDI, iVar2 != 0)) {
    local_8 = *(undefined4 *)(iVar2 + 0x18);
    FUN_0082ef00(&local_8);
    if ((local_c != *(int *)(iVar2 + 8)) && (*(int *)(local_c + 0x10) != 0)) {
      piVar3 = unaff_EDI + 1;
      if (7 < (uint)unaff_EDI[6]) {
        piVar3 = (int *)*piVar3;
      }
      iVar2 = unaff_EDI[9];
      iVar1 = FUN_0077d660(piVar3);
      if (iVar1 != 0) {
        iVar2 = FUN_00773200(param_1,iVar2);
        unaff_EDI[10] = iVar2;
        return;
      }
      unaff_EDI[10] = 0;
    }
  }
  return;
}

