
void FUN_006f9560(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  int local_8;
  
  if (in_EAX == 0) {
    *(undefined **)(unaff_EDI + 0x10) = &DAT_00c0bfa8;
    local_8 = 0;
    iVar6 = 0;
  }
  else {
    local_8 = -1;
    for (uVar2 = in_EAX - 1; 0xff < uVar2; uVar2 = uVar2 >> 8) {
      local_8 = local_8 + 8;
    }
    local_8 = (byte)(&DAT_00c0bfd8)[uVar2] + 1 + local_8;
    if (0x1a < local_8) {
      FUN_006f8b60(param_1,"table overflow");
    }
    iVar6 = 1 << ((byte)local_8 & 0x1f);
    if (iVar6 + 1U < 0x8000000) {
      uVar3 = FUN_00700880(param_1,0,0,iVar6 << 5);
    }
    else {
      uVar3 = FUN_00700860(param_1);
    }
    *(undefined4 *)(unaff_EDI + 0x10) = uVar3;
    if (0 < iVar6) {
      iVar4 = 0;
      iVar5 = iVar6;
      do {
        iVar1 = *(int *)(unaff_EDI + 0x10);
        *(undefined4 *)(iVar1 + 0x1c + iVar4) = 0;
        *(undefined4 *)(iVar1 + 0x18 + iVar4) = 0;
        *(undefined4 *)(iVar1 + 8 + iVar4) = 0;
        iVar4 = iVar4 + 0x20;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  *(undefined1 *)(unaff_EDI + 7) = (undefined1)local_8;
  *(int *)(unaff_EDI + 0x14) = iVar6 * 0x20 + *(int *)(unaff_EDI + 0x10);
  return;
}

