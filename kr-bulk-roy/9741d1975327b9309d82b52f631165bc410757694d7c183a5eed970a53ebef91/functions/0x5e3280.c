
/* WARNING: Type propagation algorithm not settling */

void FUN_005e3280(undefined4 param_1)

{
  wchar_t wVar1;
  short sVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  wchar_t *_Str;
  short *psVar5;
  undefined4 *******pppppppuVar6;
  int in_ECX;
  short *psVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int local_498;
  undefined4 local_494;
  uint local_490;
  undefined4 local_48c;
  int local_488;
  uint local_484;
  int local_480;
  wchar_t *local_47c;
  uint *local_478;
  undefined4 local_474;
  uint local_460;
  uint local_458 [4];
  undefined4 local_448;
  uint local_444;
  undefined4 *******local_43c [4];
  undefined4 local_42c;
  uint local_428;
  wchar_t local_420 [260];
  short local_218;
  undefined1 local_216 [510];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00926e7f;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48c = param_1;
  local_488 = in_ECX;
  if ((DAT_00fb1350 & 1) == 0) {
    DAT_00fb1350 = DAT_00fb1350 | 1;
    local_8 = 0;
    FUN_00511ca0(local_18);
    _atexit((_func_4879 *)&LAB_00bccf40);
  }
  local_8 = 0xffffffff;
  local_480 = *(int *)(in_ECX + 0x164);
  FUN_008438c0(&local_480);
  if (((local_47c != DAT_00fb136c) && (iVar8 = *(int *)(local_47c + 8), iVar8 != 0)) &&
     (*(byte *)(in_ECX + 0x178) != 0)) {
    for (puVar9 = *(uint **)(iVar8 + 100); puVar9 != *(uint **)(iVar8 + 0x68); puVar9 = puVar9 + 6)
    {
      if (*puVar9 == (uint)*(byte *)(in_ECX + 0x178)) {
        local_478 = puVar9;
        if (*(int *)(*(int *)(in_ECX + 0x184) + 8) == 0xf) {
          uVar3 = 0xffcccccc;
        }
        else {
          uVar3 = FUN_005e6e70();
        }
        *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = uVar3;
        local_484 = 0;
        uVar10 = (int)(puVar9[3] - puVar9[2]) >> 3;
        local_490 = uVar10;
        if (uVar10 != 0) {
          do {
            iVar8 = DAT_00fc0e34;
            local_494 = *(undefined4 *)(puVar9[2] + local_484 * 8);
            local_480 = puVar9[2] + local_484 * 8;
            FUN_005740f0(&local_494);
            if (local_498 != *(int *)(iVar8 + 0xc)) {
              _Str = (wchar_t *)(local_498 + 0x10);
              if (7 < *(uint *)(local_498 + 0x24)) {
                _Str = *(wchar_t **)_Str;
              }
              if (_Str != (wchar_t *)0x0) {
                local_218 = 0;
                _memset(local_216,0,0x1fe);
                pwVar4 = _wcsstr(_Str,L"%");
                _wcsstr(_Str,L"10x");
                iVar8 = (int)local_420 - (int)_Str;
                do {
                  wVar1 = *_Str;
                  *(wchar_t *)(iVar8 + (int)_Str) = wVar1;
                  _Str = _Str + 1;
                } while (wVar1 != L'\0');
                local_47c = (wchar_t *)0x0;
                _wcstok_s(local_420,L"(",&local_47c);
                if (local_47c != (wchar_t *)0x0) {
                  *local_47c = L'\0';
                }
                psVar7 = &DAT_00c02bac;
                if (*(int *)(local_480 + 4) < 0) {
                  psVar7 = &DAT_00bed1fc;
                }
                local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffff0000);
                local_42c = 0;
                local_428 = 7;
                psVar5 = psVar7;
                do {
                  sVar2 = *psVar5;
                  psVar5 = psVar5 + 1;
                } while (sVar2 != 0);
                FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
                local_8 = 1;
                uVar3 = FUN_0040ef80();
                local_8._0_1_ = 2;
                FUN_004041f0(uVar3,0,0xffffffff);
                local_8._0_1_ = 1;
                if (7 < local_460) {
                  FUN_0089120c(local_474);
                }
                psVar7 = &DAT_00c02ba8;
                if (pwVar4 == (wchar_t *)0x0) {
                  psVar7 = &DAT_00bed1fc;
                }
                psVar5 = psVar7;
                do {
                  sVar2 = *psVar5;
                  psVar5 = psVar5 + 1;
                } while (sVar2 != 0);
                FUN_00404300(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
                pppppppuVar6 = local_43c[0];
                if (local_428 < 8) {
                  pppppppuVar6 = local_43c;
                }
                FUN_0040aeb0(L"%s : %s<br>",local_420,pppppppuVar6);
                local_444 = 7;
                local_448 = 0;
                local_458[0] = local_458[0] & 0xffff0000;
                local_8 = CONCAT31(local_8._1_3_,3);
                if (*(int *)(*(int *)(local_488 + 0x184) + 8) == 0xf) {
                  uVar3 = 0xffcccccc;
                }
                else {
                  switch(local_478[1]) {
                  case 0:
                    uVar3 = 0xffffffff;
                    break;
                  case 1:
                    uVar3 = 0xffffff00;
                    break;
                  case 2:
                    uVar3 = 0xff5aff78;
                    break;
                  case 3:
                    uVar3 = 0xff00bbdd;
                    break;
                  case 4:
                    uVar3 = 0xffe243ff;
                    break;
                  case 5:
                    uVar3 = 0xffb41010;
                    break;
                  default:
                    uVar3 = 0xff6600;
                  }
                }
                FUN_005e6ec0(uVar3);
                FUN_004041f0(local_458,0,0xffffffff);
                psVar7 = &local_218;
                do {
                  sVar2 = *psVar7;
                  psVar7 = psVar7 + 1;
                } while (sVar2 != 0);
                FUN_00404300(&local_218,(int)psVar7 - (int)local_216 >> 1);
                if (7 < local_444) {
                  FUN_0089120c(local_458[0]);
                }
                local_8 = 0xffffffff;
                local_444 = 7;
                local_448 = 0;
                local_458[0] = local_458[0] & 0xffff0000;
                if (7 < local_428) {
                  FUN_0089120c(local_43c[0]);
                }
                local_428 = 7;
                local_42c = 0;
                local_43c[0] = (undefined4 *******)((uint)local_43c[0] & 0xffff0000);
                puVar9 = local_478;
                uVar10 = local_490;
              }
            }
            local_484 = local_484 + 1;
          } while (local_484 < uVar10);
        }
        break;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

