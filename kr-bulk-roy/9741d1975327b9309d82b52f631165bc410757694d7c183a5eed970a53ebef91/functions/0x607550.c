
void FUN_00607550(void)

{
  short sVar1;
  undefined4 uVar2;
  code *pcVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int in_ECX;
  int unaff_ESI;
  short *psStack_98;
  uint uStack_94;
  int iStack_8c;
  uint uVar9;
  int iStack_7c;
  uint uStack_78;
  int local_74;
  int local_70;
  short *local_6c;
  int local_68;
  undefined1 *puStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  void *pvStack_30;
  uint uStack_28;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00946bf3;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_7c;
  ExceptionList = &local_14;
  if ((DAT_00fe1de0 & 1) == 0) {
    DAT_00fe1de0 = DAT_00fe1de0 | 1;
    local_c = 0;
    FUN_00519060();
    uStack_94 = 0x6075b1;
    _atexit(FUN_00bcef60);
  }
  local_c = 0xffffffff;
  local_74 = *(undefined4 *)(in_ECX + 0x120);
  uStack_94 = 0x6075e0;
  FUN_00519680();
  if (local_70 == DAT_00fe1de8) {
    local_6c = (short *)0x0;
  }
  else {
    local_6c = (short *)(local_70 + 0x10);
  }
  psVar4 = local_6c;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    uStack_94 = 0x607625;
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_c = 0xffffffff;
  }
  local_74 = *(int *)(in_ECX + 0x120);
  uStack_94 = 0x607650;
  FUN_008438c0();
  if (local_70 == DAT_00f8d91c) {
    local_68 = 0;
  }
  else {
    local_68 = *(int *)(local_70 + 0x10);
  }
  uStack_78 = uStack_78 & 0xffffff;
  *(undefined4 *)(in_ECX + 0x124) = 0xff;
  if ((psVar4 == (short *)0x0) || (local_68 == 0)) {
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
    uStack_94 = 0;
    psStack_98 = (short *)0x0;
    (**(code **)(**(int **)(in_ECX + 0x118) + 0x1ac))();
    (**(code **)(**(int **)(in_ECX + 0x118) + 200))();
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
    if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xcc) != 0) {
      FUN_006438f0();
    }
    FUN_00749920();
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
    (**(code **)(**(int **)(in_ECX + 0x114) + 0x94))();
    (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
  }
  else {
    if (*(int *)(psVar4 + 6) == 100) {
      FUN_00749d00();
    }
    else {
      FUN_00749d00();
      uStack_94 = 0x6076b6;
      FUN_007597b0();
    }
    uStack_94 = 0x6076d6;
    (**(code **)(**(int **)(in_ECX + 0x114) + 0x94))();
    psStack_98 = local_6c;
    if (7 < *(uint *)(local_6c + 10)) {
      psStack_98 = *(short **)local_6c;
    }
    uStack_44 = 7;
    uStack_48 = 0;
    uStack_58 = (uint)uStack_58._2_2_ << 0x10;
    psVar5 = psStack_98;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    uStack_94 = (int)psVar5 - (int)(psStack_98 + 1) >> 1;
    FUN_00402160();
    puStack_10 = (undefined1 *)0x2;
    if (*(int *)(psVar4 + 8) != 0) {
      uStack_94 = 2;
      psStack_98 = (short *)&DAT_00c225d0;
      FUN_00404300();
      uStack_94 = 0x34;
      psStack_98 = (short *)0x607742;
      FUN_00585620();
      psStack_98 = (short *)0x607749;
      FUN_00585330();
      uStack_94 = 0x607757;
      FUN_004068f0();
      uStack_94 = 0xffffffff;
      psStack_98 = (short *)0x0;
      puStack_10._0_1_ = 3;
      FUN_004041f0();
      puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,2);
      if (7 < uStack_28) {
        uStack_94 = uStack_3c;
        psStack_98 = (short *)0x607786;
        FUN_0089120c();
      }
      uStack_94 = 1;
      psStack_98 = (short *)&DAT_00c26458;
      FUN_00404300();
    }
    uVar2 = *(undefined4 *)(psVar4 + 8);
    iVar6 = *(int *)(in_ECX + 0x118);
    *(undefined4 *)(iVar6 + 0x26c) = 0;
    *(undefined4 *)(iVar6 + 0x274) = 0;
    *(undefined1 *)(iVar6 + 0x269) = 0;
    *(undefined4 *)(iVar6 + 0x270) = uVar2;
    uStack_94 = 0x6077cd;
    (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
    puStack_64 = &stack0xffffff54;
    FUN_00412df0();
    puStack_10._0_1_ = 4;
    uStack_78 = 0x1a;
    iVar6 = FUN_00585620();
    FUN_005740f0(&uStack_78);
    if (local_74 == *(int *)(iVar6 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puVar7 = (undefined4 *)(local_74 + 0x10);
    if (7 < *(uint *)(local_74 + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    puStack_10._0_1_ = 2;
    uStack_94 = FUN_00424c80(puVar7);
    puStack_10._0_1_ = 5;
    psStack_98 = (short *)0x607852;
    FUN_00757800();
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,2);
    if (7 < uStack_28) {
      uStack_94 = uStack_3c;
      psStack_98 = (short *)0x60786b;
      FUN_0089120c();
    }
    uStack_94 = 0x60787e;
    (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
    uStack_94 = *(uint *)(psVar4 + 2);
    psStack_98 = (short *)0x0;
    (**(code **)(**(int **)(in_ECX + 0x118) + 0x1ac))();
    (**(code **)(**(int **)(in_ECX + 0x118) + 200))();
    FUN_00757800();
    (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
    if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xcc) != 0) {
      FUN_006438f0();
    }
    uVar9 = 0;
    uStack_78 = *(int *)(psVar4 + 0xe) - *(int *)(psVar4 + 0xc) >> 3;
    if (uStack_78 != 0) {
      do {
        iStack_7c = uVar9 * 8;
        if ((DAT_00f8d9a8 & 1) == 0) {
          DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
          uStack_24._0_1_ = 6;
          FUN_00523540();
          uStack_24._0_1_ = 7;
          FUN_00521080();
          _atexit((_func_4879 *)&LAB_00bccc50);
          uStack_24 = CONCAT31(uStack_24._1_3_,2);
        }
        FUN_008438c0();
        if ((local_74 != DAT_00f8d9b0) &&
           (puVar7 = *(undefined4 **)(local_74 + 0x10), puVar7 != (undefined4 *)0x0)) {
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            uStack_24._0_1_ = 8;
            FUN_004e1590();
            _atexit((_func_4879 *)&LAB_00bccc80);
            uStack_24 = CONCAT31(uStack_24._1_3_,2);
          }
          iStack_8c = 0;
          if (DAT_00f94300 != -0x16f8) {
            iStack_8c = FUN_00508f90();
          }
          if ((*(int *)(*(int *)(in_ECX + 0xf4) + 0xcc) == 0) ||
             (piVar8 = (int *)FUN_00412c70(), piVar8 == (int *)0x0)) {
LAB_00607a30:
            piVar8 = (int *)0x0;
          }
          else {
            iVar6 = (**(code **)(*piVar8 + 4))();
            if (iVar6 != 0x12d) {
              MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
              goto LAB_00607a30;
            }
          }
          (**(code **)(*(int *)piVar8[0x92] + 0x19c))(*puVar7,0xffffffff);
          if (iStack_8c < *(int *)(iStack_7c + 4 + *(int *)(unaff_ESI + 0x18))) {
            iVar6 = -0x10000;
          }
          else {
            iVar6 = -1;
          }
          piVar8[0x55] = iVar6;
          *(int *)(piVar8[0x93] + 0x154) = iVar6;
          FUN_00757710();
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            uStack_24._0_1_ = 9;
            FUN_00584c40();
            _atexit((_func_4879 *)&LAB_00bcf390);
            uStack_24 = CONCAT31(uStack_24._1_3_,2);
          }
          iStack_7c = 0x17;
          FUN_005740f0();
          if (local_70 == DAT_00fe5ac8) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          FUN_0040e460();
          uStack_24._0_1_ = 10;
          FUN_00757800();
          uStack_24 = CONCAT31(uStack_24._1_3_,2);
          if (7 < uStack_3c) {
            FUN_0089120c();
          }
          uStack_50 = uStack_50 & 0xffff0000;
          uStack_3c = 7;
          *(undefined4 *)(in_ECX + 0x128) = 1;
          iStack_8c = iStack_8c / *(int *)(uVar9 * 8 + 4 + *(int *)(unaff_ESI + 0x18));
          uStack_40 = 0;
          if (*(int *)(in_ECX + 0x124) < iStack_8c) {
            iStack_8c = *(int *)(in_ECX + 0x124);
          }
          *(int *)(in_ECX + 0x124) = iStack_8c;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uStack_78);
    }
    FUN_00749920();
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
    uStack_24 = 0xffffffff;
    if (7 < uStack_58) {
      FUN_0089120c();
    }
    uStack_58 = 7;
    uStack_5c = 0;
    local_6c = (short *)((uint)local_6c & 0xffff0000);
  }
  (**(code **)(**(int **)(in_ECX + 0x104) + 0x90))();
  ExceptionList = pvStack_30;
  __security_check_cookie(uStack_38 ^ (uint)&psStack_98);
  return;
}

