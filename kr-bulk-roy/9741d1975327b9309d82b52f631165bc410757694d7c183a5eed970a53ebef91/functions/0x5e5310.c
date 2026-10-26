
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e5310(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  short *psVar8;
  int in_ECX;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  undefined2 auStack_304 [6];
  undefined4 uStack_2f8;
  uint *puStack_2f4;
  undefined4 uStack_2f0;
  wchar_t *pwStack_2ec;
  undefined2 local_2e8 [4];
  undefined4 uStack_2e0;
  wchar_t *pwStack_2dc;
  undefined *local_2d8;
  undefined ***local_2d4;
  uint local_2bc;
  undefined1 *local_2b8;
  undefined4 local_2b4;
  int local_2b0;
  undefined1 local_2ac [4];
  int *local_2a8;
  int local_2a4;
  int *local_29c;
  uint local_298;
  undefined4 local_294;
  undefined1 *local_290;
  char *local_28c;
  undefined **local_288 [5];
  uint local_274 [4];
  undefined4 local_264;
  uint local_260;
  uint local_244;
  uint auStack_23c [4];
  undefined4 uStack_22c;
  uint uStack_228;
  short asStack_220 [258];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929024;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_2bc;
  ExceptionList = &local_14;
  local_294 = param_1;
  local_2a4 = 0;
  local_2d4 = (undefined ***)0x5e536a;
  local_2b0 = in_ECX;
  local_2a8 = (int *)FUN_00891268();
  if (local_2a8 == (int *)0x0) {
    local_28c = (char *)0x0;
    local_2d4 = (undefined ***)0x5e5a76;
    std::exception::exception((exception *)local_288,&local_28c);
    local_2d4 = local_288;
    local_288[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    local_2d8 = &UNK_005e5a8d;
    __CxxThrowException_8();
  }
  *local_2a8 = (int)local_2a8;
  local_2a8[1] = (int)local_2a8;
  local_2a8[2] = (int)local_2a8;
  *(undefined1 *)(local_2a8 + 5) = 1;
  *(undefined1 *)((int)local_2a8 + 0x15) = 1;
  local_c = 0;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_c._0_1_ = 1;
    local_c._1_3_ = 0;
    FUN_004dd4a0();
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    local_2d4 = (undefined ***)0x5e53d9;
    _atexit((_func_4879 *)&LAB_00bccdb0);
    local_c = (uint)local_c._1_3_ << 8;
  }
  local_2b8 = *(undefined1 **)(in_ECX + 0x1a8);
  local_2b4 = *(undefined4 *)(in_ECX + 0x1ac);
  local_2d4 = (undefined ***)&local_2bc;
  local_2d8 = &DAT_00fab0dc;
  pwStack_2dc = L"䒋ဤԻ냠ú萏¨";
  FUN_004dd400();
  if ((local_2bc != DAT_00fab0e0) && (local_2bc = *(uint *)(local_2bc + 0x18), local_2bc != 0)) {
    piVar11 = (int *)0x0;
    local_29c = (int *)(*(int *)(local_2bc + 0x38) - *(int *)(local_2bc + 0x34) >> 3);
    if (local_29c != (int *)0x0) {
      do {
        iVar9 = *(int *)(local_2bc + 0x34);
        puVar3 = *(undefined1 **)(iVar9 + (int)piVar11 * 8);
        local_2d4 = (undefined ***)0x5e5478;
        local_290 = puVar3;
        FUN_005740f0();
        if (local_298 != *(uint *)(DAT_00fc0e34 + 0xc)) {
          puVar7 = (undefined4 *)(local_298 + 0x10);
          if (7 < *(uint *)(local_298 + 0x24)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 != (undefined4 *)0x0) {
            local_2b4 = *(undefined4 *)(iVar9 + (int)piVar11 * 8 + 4);
            local_2b8 = puVar3;
            FUN_0057ef20();
            local_2d8 = (undefined *)0x5e54bd;
            local_2d4 = (undefined ***)local_2ac;
            FUN_0057e850();
          }
        }
        piVar11 = (int *)((int)piVar11 + 1);
      } while (piVar11 < local_29c);
    }
  }
  iVar9 = *(int *)(local_2b0 + 0x188);
  if (iVar9 == 0) {
    piVar11 = (int *)*local_2a8;
    if (piVar11 != local_2a8) {
      do {
        local_260 = 7;
        local_264 = 0;
        local_274[0] = local_274[0] & 0xffff0000;
        local_c._0_1_ = 10;
        local_2d4 = (undefined ***)local_274;
        local_2d8 = (undefined *)0x5e5951;
        FUN_005e50b0();
        local_2b8 = (undefined1 *)local_2e8;
        pwStack_2ec = (wchar_t *)0xffffffff;
        uStack_2f0 = 0;
        puStack_2f4 = local_274;
        local_2d4 = (undefined ***)0x7;
        local_2d8 = (undefined *)0x0;
        local_2e8[0] = 0;
        uStack_2f8 = 0x5e5976;
        FUN_004026e0();
        pwStack_2ec = L"<#FF503C>-{0}<br>";
        uStack_2f0 = 0x5e5987;
        local_2d8 = (undefined *)FUN_00424c80();
        local_2d4 = (undefined ***)0x0;
        local_c = CONCAT31(local_c._1_3_,0xb);
        pwStack_2dc = L"벃蠤";
        FUN_004041f0();
        if (7 < local_244) {
          local_2d4 = (undefined ***)0x5e59b2;
          FUN_0089120c();
        }
        if (7 < local_260) {
          local_2d4 = (undefined ***)0x5e59c6;
          FUN_0089120c();
        }
        if (*(char *)((int)piVar11 + 0x15) == '\0') {
          piVar5 = (int *)piVar11[2];
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x15);
            piVar11 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar5 + 0x15);
              piVar11 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar1 = *(char *)(piVar11[1] + 0x15);
            piVar6 = (int *)piVar11[1];
            piVar5 = piVar11;
            while ((piVar11 = piVar6, cVar1 == '\0' && (piVar5 == (int *)piVar11[2]))) {
              cVar1 = *(char *)(piVar11[1] + 0x15);
              piVar6 = (int *)piVar11[1];
              piVar5 = piVar11;
            }
          }
        }
      } while (piVar11 != local_2a8);
    }
  }
  else {
    local_2bc = 0;
    local_298 = *(int *)(iVar9 + 0x38) - *(int *)(iVar9 + 0x34) >> 3;
    if (local_298 != 0) {
      do {
        iVar4 = *(int *)(*(int *)(local_2b0 + 0x188) + 0x34);
        iVar9 = local_2bc * 8;
        local_260 = 7;
        local_264 = 0;
        local_274[0] = local_274[0] & 0xffff0000;
        local_c._0_1_ = 2;
        local_2d4 = (undefined ***)local_274;
        local_2d8 = (undefined *)0x5e553b;
        FUN_005e50b0();
        if (local_2a4 != 0) {
          local_2d4 = (undefined ***)0x5e5553;
          FUN_008438c0();
          if (local_29c != local_2a8) {
            iVar9 = *(int *)(iVar4 + iVar9 + 4) - local_29c[4];
            if (iVar9 < 1) {
              if (iVar9 < 0) {
                local_2d8 = (undefined *)FUN_004068f0();
                local_2d4 = (undefined ***)0x0;
                local_c._0_1_ = 4;
                pwStack_2dc = L"蓆쀤\x02Ȁ벃蠤";
                FUN_004041f0();
                goto joined_r0x005e55e4;
              }
            }
            else {
              local_2d8 = (undefined *)FUN_004068f0();
              local_2d4 = (undefined ***)0x0;
              local_c._0_1_ = 3;
              pwStack_2dc = L"蓆쀤\x02Ȁ벃蠤";
              FUN_004041f0();
joined_r0x005e55e4:
              local_c._0_1_ = 2;
              if (7 < local_244) {
                local_c._0_1_ = 2;
                local_2d4 = (undefined ***)0x5e55f0;
                FUN_0089120c();
              }
            }
            local_2d4 = (undefined ***)&local_28c;
            local_2d8 = local_2ac;
            pwStack_2dc = L"޿";
            FUN_007b6890();
          }
        }
        iVar9 = *(int *)(local_2b0 + 0x180);
        if (iVar9 == 0) {
          uVar12 = 0;
        }
        else {
          uVar12 = (uint)*(byte *)(iVar9 + 0x4c);
        }
        iVar4 = *(int *)(local_2b0 + 0x188);
        if (iVar4 == 0) {
          iVar10 = 0;
        }
        else {
          iVar10 = *(int *)(iVar4 + 0x10);
        }
        if (iVar10 < (int)uVar12) {
          if (iVar9 == 0) {
LAB_005e5646:
            uVar12 = 0;
          }
          else {
            uVar12 = (uint)*(byte *)(iVar9 + 0x4c);
          }
        }
        else {
          if (iVar4 == 0) goto LAB_005e5646;
          uVar12 = *(uint *)(iVar4 + 0x10);
        }
        uStack_228 = 7;
        uStack_22c = 0;
        auStack_23c[0] = auStack_23c[0] & 0xffff0000;
        local_c._0_1_ = 5;
        if (*(int *)(*(int *)(local_2b0 + 0x184) + 8) == 0xf) {
          uVar12 = 0xffcccccc;
        }
        else {
          switch(uVar12) {
          case 0:
            uVar12 = 0xffffffff;
            break;
          case 1:
            uVar12 = 0xffffff00;
            break;
          case 2:
            uVar12 = 0xff5aff78;
            break;
          case 3:
            uVar12 = 0xff00bbdd;
            break;
          case 4:
            uVar12 = 0xffe243ff;
            break;
          case 5:
            uVar12 = 0xffb41010;
            break;
          default:
            uVar12 = 0xff6600;
          }
        }
        local_2d4 = (undefined ***)(uVar12 >> 8 & 0xff);
        local_2d8 = (undefined *)(uVar12 >> 0x10 & 0xff);
        pwStack_2dc = L"<#%02x%02x%02x>";
        uStack_2e0 = 0x5e56e2;
        FUN_0040aeb0();
        psVar8 = asStack_220;
        do {
          sVar2 = *psVar8;
          psVar8 = psVar8 + 1;
        } while (sVar2 != 0);
        local_2d4 = (undefined ***)asStack_220;
        local_2d8 = (undefined *)0x5e5714;
        FUN_00404300();
        local_290 = (undefined1 *)local_2e8;
        pwStack_2ec = (wchar_t *)0xffffffff;
        uStack_2f0 = 0;
        puStack_2f4 = local_274;
        local_2d4 = (undefined ***)0x7;
        local_2d8 = (undefined *)0x0;
        local_2e8[0] = 0;
        uStack_2f8 = 0x5e5735;
        FUN_004026e0();
        local_2b8 = (undefined1 *)auStack_304;
        local_c._0_1_ = 6;
        uStack_2f0 = 7;
        puStack_2f4 = (uint *)0x0;
        auStack_304[0] = 0;
        FUN_004026e0(auStack_23c,0,0xffffffff);
        local_c._0_1_ = 5;
        local_2d8 = (undefined *)FUN_004213a0(L"{0}+{1}<br>");
        local_2d4 = (undefined ***)0x0;
        local_c = CONCAT31(local_c._1_3_,7);
        pwStack_2dc = L"벃蠤";
        FUN_004041f0();
        if (7 < local_244) {
          local_2d4 = (undefined ***)0x5e57a1;
          FUN_0089120c();
        }
        if (7 < uStack_228) {
          local_2d4 = (undefined ***)0x5e57bf;
          FUN_0089120c();
        }
        uStack_228 = 7;
        uStack_22c = 0;
        auStack_23c[0] = auStack_23c[0] & 0xffff0000;
        if (7 < local_260) {
          local_2d4 = (undefined ***)0x5e57ea;
          FUN_0089120c();
        }
        local_2bc = local_2bc + 1;
      } while (local_2bc < local_298);
    }
    piVar11 = (int *)*local_2a8;
    if (piVar11 != local_2a8) {
      do {
        local_260 = 7;
        local_264 = 0;
        local_274[0] = local_274[0] & 0xffff0000;
        local_c._0_1_ = 8;
        local_2d4 = (undefined ***)local_274;
        local_2d8 = (undefined *)0x5e5840;
        FUN_005e50b0();
        local_2b8 = (undefined1 *)local_2e8;
        pwStack_2ec = (wchar_t *)0xffffffff;
        uStack_2f0 = 0;
        puStack_2f4 = local_274;
        local_2d4 = (undefined ***)0x7;
        local_2d8 = (undefined *)0x0;
        local_2e8[0] = 0;
        uStack_2f8 = 0x5e5865;
        FUN_004026e0();
        pwStack_2ec = L"<#FF503C>-{0}<br>";
        uStack_2f0 = 0x5e5876;
        local_2d8 = (undefined *)FUN_00424c80();
        local_2d4 = (undefined ***)0x0;
        local_c = CONCAT31(local_c._1_3_,9);
        pwStack_2dc = L"벃蠤";
        FUN_004041f0();
        if (7 < local_244) {
          local_2d4 = (undefined ***)0x5e58a1;
          FUN_0089120c();
        }
        if (7 < local_260) {
          local_2d4 = (undefined ***)0x5e58b5;
          FUN_0089120c();
        }
        if (*(char *)((int)piVar11 + 0x15) == '\0') {
          piVar5 = (int *)piVar11[2];
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x15);
            piVar11 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar5 + 0x15);
              piVar11 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar1 = *(char *)(piVar11[1] + 0x15);
            piVar6 = (int *)piVar11[1];
            piVar5 = piVar11;
            while ((piVar11 = piVar6, cVar1 == '\0' && (piVar5 == (int *)piVar11[2]))) {
              cVar1 = *(char *)(piVar11[1] + 0x15);
              piVar6 = (int *)piVar11[1];
              piVar5 = piVar11;
            }
          }
        }
      } while (piVar11 != local_2a8);
    }
  }
  local_c = 0xc;
  local_2d4 = (undefined ***)*local_2a8;
  local_2d8 = (undefined *)0x5e5a31;
  FUN_005540c0();
  local_2d4 = (undefined ***)0x5e5a3b;
  FUN_0089120c();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_2bc);
  return;
}

