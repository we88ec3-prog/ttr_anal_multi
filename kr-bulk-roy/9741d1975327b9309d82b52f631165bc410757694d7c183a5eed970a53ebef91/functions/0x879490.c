
undefined4 FUN_00879490(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  float *unaff_ESI;
  bool bVar3;
  float local_8;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 != 0) {
    if (*(int *)(in_ECX + 0xc) != 0) {
      local_8 = 1.0;
      uVar2 = FUN_0089289d();
      uVar2 = uVar2 & 0x80000001;
      bVar3 = uVar2 == 0;
      if ((int)uVar2 < 0) {
        bVar3 = (uVar2 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (!bVar3) {
        local_8 = -1.0;
      }
      *unaff_ESI = local_8 * *unaff_ESI;
      unaff_ESI[1] = local_8 * unaff_ESI[1];
      unaff_ESI[2] = local_8 * unaff_ESI[2];
      return 1;
    }
    if (iVar1 != 0) goto LAB_008794f4;
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    return 1;
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_008794f4:
  if (*(int *)(in_ECX + 0xc) == 0) {
    *unaff_ESI = *unaff_ESI * -1.0;
    unaff_ESI[1] = unaff_ESI[1] * -1.0;
    unaff_ESI[2] = unaff_ESI[2] * -1.0;
    return 1;
  }
  return 0;
}

