
int FUN_008de1d0(undefined4 param_1)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  ushort uVar4;
  int unaff_EBX;
  int unaff_ESI;
  int iVar5;
  int local_8;
  
  uVar4 = 0;
  local_8 = 0;
  iVar5 = 0;
  if (*(int *)(unaff_ESI + 0x10) == 0) {
    if (unaff_EBX != 0) {
      puVar2 = *(ushort **)(unaff_ESI + 8);
      iVar5 = unaff_EBX;
      do {
        if (uVar4 < *puVar2) {
          uVar4 = *puVar2;
        }
        puVar2 = puVar2 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    uVar3 = FUN_008bc7d0(param_1,2,0,uVar4 + 1,0,&local_8);
    *(undefined4 *)(unaff_ESI + 0xc) = uVar3;
    iVar5 = local_8;
    iVar1 = unaff_EBX;
    if (local_8 == 0) {
      while (iVar1 = iVar1 + -1, -1 < iVar1) {
        *(short *)(*(int *)(unaff_ESI + 0xc) +
                  (uint)*(ushort *)(*(int *)(unaff_ESI + 8) + iVar1 * 2) * 2) = (short)iVar1;
      }
      *(uint *)(unaff_ESI + 0x10) = (uint)uVar4;
      *(int *)(unaff_ESI + 0x14) = unaff_EBX;
    }
  }
  return iVar5;
}

