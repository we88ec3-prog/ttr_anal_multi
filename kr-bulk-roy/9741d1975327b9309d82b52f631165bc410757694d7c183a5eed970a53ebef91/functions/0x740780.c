
void FUN_00740780(undefined4 param_1,char param_2)

{
  WCHAR WVar1;
  short sVar2;
  undefined1 uVar3;
  uint uVar4;
  UINT UVar5;
  WCHAR *pWVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  short ****ppppsVar11;
  int iVar12;
  short *psVar13;
  short ****ppppsVar14;
  short *in_ECX;
  int *unaff_FS_OFFSET;
  undefined1 auStack_434 [4];
  undefined4 *local_430;
  short *local_42c;
  undefined4 local_428 [2];
  undefined4 *local_420;
  undefined4 local_41c;
  short *local_414;
  undefined **local_410 [3];
  undefined1 local_404 [8];
  short ***local_3fc [4];
  uint local_3ec;
  uint local_3e8;
  undefined4 local_3e0;
  undefined4 local_3d0;
  uint local_3cc;
  uint local_3c4 [4];
  undefined4 local_3b4;
  uint local_3b0;
  uint local_3a8 [4];
  undefined4 local_398;
  uint local_394;
  uint local_38c [4];
  undefined4 local_37c;
  uint local_378;
  uint local_370 [4];
  undefined4 local_360;
  uint local_35c;
  undefined4 local_354;
  undefined4 local_344;
  uint local_340;
  uint local_338 [4];
  undefined4 local_328;
  uint local_324;
  undefined1 local_31c [116];
  undefined1 local_2a8 [120];
  WCHAR local_230;
  undefined1 local_22e [530];
  uint local_1c;
  int local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009159e9;
  local_14 = *unaff_FS_OFFSET;
  local_1c = DAT_00d61f20 ^ (uint)auStack_434;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffbc0;
  *unaff_FS_OFFSET = (int)&local_14;
  local_428[0] = param_1;
  local_41c = 0;
  local_420 = (undefined4 *)FUN_00891268(0x2820,uVar4);
  if (local_420 == (undefined4 *)0x0) {
    local_42c = (short *)0x0;
    std::exception::exception((exception *)local_410,(char **)&local_42c);
    local_410[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_410,&DAT_00c857a8);
  }
  *local_420 = local_420;
  local_420[1] = local_420;
  local_420[2] = local_420;
  *(undefined1 *)(local_420 + 0xa06) = 1;
  *(undefined1 *)((int)local_420 + 0x2819) = 1;
  local_3cc = 7;
  local_3d0 = 0;
  local_3e0 = (undefined4 *)((uint)local_3e0._2_2_ << 0x10);
  local_c = 1;
  if (param_2 == '\0') {
    psVar13 = in_ECX;
    do {
      sVar2 = *psVar13;
      psVar13 = psVar13 + 1;
    } while (sVar2 != 0);
    FUN_00402160(in_ECX,(int)psVar13 - (int)(in_ECX + 1) >> 1);
  }
  else {
    UVar5 = GetWindowsDirectoryW(&local_230,0x104);
    if (UVar5 == 0) {
      if (7 < local_3cc) {
        FUN_0089120c(local_3e0);
      }
      local_3cc = 7;
      local_3d0 = 0;
      local_3e0 = (undefined4 *)((uint)local_3e0 & 0xffff0000);
      local_c = 2;
      FUN_00741b10(local_428,*local_420,local_420);
      goto LAB_0074089a;
    }
    pWVar6 = &local_230;
    do {
      WVar1 = *pWVar6;
      pWVar6 = pWVar6 + 1;
    } while (WVar1 != L'\0');
    FUN_00402160(&local_230,(int)pWVar6 - (int)local_22e >> 1);
    FUN_00404300(L"\\Fonts\\",7);
    psVar13 = in_ECX;
    do {
      sVar2 = *psVar13;
      psVar13 = psVar13 + 1;
    } while (sVar2 != 0);
    FUN_00404300(in_ECX,(int)psVar13 - (int)(in_ECX + 1) >> 1);
  }
  puVar7 = local_3e0;
  if (local_3cc < 8) {
    puVar7 = &local_3e0;
  }
  FUN_00743180(puVar7);
  local_430 = (undefined4 *)*local_420;
  if (local_430 != local_420) {
    do {
      if (*(short *)((int)local_430 + 0x12) != 1) {
        local_3e8 = 7;
        local_3ec = 0;
        local_3fc[0] = (short ***)((uint)local_3fc[0] & 0xffff0000);
        FUN_00402160(&DAT_00bed1fc,0);
        local_c._0_1_ = 3;
        local_340 = 7;
        local_344 = 0;
        local_354 = local_354 & 0xffff0000;
        FUN_00402160(L"Regular",7);
        puVar7 = local_430;
        local_c._0_1_ = 4;
        uVar3 = (undefined1)local_c;
        local_c._0_1_ = 4;
        psVar13 = (short *)(local_430 + 6);
        local_42c = (short *)(local_430 + 0x606);
        if (*local_42c == 0) {
          if (*psVar13 != 0) {
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            iVar8 = (int)psVar13 - ((int)local_430 + 0x1a);
            psVar13 = (short *)(local_430 + 6);
            goto LAB_00740a34;
          }
          if (7 < local_340) {
            local_c._0_1_ = uVar3;
            FUN_0089120c(local_354);
          }
        }
        else {
          psVar13 = local_42c;
          do {
            sVar2 = *psVar13;
            psVar13 = psVar13 + 1;
          } while (sVar2 != 0);
          iVar8 = (int)psVar13 - ((int)local_430 + 0x181a);
          psVar13 = local_42c;
LAB_00740a34:
          FUN_00402160(psVar13,iVar8 >> 1);
          local_414 = (short *)(puVar7 + 0x806);
          if (*local_414 != 0) {
            psVar13 = local_414;
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            FUN_00402160(local_414,(int)psVar13 - ((int)puVar7 + 0x201a) >> 1);
          }
          if (local_3ec != 0) {
            local_3b0 = 7;
            local_3b4 = 0;
            local_3c4[0] = local_3c4[0] & 0xffff0000;
            psVar13 = local_414;
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            FUN_00402160(local_414,(int)psVar13 - (int)(local_414 + 1) >> 1);
            local_c._0_1_ = 5;
            local_3a8[0] = local_3a8[0] & 0xffff0000;
            local_394 = 7;
            local_398 = 0;
            psVar13 = local_42c;
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            FUN_00402160(local_42c,(int)psVar13 - (int)(local_42c + 1) >> 1);
            local_c._0_1_ = 6;
            local_370[0] = local_370[0] & 0xffff0000;
            psVar13 = (short *)(local_430 + 6);
            local_35c = 7;
            local_360 = 0;
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            FUN_00402160(local_430 + 6,(int)psVar13 - ((int)local_430 + 0x1a) >> 1);
            local_c._0_1_ = 7;
            ppppsVar11 = (short ****)local_3fc[0];
            if (local_3e8 < 8) {
              ppppsVar11 = local_3fc;
            }
            local_378 = 7;
            local_37c = 0;
            local_38c[0] = local_38c[0] & 0xffff0000;
            ppppsVar14 = ppppsVar11;
            do {
              sVar2 = *(short *)ppppsVar14;
              ppppsVar14 = (short ****)((int)ppppsVar14 + 2);
            } while (sVar2 != 0);
            FUN_00741900(ppppsVar11,(int)ppppsVar14 - (int)((int)ppppsVar11 + 2) >> 1);
            local_c._0_1_ = 8;
            FUN_007406c0(local_2a8,*(undefined2 *)(local_430 + 4),local_370,local_3a8,local_3c4);
            local_c._0_1_ = 9;
            local_324 = 7;
            local_328 = 0;
            local_338[0] = local_338[0] & 0xffff0000;
            FUN_004026e0(&local_354,0,0xffffffff);
            local_c._0_1_ = 10;
            FUN_00742cc0(local_31c);
            local_c = CONCAT31(local_c._1_3_,0xb);
            uVar9 = FUN_00741650(local_428[0]);
            uVar10 = FUN_00742b30(local_338);
            FUN_00742490(uVar9,local_404,uVar10);
            FUN_0073e5e0();
            if (7 < local_324) {
              FUN_0089120c(local_338[0]);
            }
            local_324 = 7;
            local_328 = 0;
            local_338[0] = local_338[0] & 0xffff0000;
            FUN_0073e5e0();
            if (7 < local_378) {
              FUN_0089120c(local_38c[0]);
            }
            local_378 = 7;
            local_37c = 0;
            local_38c[0] = local_38c[0] & 0xffff0000;
            if (7 < local_35c) {
              FUN_0089120c(local_370[0]);
            }
            local_35c = 7;
            local_360 = 0;
            local_370[0] = local_370[0] & 0xffff0000;
            if (7 < local_394) {
              FUN_0089120c(local_3a8[0]);
            }
            local_c._0_1_ = 4;
            local_394 = 7;
            local_398 = 0;
            local_3a8[0] = local_3a8[0] & 0xffff0000;
            if (7 < local_3b0) {
              FUN_0089120c(local_3c4[0]);
            }
          }
          if (4 < local_3ec) {
            ppppsVar11 = (short ****)local_3fc[0];
            if (local_3e8 < 8) {
              ppppsVar11 = local_3fc;
            }
            iVar8 = __wcsicmp((wchar_t *)((int)ppppsVar11 + (local_3ec - 4) * 2),L"Bold");
            if (iVar8 == 0) {
              iVar8 = local_3ec - 5;
              if (-1 < iVar8) {
                do {
                  ppppsVar11 = (short ****)local_3fc[0];
                  if (local_3e8 < 8) {
                    ppppsVar11 = local_3fc;
                  }
                  iVar12 = _isspace((uint)*(ushort *)((int)ppppsVar11 + iVar8 * 2));
                } while ((iVar12 != 0) && (iVar8 = iVar8 + -1, -1 < iVar8));
                if (iVar8 == 0) goto LAB_00740e78;
              }
              local_3b0 = 7;
              local_3b4 = 0;
              local_3c4[0] = local_3c4[0] & 0xffff0000;
              local_c._0_1_ = 0xc;
              ppppsVar11 = (short ****)local_3fc[0];
              if (local_3e8 < 8) {
                ppppsVar11 = local_3fc;
              }
              FUN_00402160(ppppsVar11,iVar8 + 1);
              FUN_004026e0(local_3c4,0,0xffffffff);
              FUN_00402160(L"Bold",4);
              local_c._0_1_ = 4;
              if (7 < local_3b0) {
                FUN_0089120c(local_3c4[0]);
              }
            }
          }
LAB_00740e78:
          if (local_3ec != 0) {
            local_3c4[0] = local_3c4[0] & 0xffff0000;
            local_3b0 = 7;
            local_3b4 = 0;
            psVar13 = local_414;
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            FUN_00402160(local_414,(int)psVar13 - (int)(local_414 + 1) >> 1);
            local_c._0_1_ = 0xd;
            local_38c[0] = local_38c[0] & 0xffff0000;
            local_378 = 7;
            local_37c = 0;
            psVar13 = local_42c;
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            FUN_00402160(local_42c,(int)psVar13 - (int)(local_42c + 1) >> 1);
            local_c._0_1_ = 0xe;
            psVar13 = (short *)(local_430 + 6);
            local_35c = 7;
            local_360 = 0;
            local_370[0] = local_370[0] & 0xffff0000;
            do {
              sVar2 = *psVar13;
              psVar13 = psVar13 + 1;
            } while (sVar2 != 0);
            FUN_00402160(local_430 + 6,(int)psVar13 - ((int)local_430 + 0x1a) >> 1);
            local_c._0_1_ = 0xf;
            ppppsVar11 = (short ****)local_3fc[0];
            if (local_3e8 < 8) {
              ppppsVar11 = local_3fc;
            }
            local_3a8[0] = local_3a8[0] & 0xffff0000;
            local_394 = 7;
            local_398 = 0;
            ppppsVar14 = ppppsVar11;
            do {
              sVar2 = *(short *)ppppsVar14;
              ppppsVar14 = (short ****)((int)ppppsVar14 + 2);
            } while (sVar2 != 0);
            FUN_00741900(ppppsVar11,(int)ppppsVar14 - (int)((int)ppppsVar11 + 2) >> 1);
            local_c._0_1_ = 0x10;
            FUN_007406c0(local_2a8,*(undefined2 *)(local_430 + 4),local_370,local_38c,local_3c4);
            local_c._0_1_ = 0x11;
            local_324 = 7;
            local_328 = 0;
            local_338[0] = local_338[0] & 0xffff0000;
            FUN_004026e0(&local_354,0,0xffffffff);
            local_c._0_1_ = 0x12;
            FUN_00742cc0(local_31c);
            local_c._0_1_ = 0x13;
            uVar9 = FUN_00741650(local_428[0]);
            uVar10 = FUN_00742b30(local_338);
            FUN_00742490(uVar9,local_410,uVar10);
            FUN_0073e5e0();
            if (7 < local_324) {
              FUN_0089120c(local_338[0]);
            }
            local_324 = 7;
            local_328 = 0;
            local_338[0] = local_338[0] & 0xffff0000;
            FUN_0073e5e0();
            if (7 < local_394) {
              FUN_0089120c(local_3a8[0]);
            }
            local_394 = 7;
            local_398 = 0;
            local_3a8[0] = local_3a8[0] & 0xffff0000;
            if (7 < local_35c) {
              FUN_0089120c(local_370[0]);
            }
            local_35c = 7;
            local_360 = 0;
            local_370[0] = local_370[0] & 0xffff0000;
            if (7 < local_378) {
              FUN_0089120c(local_38c[0]);
            }
            local_378 = 7;
            local_37c = 0;
            local_38c[0] = local_38c[0] & 0xffff0000;
            if (7 < local_3b0) {
              FUN_0089120c(local_3c4[0]);
            }
          }
          if (7 < local_340) {
            FUN_0089120c(local_354);
          }
        }
        local_c = CONCAT31(local_c._1_3_,1);
        local_340 = 7;
        local_354 = (uint)local_354._2_2_ << 0x10;
        local_344 = 0;
        if (7 < local_3e8) {
          FUN_0089120c(local_3fc[0]);
        }
      }
      FUN_00741b70();
    } while (local_430 != local_420);
  }
  if (7 < local_3cc) {
    FUN_0089120c(local_3e0);
  }
  local_3cc = 7;
  local_3d0 = 0;
  local_3e0 = (undefined4 *)((uint)local_3e0 & 0xffff0000);
  local_c = 0x14;
  FUN_007420d0();
LAB_0074089a:
  FUN_0089120c(local_420);
  *unaff_FS_OFFSET = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_434);
  return;
}

