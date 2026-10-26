
void FUN_008ce880(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint *unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI[5] + 4);
  iVar3 = *(int *)(unaff_ESI[5] + 8);
  uVar4 = 0;
  if (*unaff_ESI != 0) {
    puVar5 = (undefined4 *)(unaff_ESI[2] + 0x24);
    do {
      if (param_1 == 0) {
        *(undefined4 *)(iVar2 + uVar4 * 8) = *puVar5;
      }
      else {
        *(undefined4 *)(iVar2 + 4 + uVar4 * 8) = *puVar5;
      }
      if ((*(byte *)(puVar5 + -5) & 0x10) != 0) {
        pbVar1 = (byte *)(uVar4 + iVar3);
        *pbVar1 = *pbVar1 | (-(param_1 != 0) & 0x20U) + 0x20;
      }
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 10;
    } while (uVar4 < *unaff_ESI);
  }
  return;
}

