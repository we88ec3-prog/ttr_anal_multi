
int FUN_008f40d0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *unaff_ESI;
  int iVar2;
  int local_8;
  
  iVar1 = unaff_ESI[1];
  local_8 = 0;
  if (*unaff_ESI < iVar1) {
LAB_008f4139:
    iVar1 = *unaff_ESI;
    *unaff_ESI = iVar1 + 1;
    *param_2 = iVar1 * 0x30 + unaff_ESI[2];
    return 0;
  }
  if (iVar1 < 0x2aaaaaa) {
    iVar2 = (iVar1 >> 2) + 4 + iVar1;
    if ((iVar2 < iVar1) || (0x2aaaaaa < iVar2)) {
      iVar2 = 0x2aaaaaa;
    }
    iVar1 = FUN_008bc7d0(param_1,0x30,iVar1,iVar2,unaff_ESI[2],&local_8);
    unaff_ESI[2] = iVar1;
    if (local_8 == 0) {
      unaff_ESI[1] = iVar2;
      goto LAB_008f4139;
    }
  }
  else {
    local_8 = 0x40;
  }
  *param_2 = 0;
  return local_8;
}

