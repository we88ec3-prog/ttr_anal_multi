
int FUN_008c7100(int param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar4 = (uint)*(ushort *)(param_1 + 8);
  pbVar5 = *(byte **)(param_1 + 0x10);
  iVar1 = FUN_008bc7d0(param_2,1,0,uVar4 + 1,0,&param_1);
  if (param_1 != 0) {
    return 0;
  }
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      bVar2 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      if (bVar2 == 0) break;
      if ((bVar2 < 0x20) || (0x7f < bVar2)) {
        bVar2 = 0x3f;
      }
      *(byte *)(uVar3 + iVar1) = bVar2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  *(undefined1 *)(uVar3 + iVar1) = 0;
  return iVar1;
}

