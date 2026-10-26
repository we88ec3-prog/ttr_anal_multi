
void FUN_005ccd30(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int unaff_EDI;
  int aiStack_324 [2];
  undefined4 uStack_31c;
  undefined *puStack_318;
  wchar_t *pwStack_314;
  undefined8 uStack_310;
  undefined1 auStack_2f8 [36];
  float fStack_2d4;
  float fStack_2d0;
  int iStack_2cc;
  int *piStack_2c8;
  int iStack_2c4;
  uint uStack_2b0;
  uint uStack_2ac;
  uint uStack_2a4;
  undefined4 uStack_294;
  uint uStack_290;
  undefined1 auStack_28c [520];
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  puStack_48 = &LAB_0093f59a;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_2f8;
  ExceptionList = &local_4c;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_44 = 0;
    FUN_004dec90();
    uStack_310 = (double)CONCAT44(0x5ccd99,(undefined4)uStack_310);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_44 = 0xffffffff;
  if ((DAT_00fba7a4 != (int *)0x0) && (iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar3 != 0)) {
    piStack_2c8 = (int *)(uint)*(ushort *)(iVar3 + 0x88);
    iVar8 = *(int *)(iVar3 + 0x3dc);
    iStack_2cc = *(int *)(iVar3 + 0x3d8);
    iStack_2c4 = iVar8 - *(int *)(iVar3 + 0x3e0);
    fStack_2d0 = 0.0;
    if (iStack_2c4 != 0) {
      fStack_2d0 = (float)(iStack_2cc - *(int *)(iVar3 + 0x3e0)) / (float)iStack_2c4;
    }
    if ((*(int *)(unaff_EDI + 0x374) != iStack_2cc) || (*(int *)(unaff_EDI + 0x378) != iVar8)) {
      if ((fStack_2d0 < 0.0) || (100.0 < fStack_2d0)) {
        uStack_310 = (double)CONCAT44(0x5cceb6,(undefined4)uStack_310);
        (**(code **)(**(int **)(unaff_EDI + 0x2e4) + 0x90))();
        uStack_310 = 4.611587268266941e-305;
        pwStack_314 = L"ᱨ쀱栀쥘À钍谤";
        FUN_005d0d60();
        pwStack_314 = L" - ";
        puStack_318 = &DAT_00c0c958;
        uStack_31c = 0x5ccee2;
        FUN_005d0d60();
      }
      else {
        uStack_310 = (double)CONCAT44(0x5cce49,(undefined4)uStack_310);
        (**(code **)(**(int **)(unaff_EDI + 0x2e4) + 0x90))();
        uStack_310 = (double)(fStack_2d4 * 100.0);
        pwStack_314 = L"%.1f";
        puStack_318 = (undefined *)0x5cce6a;
        FUN_005d0d60();
        uStack_310 = (double)CONCAT44(0x5cce78,(undefined4)uStack_310);
        puVar4 = (undefined4 *)FUN_00412df0();
        if (7 < (uint)puVar4[5]) {
          puVar4 = (undefined4 *)*puVar4;
        }
        uStack_310 = (double)CONCAT44(puVar4,&DAT_00c0c958);
        pwStack_314 = L"쒃贈⑌\xe844햢\xfff2璋㠤䇫辋ˤ";
        FUN_005d0d60();
        uStack_310 = (double)CONCAT44(0x5cce9e,(undefined4)uStack_310);
        FUN_004fa440();
      }
      uStack_310 = (double)CONCAT44(0x5ccef0,(undefined4)uStack_310);
      FUN_00412df0();
      puStack_48 = (undefined1 *)0x1;
      piStack_2c8 = aiStack_324;
      FUN_005d0d80(auStack_28c);
      FUN_0040eff0(*(undefined4 *)(unaff_EDI + 0x2e4));
      puStack_48 = (undefined1 *)0xffffffff;
      if (7 < uStack_2b0) {
        uStack_310 = (double)CONCAT44(iStack_2c4,0x5ccf4b);
        FUN_0089120c();
      }
      pcVar2 = *(code **)(**(int **)(unaff_EDI + 0x2e4) + 0x128);
      (*(int **)(unaff_EDI + 0x2e4))[0x34] = (int)fStack_2d4;
      uStack_310 = (double)CONCAT44(0x5ccf6c,(undefined4)uStack_310);
      (*pcVar2)();
      uStack_310 = (double)CONCAT44(0x5ccf7c,(undefined4)uStack_310);
      (**(code **)(**(int **)(unaff_EDI + 0x2e4) + 200))();
      *(int *)(unaff_EDI + 0x374) = iStack_2cc;
      *(int *)(unaff_EDI + 0x378) = iVar8;
    }
    iVar3 = FUN_00404ba0();
    if (((uint)piStack_2c8 & 0xffff) < 10) {
      uVar7 = *(int *)(iVar3 + 0x6924) + ((uint)piStack_2c8 & 0xffff) * 0x210;
      uVar7 = -(uint)(*(int *)(uVar7 + 0x5c) != 0) & uVar7;
    }
    else {
      uVar7 = 0;
    }
    iStack_2cc = 0;
    if (uVar7 != 0) {
      iStack_2cc = *(int *)(uVar7 + 0xdc);
    }
    iVar3 = iStack_2cc;
    if (iStack_2cc != *(int *)(unaff_EDI + 0x350)) {
      iVar8 = -0x1b2483;
      if (99 < iStack_2cc) {
        iVar8 = -0xaf00;
      }
      if (*(int *)(unaff_EDI + 0x2f4) != iVar8) {
        piStack_2c8 = *(int **)(*(int *)(unaff_EDI + 0x2ec) + 0x94);
        if ((piStack_2c8 != (int *)0x0) &&
           (iVar5 = (**(code **)(*piStack_2c8 + 4))(), iVar5 == 0xbf6c)) {
          piStack_2c8[3] = iVar8;
        }
        *(int *)(*(int *)(unaff_EDI + 0x2f0) + 0x154) = iVar8;
        (**(code **)(**(int **)(unaff_EDI + 0x2f0) + 200))();
        *(int *)(*(int *)(unaff_EDI + 0xf0) + 0x154) = iVar8;
        *(int *)(unaff_EDI + 0x2f4) = iVar8;
      }
      FUN_0040ef80();
      local_44 = 2;
      uStack_310 = (double)CONCAT44(0x5cd06c,(undefined4)uStack_310);
      FUN_00757800();
      local_44 = 0xffffffff;
      if (7 < uStack_2ac) {
        uStack_310 = (double)CONCAT44(0x5cd088,(undefined4)uStack_310);
        FUN_0089120c();
      }
      (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
      pcVar2 = *(code **)(**(int **)(unaff_EDI + 0x2e8) + 0x128);
      (*(int **)(unaff_EDI + 0x2e8))[0x34] = (int)((float)iStack_2cc / 100.0);
      (*pcVar2)();
      (**(code **)(**(int **)(unaff_EDI + 0x2e8) + 200))();
      *(int *)(unaff_EDI + 0x350) = iVar3;
    }
    piVar6 = (int *)FUN_0040f060();
    sVar1 = *(short *)(*piVar6 + 0x5eb4);
    if (*(int *)(unaff_EDI + 0x36c) != (int)sVar1) {
      FUN_00412df0();
      local_44 = 3;
      FUN_00757710();
      local_44 = 0xffffffff;
      if (7 < uStack_2ac) {
        uStack_310 = (double)CONCAT44(0x5cd136,(undefined4)uStack_310);
        FUN_0089120c();
      }
      (**(code **)(**(int **)(unaff_EDI + 0xec) + 200))();
      *(int *)(unaff_EDI + 0x36c) = (int)sVar1;
    }
    iVar3 = FUN_00404ba0();
    iVar3 = *(int *)(iVar3 + 0x6864);
    if (*(int *)(unaff_EDI + 0x370) != iVar3) {
      FUN_00412df0();
      local_44 = 4;
      FUN_00757710();
      local_44 = 0xffffffff;
      if (7 < uStack_290) {
        uStack_310 = (double)CONCAT44(0x5cd1b1,(undefined4)uStack_310);
        FUN_0089120c();
      }
      uStack_2a4 = uStack_2a4 & 0xffff0000;
      uStack_290 = 7;
      uStack_294 = 0;
      (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))();
      *(int *)(unaff_EDI + 0x370) = iVar3;
    }
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_2f8);
  return;
}

