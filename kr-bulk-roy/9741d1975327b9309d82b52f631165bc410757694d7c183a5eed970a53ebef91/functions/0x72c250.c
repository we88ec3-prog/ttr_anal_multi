
void FUN_0072c250(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  int in_EDX;
  uint uVar6;
  uint uVar7;
  int unaff_EDI;
  ushort auStack_28 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = 1;
  uVar5 = 0;
  do {
    uVar5 = (*(short *)(in_EDX + iVar2 * 2 + -2) + uVar5) * 2;
    auStack_28[iVar2] = uVar5;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  iVar2 = 0;
  if (-1 < param_1) {
    do {
      uVar6 = (uint)*(ushort *)(unaff_EDI + 2 + iVar2 * 4);
      if (uVar6 != 0) {
        uVar3 = (uint)auStack_28[uVar6];
        auStack_28[uVar6] = auStack_28[uVar6] + 1;
        uVar1 = 0;
        do {
          uVar4 = uVar1;
          uVar7 = uVar3 & 1;
          uVar6 = uVar6 - 1;
          uVar3 = uVar3 >> 1;
          uVar1 = (uVar4 | uVar7) * 2;
        } while (0 < (int)uVar6);
        *(ushort *)(unaff_EDI + iVar2 * 4) = (ushort)uVar4 | (ushort)uVar7;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= param_1);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

