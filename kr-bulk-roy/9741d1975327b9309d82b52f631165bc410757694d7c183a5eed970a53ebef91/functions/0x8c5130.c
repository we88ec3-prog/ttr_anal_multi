
undefined2 FUN_008c5130(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uVar3 = param_2 - CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 0xc),
                                               *(undefined1 *)(iVar1 + 0xd)),
                                      *(undefined1 *)(iVar1 + 0xe)),*(undefined1 *)(iVar1 + 0xf));
  uVar2 = 0;
  if (uVar3 < CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 0x10),*(undefined1 *)(iVar1 + 0x11)
                                        ),*(undefined1 *)(iVar1 + 0x12)),
                       *(undefined1 *)(iVar1 + 0x13))) {
    uVar2 = CONCAT11(*(undefined1 *)(iVar1 + 0x14 + uVar3 * 2),
                     *(undefined1 *)(iVar1 + 0x15 + uVar3 * 2));
  }
  return uVar2;
}

