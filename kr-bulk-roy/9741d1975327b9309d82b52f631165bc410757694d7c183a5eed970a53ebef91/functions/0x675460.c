
void FUN_00675460(void)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  short **ppsVar8;
  ushort *puVar9;
  short *psVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int unaff_EDI;
  short *local_88;
  int local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  int *local_74;
  int *local_70;
  short *local_6c;
  int local_68;
  int iStack_64;
  undefined **local_60 [3];
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint uStack_38;
  uint uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945f88;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_88;
  ExceptionList = &local_14;
  uVar5 = *(int *)(unaff_EDI + 0x17c) * 10;
  piVar15 = (int *)(*(int *)(unaff_EDI + 0x1a8) - *(int *)(unaff_EDI + 0x1a4) >> 2);
  if (piVar15 < uVar5 + 10) {
    local_80 = (uint)piVar15 % 10;
  }
  else {
    local_80 = 10;
  }
  if (piVar15 < uVar5) {
    local_80 = 0;
  }
  iVar6 = *(int *)(*(int *)(unaff_EDI + 0x110) + 0xcc);
  local_7c = 0;
  local_70 = piVar15;
  if (iVar6 != 0) {
    FUN_00408920(iVar6);
  }
  if (local_80 != 0) {
    local_78 = *(int *)(unaff_EDI + 0x17c) * 0x28;
    do {
      puVar12 = (undefined4 *)(*(int *)(unaff_EDI + 0x1a4) + local_78);
      if ((DAT_00fe1de0 & 1) == 0) {
        DAT_00fe1de0 = DAT_00fe1de0 | 1;
        local_c = 0;
        DAT_00fe1dec = 0;
        iVar6 = FUN_00891268();
        if (iVar6 == 0) {
          local_74 = (int *)0x0;
          std::exception::exception((exception *)local_60,(char **)&local_74);
          local_60[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_60);
        }
        DAT_00fe1de8 = iVar6;
        *(int *)iVar6 = iVar6;
        *(int *)(DAT_00fe1de8 + 4) = DAT_00fe1de8;
        *(int *)(DAT_00fe1de8 + 8) = DAT_00fe1de8;
        *(undefined1 *)(DAT_00fe1de8 + 0x38) = 1;
        *(undefined1 *)(DAT_00fe1de8 + 0x39) = 1;
        _atexit(FUN_00bcef60);
        local_c = 0xffffffff;
      }
      local_88 = (short *)*puVar12;
      FUN_00519680();
      if (local_68 == DAT_00fe1de8) {
        local_84 = 0;
      }
      else {
        local_84 = local_68 + 0x10;
      }
      piVar13 = (int *)(*(int *)(unaff_EDI + 0x1a4) + local_78);
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 1;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      iVar6 = *piVar13;
      cVar1 = *(char *)((int)*(short **)(DAT_00f8d91c + 2) + 0x15);
      psVar7 = *(short **)(DAT_00f8d91c + 2);
      local_88 = DAT_00f8d91c;
      while (psVar10 = psVar7, cVar1 == '\0') {
        if (*(int *)(psVar10 + 6) < iVar6) {
          psVar7 = *(short **)(psVar10 + 4);
          psVar10 = local_88;
        }
        else {
          psVar7 = *(short **)psVar10;
        }
        cVar1 = *(char *)((int)psVar7 + 0x15);
        local_88 = psVar10;
      }
      if ((local_88 == DAT_00f8d91c) || (iVar6 < *(int *)(local_88 + 6))) {
        local_6c = DAT_00f8d91c;
        ppsVar8 = &local_6c;
      }
      else {
        ppsVar8 = &local_88;
      }
      if (*ppsVar8 == DAT_00f8d91c) {
        local_88 = (short *)0x0;
      }
      else {
        local_88 = *(short **)(*ppsVar8 + 8);
      }
      psVar7 = local_88;
      if ((local_84 != 0) && (local_88 != (short *)0x0)) {
        if (*(int *)(local_84 + 0x14) == 0) {
LAB_006756f6:
          if (7 < *(uint *)(psVar7 + 10)) {
            psVar7 = *(short **)psVar7;
          }
          local_54 = local_54 & 0xffff0000;
          local_40 = 7;
          local_44 = 0;
          psVar10 = psVar7;
          do {
            sVar2 = *psVar10;
            psVar10 = psVar10 + 1;
          } while (sVar2 != 0);
          FUN_00402160(psVar7);
          local_c._0_1_ = 3;
          local_c._1_3_ = 0;
          iVar6 = *(int *)(*(int *)(unaff_EDI + 0x110) + 0xcc);
          if (iVar6 != 0) {
            for (piVar15 = *(int **)(iVar6 + 0xa8); piVar15 != *(int **)(iVar6 + 0xac);
                piVar15 = piVar15 + 1) {
              piVar13 = (int *)*piVar15;
              if (piVar13[8] == local_7c) {
                if (piVar13 != (int *)0x0) {
                  iVar6 = (**(code **)(*piVar13 + 4))();
                  if (iVar6 == 0x12d) goto LAB_006757a5;
                  MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
                }
                break;
              }
            }
          }
          piVar13 = (int *)0x0;
LAB_006757a5:
          *(undefined1 *)(piVar13[0x92] + 0x268) = 1;
          (**(code **)(*(int *)piVar13[0x92] + 0x19c))
                    (*(undefined4 *)(local_88 + 0x10),*(undefined4 *)(local_88 + 0xe),0);
          if (*(int *)(local_84 + 0x10) != 0) {
            FUN_00404300(&DAT_00c225d0);
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 4;
              FUN_00584c40();
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c._0_1_ = 3;
            }
            local_88 = (short *)0x34;
            FUN_005740f0();
            if (iStack_64 == DAT_00fe5ac8) {
              pcVar4 = (code *)swi(3);
              (*pcVar4)();
              return;
            }
            uVar11 = FUN_004068f0();
            local_c._0_1_ = 5;
            FUN_004041f0(uVar11,0);
            local_c._0_1_ = 3;
            if ((void *)0x7 < pvStack_24) {
              FUN_0089120c();
            }
            pvStack_24 = (void *)0x7;
            uStack_28 = 0;
            uStack_38 = uStack_38 & 0xffff0000;
            FUN_00404300(&DAT_00c26458);
          }
          iVar6 = piVar13[0x92];
          uVar11 = *(undefined4 *)(local_84 + 0x10);
          *(undefined1 *)(iVar6 + 0x269) = 0;
          *(undefined4 *)(iVar6 + 0x26c) = 0;
          *(undefined4 *)(iVar6 + 0x270) = uVar11;
          *(undefined4 *)(iVar6 + 0x274) = 0;
          FUN_00757800();
          local_7c = local_7c + 1;
          local_c = 0xffffffff;
          if (7 < local_40) {
            FUN_0089120c();
          }
          local_40 = 7;
          local_44 = 0;
          local_54 = local_54 & 0xffff0000;
          piVar15 = local_70;
        }
        else {
          if ((DAT_00fab29c & 1) == 0) {
            DAT_00fab29c = DAT_00fab29c | 1;
            local_c = 2;
            FUN_004ffe60();
            _atexit((_func_4879 *)&LAB_00bccf00);
            local_c = 0xffffffff;
          }
          puVar9 = &DAT_00fb1170;
          do {
            if ((uint)*puVar9 == *(uint *)(local_84 + 0x14)) goto LAB_006756f6;
            puVar9 = puVar9 + 1;
          } while ((int)puVar9 < 0xfb1198);
        }
      }
      local_78 = local_78 + 4;
    } while (local_7c < local_80);
  }
  local_70 = *(int **)(unaff_EDI + 0x110);
  piVar13 = (int *)local_70[0x19];
  piVar14 = (int *)*piVar13;
  local_74 = piVar13;
  if (piVar14 != piVar13) {
    do {
      if ((*(int *)(piVar14[2] + 0x60) != 0) &&
         (piVar3 = *(int **)(piVar14[2] + 0x1c), piVar3[2] != 6)) {
        (**(code **)(*piVar3 + 0x30))();
        piVar13 = local_74;
      }
      piVar14 = (int *)*piVar14;
    } while (piVar14 != piVar13);
  }
  (**(code **)(*local_70 + 0x128))();
  (**(code **)(**(int **)(unaff_EDI + 0x110) + 200))();
  if (*(int *)(unaff_EDI + 0x18c) == 0) {
    *(undefined4 *)(unaff_EDI + 0x1c8) = 0;
  }
  FUN_006767d0();
  *(uint *)(unaff_EDI + 0x178) = (uint)piVar15 / 10 + (uint)((uint)piVar15 % 10 != 0);
  (**(code **)(**(int **)(unaff_EDI + 0x16c) + 0x90))();
  (**(code **)(**(int **)(unaff_EDI + 0x16c) + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x174) + 0x90))
            ((byte)(*(uint *)(*(int *)(unaff_EDI + 0x16c) + 0x28) >> 7) & 1);
  (**(code **)(**(int **)(unaff_EDI + 0x174) + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x168) + 0x90))(*(int *)(unaff_EDI + 0x17c) != 0);
  (**(code **)(**(int **)(unaff_EDI + 0x168) + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x170) + 0x90))
            ((byte)(*(uint *)(*(int *)(unaff_EDI + 0x168) + 0x28) >> 7) & 1);
  (**(code **)(**(int **)(unaff_EDI + 0x170) + 200))();
  FUN_00677730(unaff_EDI);
  ExceptionList = pvStack_24;
  __security_check_cookie(uStack_2c ^ (uint)&stack0xffffff68);
  return;
}

