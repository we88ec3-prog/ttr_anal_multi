
void FUN_006767d0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int in_ECX;
  int unaff_ESI;
  undefined *puStack_98;
  undefined4 *puStack_94;
  int iStack_8c;
  uint uVar7;
  int iStack_7c;
  uint uStack_78;
  int local_74;
  int local_70;
  undefined4 *local_6c;
  int local_68;
  undefined1 *puStack_64;
  undefined4 uStack_5c;
  uint uStack_58;
  uint uStack_50;
  uint uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  void *pvStack_30;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945f13;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_7c;
  ExceptionList = &local_14;
  if ((DAT_00fe1de0 & 1) == 0) {
    DAT_00fe1de0 = DAT_00fe1de0 | 1;
    local_c = 0;
    FUN_00519060();
    puStack_94 = (undefined4 *)0x676831;
    _atexit(FUN_00bcef60);
  }
  local_c = 0xffffffff;
  local_74 = *(undefined4 *)(in_ECX + 0x1c8);
  puStack_94 = (undefined4 *)0x676860;
  FUN_00519680();
  if (local_70 == DAT_00fe1de8) {
    local_6c = (undefined4 *)0x0;
  }
  else {
    local_6c = (undefined4 *)(local_70 + 0x10);
  }
  puVar2 = local_6c;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    puStack_94 = (undefined4 *)0x6768a5;
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_c = 0xffffffff;
  }
  local_74 = *(int *)(in_ECX + 0x1c8);
  puStack_94 = (undefined4 *)0x6768d0;
  FUN_008438c0();
  if (local_70 == DAT_00f8d91c) {
    local_68 = 0;
  }
  else {
    local_68 = *(int *)(local_70 + 0x10);
  }
  uStack_78 = uStack_78 & 0xffffff;
  *(undefined4 *)(in_ECX + 0x1cc) = 0xff;
  if ((puVar2 == (undefined4 *)0x0) || (local_68 == 0)) {
LAB_00676e9b:
    FUN_00749d00();
    puStack_94 = (undefined4 *)0x676ebd;
    (**(code **)(**(int **)(in_ECX + 0x134) + 0x94))();
    puStack_94 = (undefined4 *)0x676ed3;
    FUN_00757710();
    puStack_94 = (undefined4 *)0x676ee3;
    (**(code **)(**(int **)(in_ECX + 0x120) + 200))();
    puStack_94 = (undefined4 *)0xffffffff;
    puStack_98 = (undefined *)0x0;
    (**(code **)(**(int **)(in_ECX + 0x180) + 0x1ac))();
    (**(code **)(**(int **)(in_ECX + 0x180) + 200))();
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0x11c) + 200))();
    if (*(int *)(*(int *)(in_ECX + 0x114) + 0xcc) != 0) {
      FUN_006438f0();
    }
    FUN_00749920();
    (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
  }
  else {
    if (puVar2[5] != 0) {
      FUN_0040f930();
      iVar4 = FUN_005000a0();
      if (iVar4 == 0) goto LAB_00676e9b;
    }
    if (puVar2[3] == 100) {
      FUN_00749d00();
    }
    else {
      FUN_00749d00();
      puStack_94 = (undefined4 *)0x676953;
      FUN_007597b0();
    }
    puStack_94 = (undefined4 *)0x676973;
    (**(code **)(**(int **)(in_ECX + 0x134) + 0x94))();
    puStack_94 = (undefined4 *)0x676983;
    (**(code **)(**(int **)(in_ECX + 0x134) + 200))();
    puStack_94 = local_6c;
    if (7 < (uint)local_6c[5]) {
      puStack_94 = (undefined4 *)*local_6c;
    }
    puStack_98 = (undefined *)0x676999;
    FUN_00402250();
    puStack_10 = (undefined1 *)0x2;
    if (puVar2[4] != 0) {
      puStack_94 = (undefined4 *)0x2;
      puStack_98 = &DAT_00c225d0;
      FUN_00404300();
      puStack_94 = (undefined4 *)0x34;
      puStack_98 = (undefined *)0x6769c1;
      FUN_00585620();
      puStack_98 = (undefined *)0x6769c8;
      FUN_00585330();
      puStack_94 = (undefined4 *)0x6769d6;
      FUN_004068f0();
      puStack_94 = (undefined4 *)0xffffffff;
      puStack_98 = (undefined *)0x0;
      puStack_10._0_1_ = 3;
      FUN_004041f0();
      puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,2);
      puStack_94 = (undefined4 *)0x6769fb;
      FUN_004fa440();
      puStack_94 = (undefined4 *)0x1;
      puStack_98 = &DAT_00c26458;
      FUN_00404300();
    }
    uVar1 = puVar2[4];
    iVar4 = *(int *)(in_ECX + 0x180);
    puStack_64 = &stack0xffffff54;
    *(undefined1 *)(iVar4 + 0x269) = 0;
    *(undefined4 *)(iVar4 + 0x26c) = 0;
    *(undefined4 *)(iVar4 + 0x270) = uVar1;
    *(undefined4 *)(iVar4 + 0x274) = 0;
    FUN_00412df0();
    puStack_10._0_1_ = 4;
    uStack_78 = 0x1a;
    iVar4 = FUN_00585620();
    FUN_005740f0(&uStack_78);
    if (local_74 == *(int *)(iVar4 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puVar5 = (undefined4 *)(local_74 + 0x10);
    if (7 < *(uint *)(local_74 + 0x24)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    puStack_10._0_1_ = 2;
    puStack_94 = (undefined4 *)FUN_00424c80(puVar5);
    puStack_10._0_1_ = 5;
    puStack_98 = (undefined *)0x676ab4;
    FUN_00757800();
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,2);
    if (7 < uStack_44) {
      puStack_94 = (undefined4 *)uStack_58;
      puStack_98 = (undefined *)0x676acd;
      FUN_0089120c();
    }
    puStack_94 = (undefined4 *)0x676ae0;
    (**(code **)(**(int **)(in_ECX + 0x120) + 200))();
    puStack_94 = (undefined4 *)puVar2[1];
    puStack_98 = (undefined *)0x0;
    (**(code **)(**(int **)(in_ECX + 0x180) + 0x1ac))();
    (**(code **)(**(int **)(in_ECX + 0x180) + 200))();
    FUN_00757800();
    (**(code **)(**(int **)(in_ECX + 0x11c) + 200))();
    if (*(int *)(*(int *)(in_ECX + 0x114) + 0xcc) != 0) {
      FUN_006438f0();
    }
    uVar7 = 0;
    uStack_78 = (int)(puVar2[7] - puVar2[6]) >> 3;
    if (uStack_78 != 0) {
      do {
        iStack_7c = uVar7 * 8;
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
           (puVar2 = *(undefined4 **)(local_74 + 0x10), puVar2 != (undefined4 *)0x0)) {
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
          if ((*(int *)(*(int *)(in_ECX + 0x114) + 0xcc) == 0) ||
             (piVar6 = (int *)FUN_00412c70(), piVar6 == (int *)0x0)) {
LAB_00676c92:
            piVar6 = (int *)0x0;
          }
          else {
            iVar4 = (**(code **)(*piVar6 + 4))();
            if (iVar4 != 0x12d) {
              MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
              goto LAB_00676c92;
            }
          }
          (**(code **)(*(int *)piVar6[0x92] + 0x19c))(*puVar2,0xffffffff);
          if (iStack_8c < *(int *)(iStack_7c + 4 + *(int *)(unaff_ESI + 0x18))) {
            iVar4 = -0x10000;
          }
          else {
            iVar4 = -1;
          }
          piVar6[0x55] = iVar4;
          *(int *)(piVar6[0x93] + 0x154) = iVar4;
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
          if (7 < uStack_58) {
            FUN_0089120c();
          }
          local_6c = (undefined4 *)((uint)local_6c & 0xffff0000);
          uStack_58 = 7;
          *(undefined4 *)(in_ECX + 0x1d0) = 1;
          iStack_8c = iStack_8c / *(int *)(uVar7 * 8 + 4 + *(int *)(unaff_ESI + 0x18));
          uStack_5c = 0;
          if (*(int *)(in_ECX + 0x1cc) < iStack_8c) {
            iStack_8c = *(int *)(in_ECX + 0x1cc);
          }
          *(int *)(in_ECX + 0x1cc) = iStack_8c;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uStack_78);
    }
    FUN_00749920();
    (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
    uStack_24 = 0xffffffff;
    if (7 < uStack_3c) {
      FUN_0089120c();
    }
    uStack_3c = 7;
    uStack_40 = 0;
    uStack_50 = uStack_50 & 0xffff0000;
  }
  (**(code **)(**(int **)(in_ECX + 0x124) + 0x90))();
  ExceptionList = pvStack_30;
  __security_check_cookie(uStack_38 ^ (uint)&puStack_98);
  return;
}

