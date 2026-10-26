
void FUN_00776150(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EDI;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = unaff_EDI[8];
  if ((local_8 != -1) && (in_EAX != 0)) {
    *unaff_EDI = in_EAX;
    iVar2 = *(int *)(in_EAX + 0x18);
    local_c = iVar2;
    FUN_0082ef00(&local_c);
    if ((local_10 != *(int *)(in_EAX + 8)) && (*(int *)(local_10 + 0x10) != 0)) {
      piVar3 = unaff_EDI + 1;
      if (7 < (uint)unaff_EDI[6]) {
        piVar3 = (int *)*piVar3;
      }
      iVar2 = unaff_EDI[9];
      iVar1 = FUN_0077d660(piVar3);
      if (iVar1 == 0) {
        unaff_EDI[10] = 0;
        return;
      }
      iVar2 = FUN_00773200(local_8,iVar2);
      unaff_EDI[10] = iVar2;
      return;
    }
    local_10 = iVar2;
    FUN_008438c0(&local_10);
    if ((local_c != *(int *)(in_EAX + 0x20)) && (*(int *)(local_c + 0x10) != 0)) {
      iVar2 = FUN_00773200(local_8,unaff_EDI[9]);
      unaff_EDI[10] = iVar2;
    }
  }
  return;
}

