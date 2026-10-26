
void FUN_006fea00(void)

{
  byte *pbVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_EDI;
  
  iVar5 = 0xbc;
  do {
    pcVar3 = *(char **)((int)&PTR_FUN_00c0be84 + iVar5);
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    uVar4 = FUN_006fec70();
    *(undefined4 *)(iVar5 + *(int *)(unaff_EDI + 0x10)) = uVar4;
    pbVar1 = (byte *)(*(int *)(*(int *)(unaff_EDI + 0x10) + iVar5) + 5);
    *pbVar1 = *pbVar1 | 0x20;
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0x100);
  return;
}

