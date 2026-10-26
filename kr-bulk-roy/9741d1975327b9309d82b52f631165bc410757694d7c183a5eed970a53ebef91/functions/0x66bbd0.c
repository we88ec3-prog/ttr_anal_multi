
void FUN_0066bbd0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint local_e0;
  undefined2 local_dc [4];
  undefined4 uStack_d4;
  int *local_d0;
  uint *local_cc;
  wchar_t *local_c8;
  undefined4 ******ppppppuStack_c4;
  uint uStack_c0;
  uint local_ac [5];
  uint local_98;
  uint local_8c [4];
  undefined4 local_7c;
  uint local_78;
  undefined1 *local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 *local_54;
  uint local_50;
  undefined4 ******local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093cf76;
  local_10 = ExceptionList;
  uStack_c0 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = param_1;
  local_14 = uStack_c0;
  if ((*(int *)(param_1 + 0xf0) != 0) && (iVar5 = *(int *)(param_1 + 0xf4), iVar5 != 0)) {
    ppppppuStack_c4 = (undefined4 ******)0x66bc4a;
    puVar3 = (undefined4 *)FUN_0066bb80();
    local_54 = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      iVar5 = *(int *)(iVar5 + 0xcc);
      if (iVar5 == 0) {
        local_50 = 0xffffffff;
      }
      else {
        iVar5 = *(int *)(iVar5 + 0xdc);
        if (iVar5 == 0) {
          local_50 = 0xffffffff;
        }
        else {
          local_50 = *(uint *)(iVar5 + 0x20);
        }
      }
      iVar5 = (int)(puVar3[0x11] - puVar3[0x10]) / 0x60;
      ppppppuStack_c4 = (undefined4 ******)0x0;
      if (iVar5 != 0) {
        piVar6 = (int *)(puVar3[0x10] + 4);
        iVar4 = iVar5;
        do {
          if (*piVar6 != 0) {
            ppppppuStack_c4 = (undefined4 ******)((int)ppppppuStack_c4 + 1);
          }
          piVar6 = piVar6 + 0x18;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      local_c8 = *(wchar_t **)(*(int *)(local_5c + 0xf4) + 0xcc);
      if (local_c8 != (wchar_t *)0x0) {
        local_cc = (uint *)0x66bccd;
        FUN_00408920();
      }
      local_58 = 0;
      if (iVar5 != 0) {
        local_64 = 0;
        local_60 = iVar5;
        do {
          iVar5 = puVar3[0x10];
          if (*(int *)(iVar5 + 4 + local_64) != 0) {
            uVar1 = *(uint *)(local_64 + iVar5);
            uVar2 = *(undefined4 *)(local_64 + 4 + iVar5);
            ppppppuStack_c4 = *(undefined4 *******)(local_5c + 0xf4);
            local_c8 = (wchar_t *)0x66bd0b;
            piVar6 = (int *)FUN_0063cfc0();
            if (piVar6 != (int *)0x0) {
              ppppppuStack_c4 = (undefined4 ******)0x0;
              local_c8 = L"";
              local_1c = 7;
              local_20 = 0;
              local_30[0] = local_30[0] & 0xffff0000;
              local_cc = (uint *)0x66bd37;
              FUN_00402160();
              local_8 = 0;
              ppppppuStack_c4 = (undefined4 ******)0x9;
              local_c8 = L"<#FFFFFF>";
              local_38 = 7;
              local_3c = 0;
              local_4c[0] = (undefined4 ******)((uint)local_4c[0] & 0xffff0000);
              local_cc = (uint *)0x66bd59;
              FUN_00402160();
              local_8._0_1_ = 1;
              switch(uVar2) {
              case 1:
                ppppppuStack_c4 = (undefined4 ******)0x21f;
                local_c8 = L"\xf08b꿨\xf195跿푍譑\xe8d0㜄ￛ喍劸為썋\xe800㛶ￛ뗩";
                FUN_00585620();
                local_c8 = (wchar_t *)0x66bd81;
                FUN_00585330();
                ppppppuStack_c4 = (undefined4 ******)local_30;
                local_c8 = L"喍劸為썋\xe800㛶ￛ뗩";
                FUN_0041f490();
                ppppppuStack_c4 = local_4c;
                local_c8 = L"뗩";
                FUN_0041f490();
                break;
              case 2:
                ppppppuStack_c4 = (undefined4 ******)0x220;
                local_c8 = L"\xf08b胨\xf195跿푍譑\xe8d0㛕ￛ喍劸蒺썋\xe800㛇ￛ蛩";
                FUN_00585620();
                local_c8 = (wchar_t *)0x66bdb0;
                FUN_00585330();
                ppppppuStack_c4 = (undefined4 ******)local_30;
                local_c8 = L"喍劸蒺썋\xe800㛇ￛ蛩";
                FUN_0041f490();
                ppppppuStack_c4 = local_4c;
                local_c8 = L"蛩";
                FUN_0041f490();
                break;
              case 3:
                ppppppuStack_c4 = (undefined4 ******)0x221;
                local_c8 = (wchar_t *)0x66bdd8;
                FUN_00585620();
                local_c8 = (wchar_t *)0x66bddf;
                FUN_00585330();
                ppppppuStack_c4 = (undefined4 ******)local_30;
                local_c8 = (wchar_t *)0x66bdea;
                FUN_0041f490();
                ppppppuStack_c4 = local_4c;
                local_c8 = (wchar_t *)0x66bdf8;
                FUN_0041f490();
                break;
              case 4:
                ppppppuStack_c4 = (undefined4 ******)0x222;
                local_c8 = (wchar_t *)0x66be04;
                FUN_00585620();
                local_c8 = (wchar_t *)0x66be0b;
                FUN_00585330();
                ppppppuStack_c4 = (undefined4 ******)local_30;
                local_c8 = (wchar_t *)0x66be16;
                FUN_0041f490();
                ppppppuStack_c4 = local_4c;
                local_c8 = (wchar_t *)0x66be24;
                FUN_0041f490();
                break;
              case 5:
                ppppppuStack_c4 = (undefined4 ******)0x223;
                local_c8 = (wchar_t *)0x66be30;
                FUN_00585620();
                local_c8 = (wchar_t *)0x66be37;
                FUN_00585330();
                ppppppuStack_c4 = (undefined4 ******)local_30;
                local_c8 = (wchar_t *)0x66be42;
                FUN_0041f490();
                ppppppuStack_c4 = (undefined4 ******)0x66be47;
                iVar5 = FUN_00404ba0();
                if (*(int *)(iVar5 + 0x68b4) == 0) goto switchD_0066bd69_default;
                break;
              default:
switchD_0066bd69_default:
                if (local_50 == uVar1) {
                  local_50 = 0xffffffff;
                }
                local_68 = (undefined1 *)local_dc;
                local_e0 = 0xffffffff;
                local_c8 = (wchar_t *)0x7;
                local_cc = (uint *)0x0;
                local_dc[0] = 0;
                FUN_004026e0(local_30,0);
                local_8._0_1_ = 4;
                local_e0 = uVar1;
                local_e0 = FUN_00507a30(*local_54);
                local_8._0_1_ = 1;
                FUN_004796c0();
                local_8._0_1_ = 5;
                ppppppuStack_c4 = (undefined4 ******)0x66bf6c;
                FUN_007578f0();
                ppppppuStack_c4 = (undefined4 ******)0x7d;
                local_c8 = (wchar_t *)0x7b;
                local_cc = local_8c;
                uStack_d4 = 0x66bf7d;
                local_d0 = piVar6 + 0x3a;
                FUN_00759ed0();
                local_8 = CONCAT31(local_8._1_3_,1);
                if (7 < local_78) {
                  ppppppuStack_c4 = (undefined4 ******)local_8c[0];
                  local_c8 = L"쒃謄㌃㏒曶閉ｸ\xffff邋\x90";
                  FUN_0089120c();
                }
                local_8c[0] = local_8c[0] & 0xffff0000;
                ppppppuStack_c4 = (undefined4 ******)0x0;
                local_78 = 7;
                local_7c = 0;
                local_c8 = L"ࢻ";
                (**(code **)(*piVar6 + 0x90))();
                goto LAB_0066bfb9;
              }
              ppppppuStack_c4 = local_4c[0];
              if (local_38 < 8) {
                ppppppuStack_c4 = local_4c;
              }
              local_68 = (undefined1 *)&local_e0;
              local_cc = (uint *)0x7;
              local_d0 = (int *)0x0;
              local_e0 = local_e0 & 0xffff0000;
              FUN_004026e0(local_30,0,0xffffffff);
              local_8._0_1_ = 2;
              FUN_00507a30(*local_54,uVar1);
              local_8._0_1_ = 1;
              FUN_0066caa0();
              local_8._0_1_ = 3;
              ppppppuStack_c4 = (undefined4 ******)0x66bebb;
              FUN_007578f0();
              ppppppuStack_c4 = (undefined4 ******)0x7d;
              local_c8 = (wchar_t *)0x7b;
              local_cc = local_ac;
              uStack_d4 = 0x66becc;
              local_d0 = piVar6 + 0x3a;
              FUN_00759ed0();
              local_8 = CONCAT31(local_8._1_3_,1);
              if (7 < local_98) {
                ppppppuStack_c4 = (undefined4 ******)local_ac[0];
                local_c8 = L"쒃謄謓邂";
                FUN_0089120c();
              }
              ppppppuStack_c4 = (undefined4 ******)0x1;
              local_c8 = L"޿";
              (**(code **)(*piVar6 + 0x90))();
LAB_0066bfb9:
              if (7 < local_38) {
                ppppppuStack_c4 = local_4c[0];
                local_c8 = 
                L"쒃㌄쟉ﱅ\xffff\xffff綉觌졵襦롍崹狨謌푕\xe852刜\"쒃㌄觀\xe87d疉曤䖉ￔ걅䖋讠끝삃｠ꑍ䖉ྠ즅￼诿꡵蚋ô"
                ;
                FUN_0089120c();
              }
              local_8 = 0xffffffff;
              local_38 = 7;
              local_3c = 0;
              local_4c[0] = (undefined4 ******)((uint)local_4c[0] & 0xffff0000);
              if (7 < local_1c) {
                ppppppuStack_c4 = (undefined4 ******)local_30[0];
                local_c8 = 
                L"쒃㌄觀\xe87d疉曤䖉ￔ걅䖋讠끝삃｠ꑍ䖉ྠ즅￼诿꡵蚋ô";
                FUN_0089120c();
              }
              local_1c = 7;
              local_20 = 0;
              local_30[0] = local_30[0] & 0xffff0000;
            }
            local_58 = local_58 + 1;
            puVar3 = local_54;
          }
          local_64 = local_64 + 0x60;
          local_60 = local_60 + -1;
        } while (local_60 != 0);
      }
      iVar5 = local_5c;
      if (*(int *)(*(int *)(local_5c + 0xf4) + 0xcc) != 0) {
        ppppppuStack_c4 = (undefined4 ******)local_50;
        local_c8 = L"隋ô";
        FUN_0042c8e0();
      }
      ppppppuStack_c4 = *(undefined4 *******)(iVar5 + 0xf4);
      local_c8 = L"躋ô";
      FUN_00749920();
      ppppppuStack_c4 = (undefined4 ******)0x66c04f;
      (**(code **)(**(int **)(iVar5 + 0xf4) + 200))();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

