
void FUN_006fa390(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  
  if (*(int *)(unaff_ESI + 0x20) != 0) {
    pbVar1 = (byte *)(*(int *)(unaff_ESI + 0x20) + 5);
    *pbVar1 = *pbVar1 & 0xfc;
  }
  iVar4 = 0;
  if (0 < *(int *)(unaff_ESI + 0x28)) {
    iVar3 = 0;
    do {
      if ((3 < *(int *)(*(int *)(unaff_ESI + 8) + 8 + iVar3)) &&
         (iVar2 = *(int *)(*(int *)(unaff_ESI + 8) + iVar3), (*(byte *)(iVar2 + 5) & 3) != 0)) {
        FUN_006f9f70(param_1,iVar2);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x10;
    } while (iVar4 < *(int *)(unaff_ESI + 0x28));
  }
  iVar4 = 0;
  if (0 < *(int *)(unaff_ESI + 0x24)) {
    do {
      if (*(int *)(*(int *)(unaff_ESI + 0x1c) + iVar4 * 4) != 0) {
        pbVar1 = (byte *)(*(int *)(*(int *)(unaff_ESI + 0x1c) + iVar4 * 4) + 5);
        *pbVar1 = *pbVar1 & 0xfc;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_ESI + 0x24));
  }
  if (0 < *(int *)(unaff_ESI + 0x34)) {
    iVar4 = 0;
    do {
      if ((*(int *)(*(int *)(unaff_ESI + 0x10) + iVar4 * 4) != 0) &&
         (iVar3 = *(int *)(*(int *)(unaff_ESI + 0x10) + iVar4 * 4), (*(byte *)(iVar3 + 5) & 3) != 0)
         ) {
        FUN_006f9f70(param_1,iVar3);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_ESI + 0x34));
  }
  iVar4 = 0;
  if (0 < *(int *)(unaff_ESI + 0x38)) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(unaff_ESI + 0x18);
      if (*(int *)(iVar3 + iVar2) != 0) {
        *(byte *)(*(int *)(iVar2 + iVar3) + 5) = *(byte *)(*(int *)(iVar2 + iVar3) + 5) & 0xfc;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar4 < *(int *)(unaff_ESI + 0x38));
  }
  return;
}

