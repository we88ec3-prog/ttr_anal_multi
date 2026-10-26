
void FUN_006689f0(ushort *param_1)

{
  char cVar1;
  ushort uVar2;
  wchar_t wVar3;
  code *pcVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  ushort **ppuVar9;
  int *piVar10;
  ushort *puVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  int iVar14;
  ushort *puVar15;
  int *piVar16;
  bool bVar17;
  ushort auStack_f4 [8];
  undefined4 uStack_e4;
  undefined2 *puStack_e0;
  ushort auStack_d8 [8];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined1 auStack_a4 [4];
  ushort *puStack_a0;
  ushort *puStack_9c;
  ushort *local_98;
  undefined1 *puStack_94;
  undefined2 *local_90;
  undefined2 *local_8c;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_64;
  int local_54;
  uint local_50;
  undefined4 local_48;
  undefined4 local_38;
  uint local_34;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093d253;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_a4;
  ExceptionList = &local_14;
  local_98 = param_1;
  if (*(char *)(*(int *)(param_1 + 0x7e) + 0x141) != '\0') {
    FUN_006edb10();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = (wchar_t *)((uint)local_64._2_2_ << 0x10);
  uStack_c4 = 0x668a7e;
  FUN_004026e0();
  iVar14 = 0;
  local_6c = 7;
  local_70 = 0;
  local_80 = (ushort *)((uint)local_80._2_2_ << 0x10);
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  if (0 < (int)(*(int *)(*(int *)(param_1 + 0x82) + 0x114) -
                *(int *)(*(int *)(param_1 + 0x82) + 0x110) & 0xfffffffcU)) {
    do {
      uStack_c4 = 0x668aea;
      FUN_004041f0();
      iVar14 = iVar14 + 1;
    } while (iVar14 < *(int *)(*(int *)(param_1 + 0x82) + 0x114) -
                      *(int *)(*(int *)(param_1 + 0x82) + 0x110) >> 2);
  }
  local_90 = (undefined2 *)0x0;
  local_8c = (undefined2 *)0x0;
  local_88 = 0;
  local_c._0_1_ = 2;
  local_34 = 7;
  local_38 = 0;
  local_48 = (uint)local_48._2_2_ << 0x10;
  FUN_00402160();
  local_c._0_1_ = 3;
  FUN_0049c120();
  local_c._0_1_ = 2;
  if (7 < local_34) {
    FUN_0089120c();
  }
  for (iVar14 = ((int)local_8c - (int)local_90) / 0x1c; iVar14 != 0; iVar14 = iVar14 + -1) {
    uStack_c4 = 0x668bb6;
    iVar7 = FUN_00466df0();
    while (iVar7 != -1) {
      FUN_00402400();
      uStack_c4 = 0x668be9;
      iVar7 = FUN_00466df0();
    }
  }
  iVar14 = *(int *)(local_98 + 0x7e);
  if (*(char *)(iVar14 + 0x141) != '\0') {
    FUN_006edb10();
  }
  puVar15 = (ushort *)(iVar14 + 0x108);
  if (7 < *(uint *)(iVar14 + 0x11c)) {
    puVar15 = *(ushort **)puVar15;
  }
  if ((DAT_00fb75c0 & 1) == 0) {
    DAT_00fb75c0 = DAT_00fb75c0 | 1;
    local_c._0_1_ = 4;
    FUN_0081e5f0();
    _atexit((_func_4879 *)&LAB_00bcd250);
    local_c._0_1_ = 2;
  }
  if (puVar15 != (ushort *)0x0) {
    uVar2 = *puVar15;
    while (uVar2 != 0) {
      uVar8 = (uint)*puVar15;
      if (*puVar15 < 0x80) {
        if (((9 < uVar8 - 0x30) && (0x19 < uVar8 - 0x41)) && (0x19 < uVar8 - 0x61))
        goto LAB_00668cb4;
      }
      else {
        iVar14 = (**(code **)(*DAT_00fb7608 + 8))();
        if (iVar14 == 0) goto LAB_00668cb4;
      }
      puVar15 = puVar15 + 1;
      uVar2 = *puVar15;
    }
    uStack_c4 = 0x668ca9;
    iVar14 = FUN_0081eb80();
    if (iVar14 == 0) {
      iVar14 = *(int *)(local_98 + 0x80);
      if (*(char *)(iVar14 + 0x141) != '\0') {
        FUN_006edb10();
      }
      puVar15 = (ushort *)(iVar14 + 0x108);
      if (7 < *(uint *)(iVar14 + 0x11c)) {
        puVar15 = *(ushort **)puVar15;
      }
      local_98 = puVar15;
      if ((DAT_00fb75c0 & 1) == 0) {
        DAT_00fb75c0 = DAT_00fb75c0 | 1;
        local_c._0_1_ = 8;
        FUN_0081e5f0();
        _atexit((_func_4879 *)&LAB_00bcd250);
        local_c._0_1_ = 2;
      }
      if (puVar15 != (ushort *)0x0) {
        uVar2 = *puVar15;
        puStack_9c = puVar15;
        piVar16 = DAT_00fb7608;
        while (uVar2 != 0) {
          puVar15 = (ushort *)(uint)*puStack_9c;
          if (*puStack_9c < 0x80) {
            if ((((ushort *)0x9 < puVar15 + -0x18) &&
                ((undefined1 *)0x19 < (undefined1 *)((int)puVar15 - 0x41U))) &&
               (((undefined1 *)0x19 < (undefined1 *)((int)puVar15 - 0x61U) &&
                ((puVar15 != (ushort *)0x20 &&
                 ((undefined1 *)0x5d < (undefined1 *)((int)puVar15 - 0x21U))))))) goto LAB_00668fb2;
          }
          else {
            iVar7 = (**(code **)(*piVar16 + 8))();
            piVar16 = DAT_00fb7608;
            iVar14 = DAT_00fb7608[2];
            puStack_a0 = puVar15;
            piVar10 = (int *)FUN_0081ed70();
            if ((*piVar10 == iVar14) && (iVar7 == 0)) goto LAB_00668fb2;
          }
          puStack_9c = puStack_9c + 1;
          uVar2 = *puStack_9c;
        }
        uStack_c4 = 0x668fa7;
        iVar14 = FUN_0081eb80();
        if (iVar14 == 0) {
          puVar15 = local_80;
          if (local_6c < 8) {
            puVar15 = (ushort *)&local_80;
          }
          puStack_9c = puVar15;
          if ((DAT_00fb75c0 & 1) == 0) {
            DAT_00fb75c0 = DAT_00fb75c0 | 1;
            local_c._0_1_ = 0xc;
            FUN_0081e5f0();
            _atexit((_func_4879 *)&LAB_00bcd250);
            local_c._0_1_ = 2;
          }
          if (puVar15 != (ushort *)0x0) {
            uVar2 = *puVar15;
            local_98 = puVar15;
            piVar16 = DAT_00fb7608;
            while (uVar2 != 0) {
              puVar15 = (ushort *)(uint)*local_98;
              if (*local_98 < 0x80) {
                if (((((ushort *)0x9 < puVar15 + -0x18) &&
                     ((undefined1 *)0x19 < (undefined1 *)((int)puVar15 - 0x41U))) &&
                    ((undefined1 *)0x19 < (undefined1 *)((int)puVar15 - 0x61U))) &&
                   ((puVar15 != (ushort *)0x20 &&
                    ((undefined1 *)0x5d < (undefined1 *)((int)puVar15 - 0x21U)))))
                goto LAB_00669282;
              }
              else {
                iVar7 = (**(code **)(*piVar16 + 8))();
                piVar16 = DAT_00fb7608;
                iVar14 = DAT_00fb7608[2];
                puStack_a0 = puVar15;
                piVar10 = (int *)FUN_0081ed70();
                if ((*piVar10 == iVar14) && (iVar7 == 0)) goto LAB_00669282;
              }
              local_98 = local_98 + 1;
              uVar2 = *local_98;
            }
            uStack_c4 = 0x669277;
            iVar14 = FUN_0081eb80();
            if (iVar14 == 0) {
              if (local_54 == 0) {
                if ((DAT_00faadd4 & 1) == 0) {
                  DAT_00faadd4 = DAT_00faadd4 | 1;
                  local_c._0_1_ = 0x10;
                  FUN_00587480();
                  _atexit((_func_4879 *)&LAB_00bcccc0);
                  local_c._0_1_ = 2;
                }
                puStack_94 = (undefined1 *)auStack_d8;
                uStack_c4 = 7;
                uStack_c8 = 0;
                puStack_e0 = &DAT_00bed1fc;
                auStack_d8[0] = 0;
                uStack_e4 = 0x6694a9;
                FUN_00402160();
                if ((DAT_00fe5b2c & 1) == 0) {
                  DAT_00fe5b2c = DAT_00fe5b2c | 1;
                  local_c._0_1_ = 0x12;
                  puStack_e0 = (undefined2 *)0x6694d4;
                  FUN_00584c40();
                  puStack_e0 = (undefined2 *)0x6694de;
                  _atexit(FUN_00bcf370);
                }
                local_c = CONCAT31(local_c._1_3_,0x11);
                puStack_a0 = (ushort *)0x0;
                puStack_e0 = (undefined2 *)0x6694ff;
                FUN_005740f0();
                if (puStack_9c == DAT_00fe5b10) {
                  pcVar4 = (code *)swi(3);
                  (*pcVar4)();
                  return;
                }
                puVar15 = puStack_9c + 8;
                puVar11 = puVar15;
                if (7 < *(uint *)(puStack_9c + 0x12)) {
                  puVar15 = *(ushort **)puVar15;
                  puVar11 = puVar15;
                }
                do {
                  uVar2 = *puVar15;
                  puVar15 = puVar15 + 1;
                } while (uVar2 != 0);
LAB_006698cb:
                puStack_a0 = auStack_f4;
                puStack_e0 = (undefined2 *)0x7;
                uStack_e4 = 0;
                auStack_f4[0] = 0;
                FUN_00402160(puVar11,(int)puVar15 - (int)(puVar11 + 1) >> 1);
                local_c._0_1_ = 2;
                FUN_0058b270(0xca);
              }
              else {
                pwVar12 = local_64;
                if (local_50 < 8) {
                  pwVar12 = (wchar_t *)&local_64;
                }
                if ((DAT_00fb75c0 & 1) == 0) {
                  DAT_00fb75c0 = DAT_00fb75c0 | 1;
                  local_c._0_1_ = 0x13;
                  FUN_0081e5f0();
                  _atexit((_func_4879 *)&LAB_00bcd250);
                  local_c._0_1_ = 2;
                }
                if (pwVar12 != (wchar_t *)0x0) {
                  wVar3 = *pwVar12;
                  while (wVar3 != L'\0') {
                    uVar8 = (uint)(ushort)*pwVar12;
                    if ((ushort)*pwVar12 < 0x80) {
                      if (((9 < uVar8 - 0x30) && (0x19 < uVar8 - 0x41)) && (0x19 < uVar8 - 0x61))
                      goto LAB_006695e9;
                    }
                    else {
                      iVar14 = (**(code **)(*DAT_00fb7608 + 8))();
                      if (iVar14 == 0) goto LAB_006695e9;
                    }
                    pwVar12 = pwVar12 + 1;
                    wVar3 = *pwVar12;
                  }
                  uStack_c4 = 0x6695de;
                  iVar14 = FUN_0081eb80();
                  if (iVar14 == 0) {
                    if ((DAT_00f94390 & 1) == 0) {
                      DAT_00f94390 = DAT_00f94390 | 1;
                      local_c._0_1_ = 0x17;
                      FUN_004e1590();
                      _atexit((_func_4879 *)&LAB_00bccc80);
                      local_c._0_1_ = 2;
                    }
                    pwVar12 = local_64;
                    if (local_50 < 8) {
                      pwVar12 = (wchar_t *)&local_64;
                    }
                    pwVar13 = &DAT_00f938f2;
                    do {
                      wVar3 = *pwVar12;
                      bVar17 = (ushort)wVar3 < (ushort)*pwVar13;
                      if (wVar3 != *pwVar13) {
LAB_006697b6:
                        iVar14 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
                        goto LAB_006697bb;
                      }
                      if (wVar3 == L'\0') break;
                      wVar3 = pwVar12[1];
                      bVar17 = (ushort)wVar3 < (ushort)pwVar13[1];
                      if (wVar3 != pwVar13[1]) goto LAB_006697b6;
                      pwVar12 = pwVar12 + 2;
                      pwVar13 = pwVar13 + 2;
                    } while (wVar3 != L'\0');
                    iVar14 = 0;
LAB_006697bb:
                    if (iVar14 == 0) {
                      if ((DAT_00faadd4 & 1) == 0) {
                        DAT_00faadd4 = DAT_00faadd4 | 1;
                        local_c._0_1_ = 0x18;
                        FUN_00587480();
                        _atexit((_func_4879 *)&LAB_00bcccc0);
                        local_c._0_1_ = 2;
                      }
                      puStack_94 = (undefined1 *)auStack_d8;
                      uStack_c4 = 7;
                      uStack_c8 = 0;
                      puStack_e0 = &DAT_00bed1fc;
                      auStack_d8[0] = 0;
                      uStack_e4 = 0x669820;
                      FUN_00402160();
                      if ((DAT_00fe5b2c & 1) == 0) {
                        DAT_00fe5b2c = DAT_00fe5b2c | 1;
                        local_c._0_1_ = 0x1a;
                        puStack_e0 = (undefined2 *)0x66984a;
                        FUN_00584c40();
                        puStack_e0 = (undefined2 *)0x669854;
                        _atexit(FUN_00bcf370);
                      }
                      local_c = CONCAT31(local_c._1_3_,0x19);
                      puStack_a0 = (ushort *)0xb1;
                      puStack_e0 = (undefined2 *)0x66987a;
                      FUN_005740f0();
                      if (puStack_9c == DAT_00fe5b10) {
                        pcVar4 = (code *)swi(3);
                        (*pcVar4)();
                        return;
                      }
                      puVar15 = puStack_9c + 8;
                      puVar11 = puVar15;
                      if (7 < *(uint *)(puStack_9c + 0x12)) {
                        puVar15 = *(ushort **)puVar15;
                        puVar11 = puVar15;
                      }
                      do {
                        uVar2 = *puVar15;
                        puVar15 = puVar15 + 1;
                      } while (uVar2 != 0);
                      goto LAB_006698cb;
                    }
                    pwVar12 = local_64;
                    if (local_50 < 8) {
                      pwVar12 = (wchar_t *)&local_64;
                    }
                    local_48 = CONCAT22(local_48._2_2_,0x91);
                    uStack_c4 = 0x66990e;
                    _wcscpy_s((wchar_t *)((int)&local_48 + 2),0x15,pwVar12);
                    if (DAT_00fba798 == 0) {
                      uStack_c4 = 0x669930;
                      (**(code **)(*DAT_00fba854 + 0x10))();
                    }
                    goto LAB_00669930;
                  }
                }
LAB_006695e9:
                if ((DAT_00faadd4 & 1) == 0) {
                  DAT_00faadd4 = DAT_00faadd4 | 1;
                  local_c._0_1_ = 0x14;
                  FUN_00587480();
                  _atexit((_func_4879 *)&LAB_00bcccc0);
                  local_c._0_1_ = 2;
                }
                puStack_94 = (undefined1 *)auStack_d8;
                uStack_c4 = 7;
                uStack_c8 = 0;
                puStack_e0 = &DAT_00bed1fc;
                auStack_d8[0] = 0;
                uStack_e4 = 0x669646;
                FUN_00402160();
                if ((DAT_00fe5b2c & 1) == 0) {
                  DAT_00fe5b2c = DAT_00fe5b2c | 1;
                  local_c._0_1_ = 0x16;
                  puStack_e0 = (undefined2 *)0x669671;
                  FUN_00584c40();
                  puStack_e0 = (undefined2 *)0x66967b;
                  _atexit(FUN_00bcf370);
                }
                local_c._0_1_ = 0x15;
                puStack_a0 = (ushort *)0x9b;
                puStack_e0 = (undefined2 *)0x6696a0;
                FUN_005740f0();
                if (puStack_9c == DAT_00fe5b10) {
                  pcVar4 = (code *)swi(3);
                  (*pcVar4)();
                  return;
                }
                puVar15 = puStack_9c + 8;
                if (7 < *(uint *)(puStack_9c + 0x12)) {
                  puVar15 = *(ushort **)puVar15;
                }
                puStack_a0 = auStack_f4;
                puStack_e0 = (undefined2 *)0x7;
                uStack_e4 = 0;
                auStack_f4[0] = 0;
                puVar11 = puVar15;
                do {
                  uVar2 = *puVar11;
                  puVar11 = puVar11 + 1;
                } while (uVar2 != 0);
                FUN_00402160(puVar15,(int)puVar11 - (int)(puVar15 + 1) >> 1);
                local_c._0_1_ = 2;
                FUN_0058b270(0xca);
              }
LAB_00669930:
              if (local_90 != (undefined2 *)0x0) {
                FUN_0049bf30();
                FUN_0089120c();
              }
              if (7 < local_6c) {
                FUN_0089120c();
              }
              goto joined_r0x00668ea7;
            }
          }
LAB_00669282:
          if ((DAT_00faadd4 & 1) == 0) {
            DAT_00faadd4 = DAT_00faadd4 | 1;
            local_c._0_1_ = 0xd;
            FUN_00587480();
            _atexit((_func_4879 *)&LAB_00bcccc0);
            local_c._0_1_ = 2;
          }
          puStack_94 = (undefined1 *)auStack_d8;
          uStack_c4 = 7;
          uStack_c8 = 0;
          puStack_e0 = &DAT_00bed1fc;
          auStack_d8[0] = 0;
          uStack_e4 = 0x6692e0;
          FUN_00402160();
          if ((DAT_00fe5b2c & 1) == 0) {
            DAT_00fe5b2c = DAT_00fe5b2c | 1;
            local_c._0_1_ = 0xf;
            puStack_e0 = (undefined2 *)0x66930b;
            FUN_00584c40();
            puStack_e0 = (undefined2 *)0x669315;
            _atexit(FUN_00bcf370);
          }
          local_c._0_1_ = 0xe;
          puStack_a0 = (ushort *)0x72;
          puStack_e0 = (undefined2 *)0x66933a;
          FUN_005740f0();
          if (puStack_9c == DAT_00fe5b10) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          puVar15 = puStack_9c + 8;
          if (7 < *(uint *)(puStack_9c + 0x12)) {
            puVar15 = *(ushort **)puVar15;
          }
          puStack_a0 = auStack_f4;
          puStack_e0 = (undefined2 *)0x7;
          uStack_e4 = 0;
          auStack_f4[0] = 0;
          puVar11 = puVar15;
          do {
            uVar2 = *puVar11;
            puVar11 = puVar11 + 1;
          } while (uVar2 != 0);
          FUN_00402160(puVar15,(int)puVar11 - (int)(puVar15 + 1) >> 1);
          local_c._0_1_ = 2;
          FUN_0058b270(0xca);
          if (local_90 != (undefined2 *)0x0) {
            FUN_0049bf30();
            FUN_0089120c();
          }
          if (7 < local_6c) {
            FUN_0089120c();
          }
          goto joined_r0x00668ea7;
        }
      }
LAB_00668fb2:
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c._0_1_ = 9;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c._0_1_ = 2;
      }
      puStack_94 = (undefined1 *)auStack_d8;
      uStack_c4 = 7;
      uStack_c8 = 0;
      puStack_e0 = &DAT_00bed1fc;
      auStack_d8[0] = 0;
      uStack_e4 = 0x66900f;
      FUN_00402160();
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c._0_1_ = 0xb;
        puStack_e0 = (undefined2 *)0x66903a;
        FUN_00584c40();
        puStack_e0 = (undefined2 *)0x669044;
        _atexit(FUN_00bcf370);
      }
      local_c._0_1_ = 10;
      puStack_a0 = (ushort *)0xaa;
      puStack_e0 = (undefined2 *)0x669069;
      FUN_005740f0();
      if (puStack_9c == DAT_00fe5b10) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      puVar15 = puStack_9c + 8;
      if (7 < *(uint *)(puStack_9c + 0x12)) {
        puVar15 = *(ushort **)puVar15;
      }
      puStack_a0 = auStack_f4;
      puStack_e0 = (undefined2 *)0x7;
      uStack_e4 = 0;
      auStack_f4[0] = 0;
      puVar11 = puVar15;
      do {
        uVar2 = *puVar11;
        puVar11 = puVar11 + 1;
      } while (uVar2 != 0);
      FUN_00402160(puVar15,(int)puVar11 - (int)(puVar15 + 1) >> 1);
      local_c._0_1_ = 2;
      FUN_0058b270(0xca);
      puVar6 = local_8c;
      puVar5 = local_90;
      if (local_90 != (undefined2 *)0x0) {
        for (; puVar5 != puVar6; puVar5 = puVar5 + 0xe) {
          if (7 < *(uint *)(puVar5 + 10)) {
            FUN_0089120c();
          }
          *(undefined4 *)(puVar5 + 10) = 7;
          *(undefined4 *)(puVar5 + 8) = 0;
          *puVar5 = 0;
        }
        FUN_0089120c();
      }
      if (7 < local_6c) {
        FUN_0089120c();
      }
      goto joined_r0x00668ea7;
    }
  }
