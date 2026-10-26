
void FUN_00712ea0(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  uint local_8;
  
  iVar1 = FUN_00712db0(param_1);
  if (iVar1 != 0) {
    return;
  }
  if ((param_1 == 0x12) || (param_1 == 0x14)) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_00712740();
  }
  iVar1 = FUN_00712740();
  if ((int)local_8 < iVar1) {
    if (((*param_2 == 0xc) && ((param_2[2] & 0x100U) == 0)) &&
       ((int)(uint)*(byte *)(unaff_EDI + 0x32) <= param_2[2])) {
      *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + -1;
    }
    if (*param_3 != 0xc) goto LAB_00712f57;
    uVar2 = param_3[2];
  }
  else {
    if (((*param_3 == 0xc) && ((param_3[2] & 0x100U) == 0)) &&
       ((int)(uint)*(byte *)(unaff_EDI + 0x32) <= param_3[2])) {
      *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + -1;
    }
    if (*param_2 != 0xc) goto LAB_00712f57;
    uVar2 = param_2[2];
  }
  if (((uVar2 & 0x100) == 0) && ((int)(uint)*(byte *)(unaff_EDI + 0x32) <= (int)uVar2)) {
    *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + -1;
  }
LAB_00712f57:
  iVar1 = FUN_00713370((iVar1 << 9 | local_8) << 0xe | param_1,
                       *(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 8));
  param_2[2] = iVar1;
  *param_2 = 0xb;
  return;
}

