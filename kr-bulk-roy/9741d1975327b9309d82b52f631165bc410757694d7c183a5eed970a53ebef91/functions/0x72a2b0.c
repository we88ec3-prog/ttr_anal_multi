
void FUN_0072a2b0(void)

{
  ushort uVar1;
  int iVar2;
  int unaff_ESI;
  
  *(int *)(unaff_ESI + 0x3c) = *(int *)(unaff_ESI + 0x2c) * 2;
  *(undefined2 *)(*(int *)(unaff_ESI + 0x44) + -2 + *(int *)(unaff_ESI + 0x4c) * 2) = 0;
  _memset(*(void **)(unaff_ESI + 0x44),0,*(int *)(unaff_ESI + 0x4c) * 2 - 2);
  iVar2 = *(int *)(unaff_ESI + 0x84) * 0xc;
  *(uint *)(unaff_ESI + 0x80) = (uint)*(ushort *)(&DAT_00c0ad22 + *(int *)(unaff_ESI + 0x84) * 0xc);
  *(uint *)(unaff_ESI + 0x8c) = (uint)*(ushort *)(&DAT_00c0ad20 + iVar2);
  *(uint *)(unaff_ESI + 0x90) = (uint)*(ushort *)(&DAT_00c0ad24 + iVar2);
  uVar1 = *(ushort *)(&DAT_00c0ad26 + iVar2);
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  *(undefined4 *)(unaff_ESI + 0x5c) = 0;
  *(undefined4 *)(unaff_ESI + 0x74) = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(uint *)(unaff_ESI + 0x7c) = (uint)uVar1;
  *(undefined4 *)(unaff_ESI + 0x78) = 2;
  *(undefined4 *)(unaff_ESI + 0x60) = 2;
  return;
}

