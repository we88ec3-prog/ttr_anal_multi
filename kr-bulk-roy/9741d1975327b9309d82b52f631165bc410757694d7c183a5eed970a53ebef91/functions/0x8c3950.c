
int FUN_008c3950(void)

{
  int iVar1;
  undefined1 *puVar2;
  uint in_EAX;
  int iVar3;
  int iVar4;
  uint uVar5;
  int unaff_EBX;
  
  iVar3 = 0;
  if (in_EAX < 0x10000) {
    uVar5 = in_EAX >> 8;
    iVar1 = unaff_EBX + 0x206;
    if (uVar5 == 0) {
      puVar2 = (undefined1 *)(unaff_EBX + 6 + (in_EAX & 0xff) * 2);
      if (CONCAT11(*puVar2,puVar2[1]) == 0) {
        return iVar1;
      }
    }
    else {
      iVar4 = (CONCAT11(*(undefined1 *)(unaff_EBX + 6 + uVar5 * 2),
                        *(undefined1 *)(unaff_EBX + 7 + uVar5 * 2)) & 0xfffffff8) + iVar1;
      if (iVar4 != iVar1) {
        iVar3 = iVar4;
      }
    }
  }
  return iVar3;
}

