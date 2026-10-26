
void FUN_0082d5b0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EDI;
  int local_94;
  uint local_90;
  CHAR local_88 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(unaff_EDI + 0x14) - *(int *)(unaff_EDI + 0x10);
  iVar1 = iVar2 >> 0x1f;
  iVar2 = iVar2 / 0x38 + iVar1;
  uVar3 = iVar2 - iVar1;
  local_94 = 0;
  local_90 = 0;
  if (iVar2 != iVar1) {
    do {
      uVar4 = 0;
      do {
        if ((local_90 != uVar4) && (iVar1 = FUN_00832f60(), iVar1 != 0)) {
          FUN_00832ec0(uVar4);
          local_94 = local_94 + 1;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
      local_90 = local_90 + 1;
    } while (local_90 < uVar3);
  }
  FUN_006f0490("NeighborInfo Count : %d\n",local_94);
  OutputDebugStringA(local_88);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

