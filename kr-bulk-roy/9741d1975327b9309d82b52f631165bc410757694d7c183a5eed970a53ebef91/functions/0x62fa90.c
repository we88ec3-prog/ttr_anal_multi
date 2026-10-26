
void FUN_0062fa90(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  undefined4 **ppuVar9;
  undefined4 *puVar10;
  int in_ECX;
  int iVar11;
  undefined4 *puVar12;
  undefined2 auStack_c0 [6];
  undefined4 uStack_b4;
  undefined4 *puStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_94 [4];
  undefined4 *puStack_90;
  int local_8c;
  char local_85;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  int iStack_60;
  undefined4 *puStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int local_48;
  int iStack_44;
  undefined4 *puStack_40;
  int iStack_3c;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946905;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_94;
  ExceptionList = &local_14;
  local_84 = in_ECX;
  if (*(int *)(*(int *)(in_ECX + 0x110) + 0xcc) != 0) {
    uStack_ac = 0x62faeb;
    FUN_006438f0();
  }
  uStack_ac = 0x62faf1;
  FUN_0062f780();
  iVar7 = *(int *)(in_ECX + 0x118) - *(int *)(in_ECX + 0x114) >> 2;
  local_78 = 0;
  local_48 = iVar7;
  if (0 < iVar7) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x114) + local_78 * 4);
      local_80 = iVar2;
      if (iVar2 != 0) {
        local_85 = '\0';
        local_74 = 0;
        local_70 = 0;
        local_6c = 0;
        local_c._1_3_ = 0;
        if ((DAT_00fab29c & 1) == 0) {
          DAT_00fab29c = DAT_00fab29c | 1;
          local_c._0_1_ = 1;
          local_c._1_3_ = 0;
          FUN_004ffe60();
          uStack_ac = 0x62fb66;
          _atexit((_func_4879 *)&LAB_00bccf00);
        }
        local_c._0_1_ = 0;
        uStack_ac = *(undefined4 *)(iVar2 + 0x2c);
        puStack_b0 = &DAT_00fab2a0;
        uStack_b4 = 0x62fb84;
        FUN_00500e00();
        iVar7 = local_70 - local_74 >> 2;
        iVar11 = 0;
        if (0 < iVar7) {
          do {
            if (iVar2 == *(int *)(local_74 + iVar11 * 4)) {
              local_85 = '\x01';
              break;
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < iVar7);
        }
        if (*(int *)(iVar2 + 4) == 1) {
          piVar3 = *(int **)(*(int *)(local_84 + 0x110) + 0xcc);
          if (piVar3 == (int *)0x0) {
LAB_0062fcc6:
            local_8c = 0;
          }
          else {
            iVar7 = piVar3[0x39];
            if ((int *)piVar3[0x29] == (int *)0x0) goto LAB_0062fcc6;
            iVar2 = *(int *)piVar3[0x29];
            if (piVar3[0x2e] == piVar3[0x2f]) {
              iVar11 = (**(code **)(iVar2 + 0x28))();
              local_7c = iVar11;
            }
            else {
              iVar11 = *(int *)(piVar3[0x2f] + -4);
              uStack_ac = 0x62fc0e;
              local_7c = iVar11;
              (**(code **)(iVar2 + 0x2c))();
              if (piVar3[0x2e] != piVar3[0x2f]) {
                piVar3[0x2f] = piVar3[0x2f] + -4;
              }
            }
            *(int *)(iVar11 + 0x20) = iVar7;
            uStack_ac = 0x62fc36;
            local_8c = iVar11;
            (**(code **)(*piVar3 + 0x70))();
            piVar4 = (int *)piVar3[0x2b];
            if (&local_8c < piVar4) {
              piVar5 = (int *)piVar3[0x2a];
              if (&local_8c < piVar5) goto LAB_0062fc85;
              if (piVar4 == (int *)piVar3[0x2c]) {
                FUN_004deab0();
              }
              if ((undefined4 *)piVar3[0x2b] != (undefined4 *)0x0) {
                *(undefined4 *)piVar3[0x2b] =
                     *(undefined4 *)(piVar3[0x2a] + ((int)&local_8c - (int)piVar5 >> 2) * 4);
              }
            }
            else {
LAB_0062fc85:
              if (piVar4 == (int *)piVar3[0x2c]) {
                FUN_004deab0();
              }
              if ((int *)piVar3[0x2b] != (int *)0x0) {
                *(int *)piVar3[0x2b] = iVar11;
              }
            }
            piVar3[0x2b] = piVar3[0x2b] + 4;
            uVar8 = iVar7 + 1;
            if (uVar8 <= (uint)piVar3[0x39]) {
              uVar8 = piVar3[0x39];
            }
            piVar3[0x39] = uVar8;
            local_8c = local_7c;
          }
          FUN_00630a50();
          if ((DAT_00f94394 & 1) == 0) {
            DAT_00f94394 = DAT_00f94394 | 1;
            local_c._0_1_ = 2;
            FUN_005c3de0();
            uStack_ac = 0x62fcf8;
            _atexit((_func_4879 *)&LAB_00bccc30);
            local_c._0_1_ = 0;
          }
          cVar1 = *(char *)((int)DAT_00f94574[1] + 0x15);
          puVar10 = (undefined4 *)DAT_00f94574[1];
          puStack_90 = DAT_00f94574;
          while (puVar12 = puVar10, cVar1 == '\0') {
            if ((uint)puVar12[3] < *(uint *)(local_80 + 0x24)) {
              puVar10 = (undefined4 *)puVar12[2];
              puVar12 = puStack_90;
            }
            else {
              puVar10 = (undefined4 *)*puVar12;
            }
            cVar1 = *(char *)((int)puVar10 + 0x15);
            puStack_90 = puVar12;
          }
          if ((puStack_90 == DAT_00f94574) || (*(uint *)(local_80 + 0x24) < (uint)puStack_90[3])) {
            puStack_5c = DAT_00f94574;
            ppuVar9 = &puStack_5c;
          }
          else {
            ppuVar9 = &puStack_90;
          }
          if (*ppuVar9 == DAT_00f94574) {
            iVar7 = 0;
          }
          else {
            iVar7 = (*ppuVar9)[4];
          }
          iVar2 = *(int *)(local_8c + 0x24c);
          if ((((*(char *)(iVar2 + 0xa4) != '\0') && (*(int **)(iVar2 + 0x94) != (int *)0x0)) &&
              (iVar11 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar11 == 0xbf6b)) &&
             (iVar2 = *(int *)(iVar2 + 0x94), *(int *)(iVar2 + 0x10) != iVar7)) {
            if (((iVar7 != 0) && (piVar3 = *(int **)(iVar7 + 8), piVar3 != (int *)0x0)) &&
               (piVar3[0x27] = piVar3[0x27] + 1, piVar3[0x27] == 1)) {
              (**(code **)(*piVar3 + 0x24))();
            }
            if ((*(int *)(iVar2 + 0x10) != 0) &&
               (piVar3 = *(int **)(*(int *)(iVar2 + 0x10) + 8), piVar3 != (int *)0x0)) {
              piVar4 = piVar3 + 0x27;
              *piVar4 = *piVar4 + -1;
              if (*piVar4 == 0) {
                (**(code **)(*piVar3 + 0x28))();
              }
            }
            *(int *)(iVar2 + 0x10) = iVar7;
          }
          if ((DAT_00fe17b8 & 1) == 0) {
            DAT_00fe17b8 = DAT_00fe17b8 | 1;
            local_c._0_1_ = 3;
            FUN_0050caf0();
            uStack_ac = 0x62fe04;
            _atexit((_func_4879 *)&LAB_00bce7e0);
            local_c._0_1_ = 0;
          }
          cVar1 = *(char *)((int)DAT_00fe17e4[1] + 0x31);
          puVar10 = (undefined4 *)DAT_00fe17e4[1];
          puStack_90 = DAT_00fe17e4;
          while (puVar12 = puVar10, cVar1 == '\0') {
            if ((int)puVar12[3] < *(int *)(local_80 + 0x24)) {
              puVar10 = (undefined4 *)puVar12[2];
              puVar12 = puStack_90;
            }
            else {
              puVar10 = (undefined4 *)*puVar12;
            }
            cVar1 = *(char *)((int)puVar10 + 0x31);
            puStack_90 = puVar12;
          }
          if ((puStack_90 == DAT_00fe17e4) || (*(int *)(local_80 + 0x24) < (int)puStack_90[3])) {
            puStack_40 = DAT_00fe17e4;
            ppuVar9 = &puStack_40;
          }
          else {
            ppuVar9 = &puStack_90;
          }
          puVar10 = *ppuVar9;
          if ((puVar10 != DAT_00fe17e4) && (puVar10 != (undefined4 *)0xfffffff0)) {
            if ((DAT_00f94394 & 1) == 0) {
              DAT_00f94394 = DAT_00f94394 | 1;
              local_c._0_1_ = 4;
              FUN_005c3de0();
              uStack_ac = 0x62fe9b;
              _atexit((_func_4879 *)&LAB_00bccc30);
              local_c._0_1_ = 0;
            }
            puStack_90 = (undefined4 *)puVar10[5];
            uStack_ac = 0x62fec6;
            FUN_0082ef00();
            if (((*(char *)(*(int *)(local_8c + 0x250) + 0xa4) != '\0') &&
                (piVar3 = *(int **)(*(int *)(local_8c + 0x250) + 0x94), piVar3 != (int *)0x0)) &&
               (iVar7 = (**(code **)(*piVar3 + 4))(), iVar7 == 0xbf6b)) {
              FUN_0077b200();
            }
          }
          iVar2 = local_80;
          iVar7 = local_8c;
          if (*(int *)(local_80 + 4) == 2) {
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 5;
              uStack_ac = 0x62ff3d;
              FUN_00584c40();
              uStack_ac = 0x62ff47;
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c._0_1_ = 0;
            }
            puStack_90 = (undefined4 *)0x28c;
            uStack_ac = 0x62ff6d;
            FUN_005740f0();
            iVar7 = local_8c;
            if (iStack_3c == DAT_00fe5ac8) {
              pcVar6 = (code *)swi(3);
              (*pcVar6)();
              return;
            }
            FUN_00757710();
            *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xff0099ff;
          }
          else {
            switch(*(undefined4 *)(local_80 + 8)) {
            case 1:
              if (*(int *)(local_80 + 4) == 1) {
                puStack_90 = (undefined4 *)0x28c;
                iVar11 = FUN_00585620();
                uStack_ac = 0x62ffee;
                FUN_005740f0();
                iVar7 = local_8c;
                if (iStack_54 == *(int *)(iVar11 + 4)) {
                  pcVar6 = (code *)swi(3);
                  (*pcVar6)();
                  return;
                }
                FUN_00757710();
                *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xff0099ff;
              }
              else {
                puStack_90 = (undefined4 *)0x288;
                iVar11 = FUN_00585620();
                uStack_ac = 0x630055;
                FUN_005740f0();
                iVar7 = local_8c;
                if (iStack_44 == *(int *)(iVar11 + 4)) {
                  pcVar6 = (code *)swi(3);
                  (*pcVar6)();
                  return;
                }
                FUN_00757710();
                *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xff0099ff;
              }
              break;
            case 2:
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 6;
                uStack_ac = 0x6300bf;
                FUN_00584c40();
                uStack_ac = 0x6300c9;
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c._0_1_ = 0;
              }
              puStack_90 = (undefined4 *)0x289;
              uStack_ac = 0x6300ef;
              FUN_005740f0();
              iVar7 = local_8c;
              if (iStack_4c == DAT_00fe5ac8) {
                pcVar6 = (code *)swi(3);
                (*pcVar6)();
                return;
              }
              FUN_00757710();
              *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xffff9900;
              break;
            case 3:
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 7;
                uStack_ac = 0x63015a;
                FUN_00584c40();
                uStack_ac = 0x630164;
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c._0_1_ = 0;
              }
              puStack_90 = (undefined4 *)0x28a;
              uStack_ac = 0x63018a;
              FUN_005740f0();
              iVar7 = local_8c;
              if (iStack_60 == DAT_00fe5ac8) {
                pcVar6 = (code *)swi(3);
                (*pcVar6)();
                return;
              }
              FUN_00757710();
              *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xffcccccc;
              break;
            case 4:
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 8;
                uStack_ac = 0x6301f5;
                FUN_00584c40();
                uStack_ac = 0x6301ff;
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c._0_1_ = 0;
              }
              puStack_90 = (undefined4 *)0x28b;
              uStack_ac = 0x630225;
              FUN_005740f0();
              iVar7 = local_8c;
              if (iStack_58 == DAT_00fe5ac8) {
                pcVar6 = (code *)swi(3);
                (*pcVar6)();
                return;
              }
              FUN_00757710();
              *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xffcc3333;
              break;
            default:
              FUN_00757710();
            }
          }
          if (local_85 == '\0') {
            uStack_ac = 0x6303a4;
            FUN_00757800();
            uVar8 = DAT_00fab100 & 1;
            *(undefined4 *)(iVar7 + 0x154) = 0xffffffff;
            if (uVar8 == 0) {
              local_c = CONCAT31(local_c._1_3_,0x10);
              goto LAB_006303c6;
            }
          }
          else {
            puStack_90 = (undefined4 *)auStack_c0;
            uStack_ac = 7;
            puStack_b0 = (undefined4 *)0x0;
            auStack_c0[0] = 0;
            FUN_004026e0(iVar2 + 0x4c,0,0xffffffff);
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 10;
              FUN_00584c40(&DAT_00fe5ac4);
              _atexit((_func_4879 *)&LAB_00bcf390);
            }
            local_c._0_1_ = 9;
            puStack_90 = (undefined4 *)0x287;
            FUN_005740f0(&puStack_90);
            if (iStack_50 == DAT_00fe5ac8) {
              pcVar6 = (code *)swi(3);
              (*pcVar6)();
              return;
            }
            puVar10 = (undefined4 *)(iStack_50 + 0x10);
            if (7 < *(uint *)(iStack_50 + 0x24)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            local_c._0_1_ = 0;
            FUN_00424c80(puVar10);
            local_c = CONCAT31(local_c._1_3_,0xb);
            uStack_ac = 0x63035d;
            FUN_00757800();
            if (7 < uStack_24) {
              uStack_ac = 0x630371;
              FUN_0089120c();
            }
            uVar8 = DAT_00fab100 & 1;
            *(undefined4 *)(iVar7 + 0x154) = 0xffffff57;
            if (uVar8 == 0) {
              local_c = CONCAT31(local_c._1_3_,0xc);
LAB_006303c6:
              DAT_00fab100 = DAT_00fab100 | 1;
              FUN_0049d6a0();
              uStack_ac = 0x6303d5;
              _atexit((_func_4879 *)&LAB_00bcce20);
            }
          }
        }
        local_c = 0xffffffff;
        if (local_74 != 0) {
          uStack_ac = 0x6303f3;
          FUN_0089120c();
        }
        local_74 = 0;
        local_70 = 0;
        local_6c = 0;
        iVar7 = local_48;
        in_ECX = local_84;
      }
      local_78 = local_78 + 1;
    } while (local_78 < iVar7);
  }
  piVar3 = *(int **)(local_84 + 0x110);
  puVar10 = (undefined4 *)piVar3[0x19];
  for (puVar12 = (undefined4 *)*puVar10; puVar12 != puVar10; puVar12 = (undefined4 *)*puVar12) {
    if ((*(int *)(puVar12[2] + 0x60) != 0) &&
       (piVar4 = *(int **)(puVar12[2] + 0x1c), piVar4[2] != 6)) {
      uStack_ac = 0x63044a;
      (**(code **)(*piVar4 + 0x30))();
    }
  }
  (**(code **)(*piVar3 + 0x128))();
  (**(code **)(**(int **)(local_84 + 0x110) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_94);
  return;
}