LAB_00668cb4:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c._0_1_ = 5;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c._0_1_ = 2;
  }
  puStack_a0 = auStack_d8;
  uStack_c4 = 7;
  uStack_c8 = 0;
  puStack_e0 = &DAT_00bed1fc;
  auStack_d8[0] = 0;
  uStack_e4 = 0x668d11;
  FUN_00402160();
  local_c._0_1_ = 6;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 7;
    puStack_e0 = (undefined2 *)0x668d3c;
    FUN_00584c40();
    puStack_e0 = (undefined2 *)0x668d46;
    _atexit(FUN_00bcf370);
    local_c._0_1_ = 6;
  }
  local_c._0_1_ = 6;
  cVar1 = *(char *)((int)*(ushort **)(DAT_00fe5b10 + 2) + 0x2d);
  puVar15 = *(ushort **)(DAT_00fe5b10 + 2);
  puStack_9c = DAT_00fe5b10;
  while (puVar11 = puVar15, cVar1 == '\0') {
    if (*(int *)(puVar11 + 6) < 0x9b) {
      puVar15 = *(ushort **)(puVar11 + 4);
      puVar11 = puStack_9c;
    }
    else {
      puVar15 = *(ushort **)puVar11;
    }
    cVar1 = *(char *)((int)puVar15 + 0x2d);
    puStack_9c = puVar11;
  }
  if ((puStack_9c == DAT_00fe5b10) || (0x9b < *(int *)(puStack_9c + 6))) {
    local_98 = DAT_00fe5b10;
    ppuVar9 = &local_98;
  }
  else {
    ppuVar9 = &puStack_9c;
  }
  puVar15 = *ppuVar9;
  if (puVar15 == DAT_00fe5b10) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  puVar11 = puVar15 + 8;
  if (7 < *(uint *)(puVar15 + 0x12)) {
    puVar11 = *(ushort **)puVar11;
  }
  puStack_9c = auStack_f4;
  puStack_e0 = (undefined2 *)0x7;
  uStack_e4 = 0;
  auStack_f4[0] = 0;
  puVar15 = puVar11;
  do {
    uVar2 = *puVar15;
    puVar15 = puVar15 + 1;
  } while (uVar2 != 0);
  FUN_00402160(puVar11,(int)puVar15 - (int)(puVar11 + 1) >> 1);
  local_c._0_1_ = 2;
  FUN_0058b270(0xca);
  puVar6 = local_8c;
  puVar5 = local_90;
  if (local_90 != (undefined2 *)0x0) {
    for (; puVar5 != puVar6; puVar5 = puVar5 + 0xe) {
      if (7 < *(uint *)(puVar5 + 10)) {
        FUN_0089120c();
      }
      *(undefined4 *)(puVar5 + 10) = 7;
      *(undefined4 *)(puVar5 + 8) = 0;
      *puVar5 = 0;
    }
    FUN_0089120c();
  }
  if (7 < local_6c) {
    FUN_0089120c();
  }
joined_r0x00668ea7:
  local_80 = (ushort *)((uint)local_80 & 0xffff0000);
  local_70 = 0;
  local_6c = 7;
  if (7 < local_50) {
    local_6c = 7;
    local_70 = 0;
    FUN_0089120c();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_a4);
  return;
}

