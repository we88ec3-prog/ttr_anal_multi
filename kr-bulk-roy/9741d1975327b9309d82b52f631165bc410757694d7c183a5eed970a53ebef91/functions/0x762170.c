
void FUN_00762170(void)

{
  short sVar1;
  uint uVar2;
  BOOL BVar3;
  HANDLE hMem;
  short *psVar4;
  undefined4 *puVar5;
  int *in_ECX;
  short *psVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint local_34;
  undefined4 local_30;
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911bd8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  BVar3 = IsClipboardFormatAvailable(0xd);
  if (BVar3 != 0) {
    (**(code **)(*in_ECX + 0x1b0))(uVar2);
    OpenClipboard(*(HWND *)(in_ECX[9] + 4));
    hMem = GetClipboardData(0xd);
    psVar4 = GlobalLock(hMem);
    iVar9 = 0;
    local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
    local_1c = 7;
    local_20 = 0;
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
    uVar2 = local_20;
    local_8 = 0;
    if (in_ECX[0x51] == 0) {
      local_34 = local_20;
    }
    else {
      local_34 = in_ECX[0x51] - in_ECX[0x46];
      if (local_20 < local_34) {
        local_34 = local_20;
      }
    }
    iVar10 = 0;
    puVar5 = local_30;
    uVar8 = local_1c;
    if (0 < (int)local_20) {
      do {
        puVar7 = puVar5;
        if (uVar8 < 8) {
          puVar7 = &local_30;
        }
        if (*(short *)((int)puVar7 + iVar10 * 2) != 0xd) {
          puVar7 = puVar5;
          if (uVar8 < 8) {
            puVar7 = &local_30;
          }
          if (*(short *)((int)puVar7 + iVar10 * 2) != 10) {
            if ((char)in_ECX[0x50] == '\0') {
LAB_0076228d:
              if (iVar9 < (int)local_34) {
                if (uVar8 < 8) {
                  puVar5 = &local_30;
                }
                FUN_00761550(in_ECX,(int)puVar5 + iVar10 * 2,1);
                in_ECX[0x53] = in_ECX[0x53] + 1;
                iVar9 = iVar9 + 1;
                puVar5 = local_30;
                uVar8 = local_1c;
              }
            }
            else {
              puVar7 = puVar5;
              if (uVar8 < 8) {
                puVar7 = &local_30;
              }
              if (0x2f < *(ushort *)((int)puVar7 + iVar10 * 2)) {
                puVar7 = puVar5;
                if (uVar8 < 8) {
                  puVar7 = &local_30;
                }
                if (*(ushort *)((int)puVar7 + iVar10 * 2) < 0x3a) goto LAB_0076228d;
              }
            }
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)uVar2);
      if (0 < iVar9) {
        puVar5 = (undefined4 *)FUN_00891268(0x14);
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = FoxUI::FXUIEvent::vftable;
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0x3ec;
        }
        FUN_00748900();
      }
    }
    GlobalUnlock(hMem);
    CloseClipboard();
    in_ECX[0x58] = in_ECX[0x53];
    in_ECX[0x59] = in_ECX[0x53];
    FUN_00761800();
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

