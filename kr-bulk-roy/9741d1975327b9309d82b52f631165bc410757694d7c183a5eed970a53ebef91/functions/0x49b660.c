
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b660(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  float in_XMM0_Da;
  undefined1 auStack_f8 [44];
  undefined4 uStack_cc;
  float fStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 local_b8 [8];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  
  uStack_44 = 0xffffffff;
  puStack_48 = &LAB_00937002;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_f8;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff00;
  ExceptionList = &local_4c;
  *(undefined4 *)(unaff_EDI + 4) = 0;
  if (0 < *(int *)(unaff_EDI + 8)) {
    if ((_DAT_00fe48d8 & 1) == 0) {
      _DAT_00fe48d8 = _DAT_00fe48d8 | 1;
      FUN_0049b310(uVar2);
    }
    FUN_0049bbc0();
  }
  if (1 < *(int *)(unaff_EDI + 8)) {
    FUN_0049bbc0();
    FUN_0049bbc0();
    if ((LPCWSTR)(DAT_00fb1318 + 0xbf95) != (LPCWSTR)0x0) {
      WideCharToMultiByte(0,0,(LPCWSTR)(DAT_00fb1318 + 0xbf95),-1,&DAT_00fdf710,0x400,(LPCSTR)0x0,
                          (LPBOOL)0x0);
    }
    FUN_0049bbc0();
    local_90 = 0;
    local_8c = 0;
    local_88 = 0;
    local_94 = 0x10004000;
    (**(code **)(*DAT_00fb941c + 0x5c))(DAT_00fb941c,&local_94,local_b8);
    FUN_0049bbc0();
    uVar1 = DAT_00fb9418;
    (**(code **)(*DAT_00fb9414 + 0x10))(DAT_00fb9414);
    uStack_cc = uVar1;
    FUN_0049bbc0();
    FUN_0049bbc0();
    if ((DAT_00fba7a4 != (int *)0x0) && (iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar3 != 0))
    {
      piVar4 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
      puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x4c))();
      uStack_c4 = *puVar5;
      uStack_c0 = puVar5[1];
      uStack_bc = puVar5[2];
      iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      fStack_c8 = (float)CONCAT31(fStack_c8._1_3_,*(undefined1 *)(iVar3 + 0xb0));
      FUN_00444a90();
      fStack_c8 = in_XMM0_Da * 57.295776;
      FUN_0049bbc0();
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_44 = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_44 = 0xffffffff;
    }
    uStack_c4 = *(undefined4 *)(DAT_00fb76e8 + 0xc);
    uStack_c0 = *(undefined4 *)(DAT_00fb76e8 + 0x10);
    uStack_bc = *(undefined4 *)(DAT_00fb76e8 + 0x14);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_44 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_44 = 0xffffffff;
    }
    uStack_ac = *(undefined4 *)(DAT_00fb76e8 + 0xc);
    uStack_a8 = *(undefined4 *)(DAT_00fb76e8 + 0x10);
    uStack_a4 = *(undefined4 *)(DAT_00fb76e8 + 0x14);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_44 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_44 = 0xffffffff;
    }
    uStack_a0 = *(undefined4 *)(DAT_00fb76e8 + 0xc);
    uStack_9c = *(undefined4 *)(DAT_00fb76e8 + 0x10);
    uStack_98 = *(undefined4 *)(DAT_00fb76e8 + 0x14);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_44 = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_44 = 0xffffffff;
    }
    fStack_c8 = *(float *)(DAT_00fb76e8 + 0x20);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_44 = 4;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_44 = 0xffffffff;
    }
    uStack_b0 = *(undefined4 *)(DAT_00fb76e8 + 0x18);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_44 = 5;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_44 = 0xffffffff;
    }
    uStack_cc = *(undefined4 *)(DAT_00fb76e8 + 0x24);
    FUN_0049bbc0();
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_44 = 6;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      uStack_44 = 0xffffffff;
    }
    FUN_0049bbc0();
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_f8);
  return;
}

