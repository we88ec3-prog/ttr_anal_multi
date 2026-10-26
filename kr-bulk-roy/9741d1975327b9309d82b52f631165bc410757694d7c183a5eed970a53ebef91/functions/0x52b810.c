
void FUN_0052b810(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  char cVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  char *_Str1;
  int iVar12;
  undefined4 **ppuVar13;
  undefined4 *apuStack_bc [2];
  int iStack_b4;
  int *local_b0;
  undefined4 *puStack_ac;
  undefined4 uStack_a8;
  undefined4 *puStack_a4;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923779;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)apuStack_bc;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffff38;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar4 = FUN_0072f110(0);
  if (cVar4 == '\0') {
    FUN_006edb60(&DAT_00c0ee28,uVar6);
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c = local_4c & 0xffffff00;
    FUN_0072e040();
  }
  else {
    iVar7 = FUN_0072e2e0("ITEM_RANDOM_CAPSULE");
    if (iVar7 == 0) {
      FUN_006edb60(&DAT_00c0ee64,uVar6);
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c = local_4c & 0xffffff00;
      FUN_0072e040();
    }
    else {
      piVar8 = (int *)FUN_0072e2e0(&DAT_00bf2330);
      if (piVar8 == (int *)0x0) {
        local_b0 = piVar8;
        FUN_006edb60(&DAT_00c0ee94,uVar6);
      }
      else {
        do {
          local_b0 = piVar8;
          apuStack_bc[1] = (undefined4 *)FUN_00891268(0x1c);
          if (apuStack_bc[1] == (undefined4 *)0x0) {
            apuStack_bc[1] = (undefined4 *)0x0;
          }
          else {
            apuStack_bc[1][3] = 0;
            apuStack_bc[1][4] = 0;
            apuStack_bc[1][5] = 0;
          }
          puVar11 = apuStack_bc[1];
          (**(code **)(*piVar8 + 0x14))();
          iVar7 = FUN_007300a0(&DAT_00c0ce2c);
          if (iVar7 == 0) {
LAB_0052b9de:
            uVar10 = 0;
          }
          else {
            puVar9 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 == (undefined4 *)0x0) goto LAB_0052b9de;
            uVar10 = FUN_008917b4(puVar9);
          }
          *puVar11 = uVar10;
          iVar7 = FUN_007300a0("CAPSULE_TYPE");
          if (iVar7 == 0) {
LAB_0052ba09:
            uVar10 = 1;
          }
          else {
            puVar9 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 == (undefined4 *)0x0) goto LAB_0052ba09;
            uVar10 = FUN_008917b4(puVar9);
          }
          puVar11[1] = uVar10;
          iVar7 = FUN_007300a0("BOX_TYPE");
          if (iVar7 == 0) {
LAB_0052ba38:
            uVar10 = 0;
          }
          else {
            puVar11 = (undefined4 *)(iVar7 + 0x30);
            if (0xf < *(uint *)(iVar7 + 0x44)) {
              puVar11 = (undefined4 *)*puVar11;
            }
            if (puVar11 == (undefined4 *)0x0) goto LAB_0052ba38;
            uVar10 = FUN_008917b4(puVar11);
          }
          apuStack_bc[1][2] = uVar10;
          iStack_b4 = FUN_0072e360();
          while (iStack_b4 != 0) {
            iVar7 = iStack_b4 + 0x44;
            for (iVar1 = *(int *)(iStack_b4 + 0x94); iVar1 != iVar7; iVar1 = *(int *)(iVar1 + 0x50))
            {
              _Str1 = (char *)(iVar1 + 0x14);
              if (0xf < *(uint *)(iVar1 + 0x28)) {
                _Str1 = *(char **)_Str1;
              }
              iVar12 = __stricmp(_Str1,"PRODUCT");
              if (iVar12 == 0) {
                if (iVar1 != 0) {
                  puVar11 = (undefined4 *)(iVar1 + 0x30);
                  if (0xf < *(uint *)(iVar1 + 0x44)) {
                    puVar11 = (undefined4 *)*puVar11;
                  }
                  if (puVar11 != (undefined4 *)0x0) {
                    iVar7 = FUN_008917b4(puVar11);
                    goto LAB_0052ba96;
                  }
                }
                break;
              }
            }
            iVar7 = 0;
LAB_0052ba96:
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c._0_1_ = 1;
              FUN_0051c120();
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = (uint)local_c._1_3_ << 8;
            }
            cVar4 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
            puVar11 = (undefined4 *)DAT_00f8d91c[1];
            apuStack_bc[0] = DAT_00f8d91c;
            while (puVar9 = puVar11, cVar4 == '\0') {
              if ((int)puVar9[3] < iVar7) {
                puVar11 = (undefined4 *)puVar9[2];
                puVar9 = apuStack_bc[0];
              }
              else {
                puVar11 = (undefined4 *)*puVar9;
              }
              cVar4 = *(char *)((int)puVar11 + 0x15);
              apuStack_bc[0] = puVar9;
            }
            if ((apuStack_bc[0] == DAT_00f8d91c) || (iVar7 < (int)apuStack_bc[0][3])) {
              puStack_ac = DAT_00f8d91c;
              ppuVar13 = &puStack_ac;
            }
            else {
              ppuVar13 = apuStack_bc;
            }
            if ((*ppuVar13 == DAT_00f8d91c) ||
               (apuStack_bc[0] = (undefined4 *)(*ppuVar13)[4], apuStack_bc[0] == (undefined4 *)0x0))
            {
              iStack_b4 = FUN_0072e3c0();
            }
            else {
              puVar11 = (undefined4 *)FUN_00891268(0x10);
              if (puVar11 == (undefined4 *)0x0) {
                puVar11 = (undefined4 *)0x0;
              }
              else {
                iVar7 = FUN_007300a0("ORDER");
                if (iVar7 == 0) {
LAB_0052bb91:
                  uVar10 = 0;
                }
                else {
                  puVar9 = (undefined4 *)(iVar7 + 0x30);
                  if (0xf < *(uint *)(iVar7 + 0x44)) {
                    puVar9 = (undefined4 *)*puVar9;
                  }
                  if (puVar9 == (undefined4 *)0x0) goto LAB_0052bb91;
                  uVar10 = FUN_008917b4(puVar9);
                }
                iVar7 = FUN_007300a0("QUANTITY");
                if (iVar7 == 0) {
LAB_0052bbbb:
                  uVar5 = 0;
                }
                else {
                  puVar9 = (undefined4 *)(iVar7 + 0x30);
                  if (0xf < *(uint *)(iVar7 + 0x44)) {
                    puVar9 = (undefined4 *)*puVar9;
                  }
                  if (puVar9 == (undefined4 *)0x0) goto LAB_0052bbbb;
                  uVar5 = FUN_008917b4(puVar9);
                }
                uVar2 = apuStack_bc[0][8];
                *puVar11 = apuStack_bc[0][7];
                puVar11[1] = uVar2;
                *(undefined2 *)(puVar11 + 2) = uVar5;
                puVar11[3] = uVar10;
              }
              puVar9 = apuStack_bc[1];
              ppuVar13 = (undefined4 **)apuStack_bc[1][4];
              apuStack_bc[0] = puVar11;
              if (apuStack_bc < ppuVar13) {
                ppuVar3 = (undefined4 **)apuStack_bc[1][3];
                if (apuStack_bc < ppuVar3) goto LAB_0052bc1e;
                if (ppuVar13 == (undefined4 **)apuStack_bc[1][5]) {
                  FUN_004deab0();
                }
                if ((undefined4 *)puVar9[4] != (undefined4 *)0x0) {
                  *(undefined4 *)puVar9[4] =
                       *(undefined4 *)(puVar9[3] + ((int)apuStack_bc - (int)ppuVar3 >> 2) * 4);
                }
              }
              else {
LAB_0052bc1e:
                if (ppuVar13 == (undefined4 **)apuStack_bc[1][5]) {
                  FUN_004deab0();
                }
                if ((undefined4 *)puVar9[4] != (undefined4 *)0x0) {
                  *(undefined4 *)puVar9[4] = puVar11;
                }
              }
              puVar9[4] = puVar9[4] + 4;
              iStack_b4 = FUN_0072e3c0();
            }
          }
          uStack_a8 = *apuStack_bc[1];
          puStack_a4 = apuStack_bc[1];
          uVar10 = FUN_0057ef20();
          FUN_0057e850(&DAT_00fe2880,uVar10);
          piVar8 = (int *)FUN_0072e320(&DAT_00bf2330);
          local_b0 = piVar8;
        } while (piVar8 != (int *)0x0);
      }
      local_c = 0xffffffff;
      FUN_00407fb0();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)apuStack_bc);
  return;
}

