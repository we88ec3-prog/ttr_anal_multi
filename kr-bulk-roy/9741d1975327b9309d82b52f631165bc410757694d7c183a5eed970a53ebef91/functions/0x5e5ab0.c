
void FUN_005e5ab0(void)

{
  wchar_t wVar1;
  short sVar2;
  int iVar3;
  wchar_t *pwVar4;
  wchar_t *_Str;
  undefined4 uVar5;
  short *psVar6;
  undefined4 ****ppppuVar7;
  int in_ECX;
  short *psVar8;
  undefined4 in_EDX;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 local_490;
  uint local_48c;
  int local_488;
  int local_480;
  uint local_47c;
  int local_478;
  wchar_t *local_474;
  undefined4 local_470;
  uint local_45c;
  uint local_454 [4];
  undefined4 local_444;
  uint local_440;
  undefined4 ***local_438 [4];
  undefined4 local_428;
  uint local_424;
  wchar_t local_41c [260];
  short local_214;
  undefined1 local_212 [510];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928f61;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar9 = *(int *)(in_ECX + 0x188);
  if (iVar9 == 0) {
    if (*(int *)(in_ECX + 0x174) != 0) {
      FUN_005e3280(in_EDX);
    }
  }
  else {
    uVar11 = *(int *)(iVar9 + 0x38) - *(int *)(iVar9 + 0x34) >> 3;
    local_47c = 0;
    local_48c = uVar11;
    local_480 = in_ECX;
    if (uVar11 != 0) {
      do {
        uVar12 = local_47c;
        iVar9 = DAT_00fc0e34;
        local_478 = *(int *)(*(int *)(local_480 + 0x188) + 0x34);
        local_490 = *(undefined4 *)(local_478 + local_47c * 8);
        local_478 = local_478 + local_47c * 8;
        FUN_005740f0(&local_490);
        if (local_488 != *(int *)(iVar9 + 0xc)) {
          _Str = (wchar_t *)(local_488 + 0x10);
          if (7 < *(uint *)(local_488 + 0x24)) {
            _Str = *(wchar_t **)_Str;
          }
          if (_Str != (wchar_t *)0x0) {
            local_214 = 0;
            _memset(local_212,0,0x1fe);
            pwVar4 = _wcsstr(_Str,L"%");
            _wcsstr(_Str,L"10x");
            iVar9 = (int)local_41c - (int)_Str;
            do {
              wVar1 = *_Str;
              *(wchar_t *)((int)_Str + iVar9) = wVar1;
              _Str = _Str + 1;
            } while (wVar1 != L'\0');
            local_474 = (wchar_t *)0x0;
            _wcstok_s(local_41c,L"(",&local_474);
            if (local_474 != (wchar_t *)0x0) {
              *local_474 = L'\0';
            }
            psVar8 = &DAT_00c02bac;
            if (*(int *)(local_478 + 4) < 0) {
              psVar8 = &DAT_00bed1fc;
            }
            local_428 = 0;
            local_424 = 7;
            local_438[0] = (undefined4 ***)((uint)local_438[0] & 0xffff0000);
            psVar6 = psVar8;
            do {
              sVar2 = *psVar6;
              psVar6 = psVar6 + 1;
            } while (sVar2 != 0);
            FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
            local_8 = 0;
            uVar5 = FUN_0040ef80();
            local_8._0_1_ = 1;
            FUN_004041f0(uVar5,0,0xffffffff);
            local_8._0_1_ = 0;
            if (7 < local_45c) {
              FUN_0089120c(local_470);
            }
            psVar8 = &DAT_00c02ba8;
            if (pwVar4 == (wchar_t *)0x0) {
              psVar8 = &DAT_00bed1fc;
            }
            psVar6 = psVar8;
            do {
              sVar2 = *psVar6;
              psVar6 = psVar6 + 1;
            } while (sVar2 != 0);
            FUN_00404300(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
            ppppuVar7 = (undefined4 ****)local_438[0];
            if (local_424 < 8) {
              ppppuVar7 = local_438;
            }
            FUN_0040aeb0(L"%s : %s<br>",local_41c,ppppuVar7);
            iVar9 = *(int *)(local_480 + 0x180);
            if (iVar9 == 0) {
              uVar11 = 0;
            }
            else {
              uVar11 = (uint)*(byte *)(iVar9 + 0x4c);
            }
            iVar3 = *(int *)(local_480 + 0x188);
            if (iVar3 == 0) {
              iVar10 = 0;
            }
            else {
              iVar10 = *(int *)(iVar3 + 0x10);
            }
            if (iVar10 < (int)uVar11) {
              if (iVar9 == 0) {
LAB_005e5d57:
                uVar11 = 0;
              }
              else {
                uVar11 = (uint)*(byte *)(iVar9 + 0x4c);
              }
            }
            else {
              if (iVar3 == 0) goto LAB_005e5d57;
              uVar11 = *(uint *)(iVar3 + 0x10);
            }
            local_440 = 7;
            local_444 = 0;
            local_454[0] = local_454[0] & 0xffff0000;
            local_8 = CONCAT31(local_8._1_3_,2);
            if (*(int *)(*(int *)(local_480 + 0x184) + 8) == 0xf) {
              uVar5 = 0xffcccccc;
            }
            else {
              switch(uVar11) {
              case 0:
                uVar5 = 0xffffffff;
                break;
              case 1:
                uVar5 = 0xffffff00;
                break;
              case 2:
                uVar5 = 0xff5aff78;
                break;
              case 3:
                uVar5 = 0xff00bbdd;
                break;
              case 4:
                uVar5 = 0xffe243ff;
                break;
              case 5:
                uVar5 = 0xffb41010;
                break;
              default:
                uVar5 = 0xff6600;
              }
            }
            FUN_005e6ec0(uVar5);
            FUN_004041f0(local_454,0,0xffffffff);
            psVar8 = &local_214;
            do {
              sVar2 = *psVar8;
              psVar8 = psVar8 + 1;
            } while (sVar2 != 0);
            FUN_00404300(&local_214,(int)psVar8 - (int)local_212 >> 1);
            if (7 < local_440) {
              FUN_0089120c(local_454[0]);
            }
            local_8 = 0xffffffff;
            local_440 = 7;
            local_444 = 0;
            local_454[0] = local_454[0] & 0xffff0000;
            if (7 < local_424) {
              FUN_0089120c(local_438[0]);
            }
            local_428 = 0;
            local_424 = 7;
            local_438[0] = (undefined4 ***)((uint)local_438[0] & 0xffff0000);
            uVar11 = local_48c;
            uVar12 = local_47c;
          }
        }
        local_47c = uVar12 + 1;
      } while (local_47c < uVar11);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

