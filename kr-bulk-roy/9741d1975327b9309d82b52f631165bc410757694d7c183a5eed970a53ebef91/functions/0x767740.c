
void FUN_00767740(void)

{
  short sVar1;
  uint uVar2;
  BOOL BVar3;
  HANDLE hMem;
  short *psVar4;
  int iVar5;
  int *in_ECX;
  short *psVar6;
  undefined1 auStack_94 [4];
  short *local_90;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  undefined4 **local_54 [5];
  uint local_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091ed1d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_94;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  BVar3 = IsClipboardFormatAvailable(0xd);
  if (BVar3 != 0) {
    FUN_00767c20(uVar2);
    FUN_00757200(local_54);
    local_c = 0;
    OpenClipboard(*(HWND *)(in_ECX[9] + 4));
    hMem = GetClipboardData(0xd);
    psVar4 = GlobalLock(hMem);
    local_90 = psVar4 + 1;
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)local_90 >> 1);
    GlobalUnlock(hMem);
    CloseClipboard();
    local_5c = 7;
    local_60 = 0;
    local_70 = (uint)local_70._2_2_ << 0x10;
    FUN_00402160(&DAT_00bfb894,1);
    local_c._0_1_ = 1;
    local_8c = (uint)local_8c._2_2_ << 0x10;
    local_78 = 7;
    local_7c = 0;
    FUN_00402160(&DAT_00c059c0,2);
    local_c = CONCAT31(local_c._1_3_,2);
    FUN_00759330(local_54,&local_8c,&local_70);
    if (7 < local_78) {
      FUN_0089120c(local_8c);
    }
    local_c = local_c & 0xffffff00;
    local_78 = 7;
    local_7c = 0;
    local_8c = local_8c & 0xffff0000;
    if (7 < local_5c) {
      FUN_0089120c(local_70);
    }
    local_5c = 7;
    local_60 = 0;
    local_70 = local_70 & 0xffff0000;
    iVar5 = FUN_007680b0(local_54);
    if (0 < iVar5) {
      if (local_40 < 8) {
        local_54[0] = local_54;
      }
      FUN_007660d0(in_ECX,local_54[0],in_ECX[0x4f]);
      FUN_00767a80();
    }
    local_c = 0xffffffff;
    FUN_00757640(local_54);
  }
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
  (**(code **)(*in_ECX + 0x1b0))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_94);
  return;
}

