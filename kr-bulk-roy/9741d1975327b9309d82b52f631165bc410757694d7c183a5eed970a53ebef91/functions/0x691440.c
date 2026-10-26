
uint FUN_00691440(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  int unaff_EDI;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cfce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar5 = *(int *)(*(int *)(unaff_EDI + 0x138) + 0x24c);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xcc) != 0)) {
    FUN_006438f0();
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  FUN_005740f0();
  if (local_18 != DAT_00fe5ac8) {
    psVar6 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
    FUN_00690e20(unaff_EDI);
    iVar5 = *(int *)(unaff_EDI + 0x214) - *(int *)(unaff_EDI + 0x210);
    uVar3 = iVar5 * 0x38e38e39;
    uVar7 = 0;
    if (iVar5 / 0x24 + (iVar5 >> 0x1f) != iVar5 >> 0x1f) {
      iVar5 = 0;
      do {
        FUN_004026e0(*(int *)(unaff_EDI + 0x210) + iVar5,0,0xffffffff);
        FUN_00690e20(unaff_EDI);
        uVar3 = (*(int *)(unaff_EDI + 0x214) - *(int *)(unaff_EDI + 0x210)) / 0x24;
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 0x24;
      } while (uVar7 < uVar3);
    }
    ExceptionList = local_10;
    return uVar3;
  }
  pcVar2 = (code *)swi(3);
  uVar3 = (*pcVar2)();
  return uVar3;
}

