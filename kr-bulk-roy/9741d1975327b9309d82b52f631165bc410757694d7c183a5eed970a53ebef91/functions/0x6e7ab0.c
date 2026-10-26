
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e7ab0(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  undefined4 *puVar9;
  bool bVar10;
  float10 fVar11;
  undefined4 uVar12;
  float fVar13;
  undefined4 local_c4 [18];
  uint local_7c;
  int local_78;
  int *local_74;
  float local_70;
  undefined8 local_6c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_14;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  local_78 = *(int *)(iVar2 + 0x2c8);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar2 + 0x328);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (((cVar1 != '\0') || (cVar1 = FUN_006e00d0(), cVar1 != '\0')) ||
     (cVar1 = FUN_006e0140(), cVar1 == '\0')) {
    Sleep(10);
  }
  local_74 = (int *)FUN_006dfbe0();
  if (local_74 == (int *)0x0) {
    if (DAT_00fba7cc == 0) {
      iVar2 = FUN_00891268();
      if (iVar2 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar2 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    cVar1 = *(char *)(iVar2 + 0x328);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (cVar1 != '\0') {
      puVar3 = (undefined4 *)FUN_006ea4e0();
      puVar9 = local_c4;
      for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar9 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar9 = puVar9 + 1;
      }
      FUN_006e4f90(local_c4,0,0,1);
      if ((_DAT_00fe4b40 & 1) == 0) {
        _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
        FUN_006eb420();
      }
      if (DAT_00fe4b28 == 0 && DAT_00fe4b2c == 0) {
        FUN_006eb3c0();
      }
      else {
        local_7c = DAT_00fe4b28;
        local_78 = DAT_00fe4b2c;
      }
      local_6c = (double)CONCAT44((local_78 - _DAT_00fe4b3c) - (uint)(local_7c < _DAT_00fe4b38),
                                  local_7c - _DAT_00fe4b38);
      local_14 = (double)(longlong)local_6c / (double)_DAT_00fe4b20;
      if (DAT_00fba7cc == 0) {
        iVar2 = FUN_00891268();
        if (iVar2 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      iVar2 = DAT_00fba7cc;
      *(double *)(DAT_00fba7cc + 0x1358) = local_14;
      *(double *)(iVar2 + 0x1350) = local_14;
      *(undefined4 *)(iVar2 + 0x1378) = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    goto LAB_006e834f;
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar2 + 0x328);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 != '\0') {
    if (DAT_00fba7cc == 0) {
      iVar2 = FUN_00891268();
      if (iVar2 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    cVar1 = FUN_006e1060();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*local_74 + 0xc))();
      if (iVar2 < 0) {
        if (iVar2 == -0x7789f798) goto LAB_006e834f;
        cVar1 = FUN_006ea3d0();
        if (cVar1 != '\0') {
          piVar4 = (int *)FUN_006dfb80();
          FUN_006df6d0();
          puVar3 = (undefined4 *)FUN_006e03c0();
          (**(code **)(*piVar4 + 0x20))(piVar4,*puVar3);
          if (puVar3[2] != local_14._4_4_) {
            local_58 = 1;
            local_54 = 1;
            local_50 = 1;
            local_4c = 1;
            local_48 = 2;
            local_44 = 2;
            local_40 = 2;
            local_3c = 2;
            local_38 = 2;
            local_34 = 2;
            local_30 = 2;
            local_2c = 2;
            local_28 = 2;
            local_24 = 2;
            local_20 = 2;
            puVar3 = (undefined4 *)FUN_006ea4e0();
            local_c4[2] = local_14._4_4_;
            puVar9 = local_c4;
            for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar9 = *puVar3;
              puVar3 = puVar3 + 1;
              puVar9 = puVar9 + 1;
            }
            iVar2 = FUN_006e3830(local_c4,local_c4);
            if (iVar2 < 0) {
              FUN_006ea570();
              FUN_006e9ae0();
            }
            iVar2 = FUN_006e4f90(local_c4,0,0,0,0);
            if ((iVar2 < 0) && (iVar2 = FUN_006e2e20(), iVar2 < 0)) {
              FUN_006e9ae0();
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
            goto LAB_006e834f;
          }
        }
        iVar2 = FUN_006e6c20();
        if (iVar2 < 0) {
          if (iVar2 == -0x7789f798) goto LAB_006e834f;
          if ((iVar2 == -0x7ffbf6f8) || (iVar2 == -0x7ffbf6fd)) {
            FUN_006ea570();
            FUN_006e9ae0();
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          FUN_006df6d0();
          uVar5 = FUN_006e03c0();
          iVar2 = FUN_006e4f90(uVar5,0,1,0);
          if (iVar2 < 0) {
            FUN_006e9ae0();
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
        }
      }
      uVar12 = 0;
      uVar5 = FUN_006df6d0();
      FUN_006e10a0(uVar5,uVar12);
      iVar2 = FUN_006df6d0();
      FUN_006eb340();
      fVar11 = (float10)FUN_006eb510();
      *(double *)(iVar2 + 0x1358) = (double)fVar11;
      *(double *)(iVar2 + 0x1350) = (double)fVar11;
      *(undefined4 *)(iVar2 + 0x1378) = 0;
    }
  }
  local_70 = 0.0;
  if ((_DAT_00fe4b40 & 1) == 0) {
    _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
    FUN_006eb420();
  }
  iVar2 = DAT_00fe4b2c;
  uVar8 = DAT_00fe4b28;
  if (DAT_00fe4b28 == 0 && DAT_00fe4b2c == 0) {
    FUN_006eb3c0();
    iVar2 = local_6c._4_4_;
    uVar8 = (uint)local_6c;
  }
  local_6c = (double)CONCAT44((iVar2 - _DAT_00fe4b3c) - (uint)(uVar8 < _DAT_00fe4b38),
                              uVar8 - _DAT_00fe4b38);
  local_6c = (double)(longlong)local_6c / (double)_DAT_00fe4b20;
  if ((_DAT_00fe4b40 & 1) == 0) {
    _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
    FUN_006eb420();
  }
  FUN_006eb3c0();
  local_14 = (double)(longlong)local_14 / (double)_DAT_00fe4b20;
  if ((_DAT_00fe4b40 & 1) == 0) {
    _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
    FUN_006eb420();
  }
  FUN_006eb550(&local_6c,&local_14,&local_70);
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = DAT_00fba7cc;
  *(float *)(DAT_00fba7cc + 0x1378) = local_70 + *(float *)(DAT_00fba7cc + 0x1378);
  if (iVar2 == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      iVar2 = 0;
      DAT_00fba7cc = iVar2;
    }
    else {
      iVar2 = FUN_006df3d0();
      DAT_00fba7cc = iVar2;
    }
  }
  iVar6 = iVar2;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar6 = DAT_00fba7cc;
  }
  bVar10 = DAT_00d63d09 != '\0';
  *(double *)(iVar2 + 0x2a0) = local_6c;
  if (bVar10) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar6 = DAT_00fba7cc;
  }
  if (iVar6 == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      iVar6 = 0;
      DAT_00fba7cc = iVar6;
    }
    else {
      iVar6 = FUN_006df3d0();
      DAT_00fba7cc = iVar6;
    }
  }
  iVar2 = iVar6;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  bVar10 = DAT_00d63d09 != '\0';
  *(double *)(iVar6 + 0x2a8) = local_14;
  if (bVar10) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  FUN_006e0330(local_6c);
  FUN_006e87f0();
  FUN_006ea2b0();
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  piVar4 = local_74;
  if ((*(int *)(DAT_00fba7cc + 0x1370) != 0) &&
     (pcVar7 = (code *)FUN_006e1520(), piVar4 = local_74, pcVar7 != (code *)0x0)) {
    FUN_006df6d0();
    FUN_006e1720();
    (*pcVar7)(local_74);
    piVar4 = (int *)FUN_006dfbe0();
    if (piVar4 == (int *)0x0) goto LAB_006e834f;
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268();
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  if ((*(int *)(DAT_00fba7cc + 0x1374) != 0) && (cVar1 = FUN_006e1060(), cVar1 == '\0')) {
    iVar2 = FUN_006df6d0();
    local_70 = *(float *)(iVar2 + 0x1378);
    fVar13 = local_70;
    uVar5 = FUN_006df6d0();
    FUN_006e0990(uVar5,fVar13);
    iVar2 = FUN_006df6d0();
    *(undefined4 *)(iVar2 + 0x1378) = 0;
    FUN_006df6d0();
    pcVar7 = (code *)FUN_006e1560();
    if (pcVar7 != (code *)0x0) {
      FUN_006df6d0();
      FUN_006e1760();
      (*pcVar7)(piVar4,local_70);
      piVar4 = (int *)FUN_006dfbe0();
      if (piVar4 == (int *)0x0) goto LAB_006e834f;
    }
    if (DAT_00fba7d8 != 0) {
      DAT_00fba7d8 = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    FUN_006df6d0();
    pcVar7 = (code *)FUN_006e15a0();
    if (pcVar7 != (code *)0x0) {
      FUN_006df6d0();
      FUN_006e17a0();
      (*pcVar7)(piVar4);
      piVar4 = (int *)FUN_006dfbe0();
      if (piVar4 == (int *)0x0) goto LAB_006e834f;
    }
    if (DAT_00fba7dc != 0) {
      DAT_00fba7dc = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar2 = (**(code **)(*piVar4 + 0x44))(piVar4,0,0,0);
    if ((iVar2 < 0) && ((iVar2 == -0x7789f798 || (iVar2 == -0x7789f7d9)))) {
      uVar12 = 1;
      uVar5 = FUN_006df6d0();
      FUN_006e10a0(uVar5,uVar12);
    }
  }
  iVar2 = local_78 + 1;
  if (DAT_00fba7cc == 0) {
    iVar6 = FUN_00891268();
    if (iVar6 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar6 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar10 = DAT_00d63d09 != '\0';
  *(int *)(iVar6 + 0x2c8) = iVar2;
  if (bVar10) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
LAB_006e834f:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

