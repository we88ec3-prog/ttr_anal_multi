
bool FUN_008ad5e7(void)

{
  bool bVar1;
  errno_t eVar2;
  int iVar3;
  undefined4 uVar4;
  int *unaff_EDI;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined4 local_c;
  long local_8;
  
  local_8 = 0;
  eVar2 = FID_conflict___get_dstbias(&local_8);
  if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  if (local_8 == 0) {
    return false;
  }
  iVar5 = unaff_EDI[5];
  if ((iVar5 != DAT_00d62a78) || (iVar5 != DAT_00d62a84)) {
    if (DAT_00f8d734 == 0) {
      uVar4 = 2;
      local_c = 1;
      if (iVar5 < 0x6b) {
        uVar4 = 1;
        local_c = 5;
      }
      FUN_008ad3f0(1,1,iVar5,uVar4,0,0,0,0,0);
      FUN_008ad3f0(0,1,unaff_EDI[5],local_c,0,0,0,0,0);
    }
    else {
      if (DAT_00f8d720 != 0) {
        uVar7 = 0;
        uVar6 = 0;
        uVar8 = DAT_00f8d726;
      }
      else {
        uVar7 = DAT_00f8d724;
        uVar6 = DAT_00f8d726;
        uVar8 = 0;
      }
      FUN_008ad3f0(1,DAT_00f8d720 == 0,iVar5,uVar6,uVar7,uVar8,DAT_00f8d72a,DAT_00f8d72c,
                   DAT_00f8d72e);
      if (DAT_00f8d6cc != 0) {
        uVar7 = 0;
        uVar6 = 0;
        iVar5 = unaff_EDI[5];
        uVar8 = DAT_00f8d6d2;
      }
      else {
        iVar5 = unaff_EDI[5];
        uVar7 = DAT_00f8d6d0;
        uVar6 = DAT_00f8d6d2;
        uVar8 = 0;
      }
      FUN_008ad3f0(0,DAT_00f8d6cc == 0,iVar5,uVar6,uVar7,uVar8,DAT_00f8d6d6,DAT_00f8d6d8,
                   DAT_00f8d6da);
    }
  }
  iVar5 = unaff_EDI[7];
  if (DAT_00d62a7c < DAT_00d62a88) {
    if ((iVar5 < DAT_00d62a7c) || (DAT_00d62a88 < iVar5)) {
      return false;
    }
    if ((DAT_00d62a7c < iVar5) && (iVar5 < DAT_00d62a88)) {
      return true;
    }
  }
  else {
    if (iVar5 < DAT_00d62a88) {
      return true;
    }
    if (DAT_00d62a7c < iVar5) {
      return true;
    }
    if ((DAT_00d62a88 < iVar5) && (iVar5 < DAT_00d62a7c)) {
      return false;
    }
  }
  iVar3 = ((unaff_EDI[2] * 0x3c + unaff_EDI[1]) * 0x3c + *unaff_EDI) * 1000;
  if (iVar5 == DAT_00d62a7c) {
    bVar1 = DAT_00d62a80 <= iVar3;
  }
  else {
    bVar1 = iVar3 < DAT_00d62a8c;
  }
  return bVar1;
}

