
void FUN_008b8760(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  
  iVar1 = *(int *)(param_1 + 0x58);
  psVar3 = (short *)(param_2 * 0x10 + *(int *)(param_1 + 0x20));
  *(short *)(iVar1 + 0xc) = (short)(*(int *)(psVar3 + 4) + 0x20 >> 6);
  *(short *)(iVar1 + 0xe) = (short)(*(int *)(psVar3 + 6) + 0x20 >> 6);
  if ((*(byte *)(param_1 + 8) & 1) != 0) {
    uVar2 = FUN_008b7f40(*(undefined4 *)(psVar3 + 4),*(undefined2 *)(param_1 + 0x44));
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
    uVar2 = FUN_008b7f40(*(undefined4 *)(psVar3 + 6),*(undefined2 *)(param_1 + 0x44));
    *(undefined4 *)(iVar1 + 0x14) = uVar2;
    FUN_008b8700();
    return;
  }
  *(undefined4 *)(iVar1 + 0x10) = 0x10000;
  *(undefined4 *)(iVar1 + 0x14) = 0x10000;
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(psVar3 + 6);
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(int *)(iVar1 + 0x20) = (int)*psVar3 << 6;
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(psVar3 + 4);
  return;
}

