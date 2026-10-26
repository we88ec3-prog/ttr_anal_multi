
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048c6e0(uint param_1)

{
  code *pcVar1;
  uint uVar2;
  short sVar3;
  char cVar4;
  LPCWSTR lpString;
  HWND hWnd;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  void *_ArgList;
  uintptr_t uVar8;
  int iVar9;
  int *piVar10;
  undefined4 **ppuVar11;
  undefined4 *puStack_6c;
  undefined4 *local_68;
  undefined4 *puStack_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined4 *puStack_40;
  uint uStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00949fb2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_6c;
  ExceptionList = &local_14;
  local_5c = param_1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
  }
  local_c = 0xffffffff;
  local_60 = 0x199;
  FUN_005740f0();
  if (local_68 != DAT_00fe5b10) {
    lpString = (LPCWSTR)(local_68 + 4);
    if (7 < (uint)local_68[9]) {
      lpString = *(LPCWSTR *)lpString;
    }
    hWnd = (HWND)FUN_006dfd60();
    SetWindowTextW(hWnd,lpString);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 1;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c = 0xffffffff;
    }
    (**(code **)(*DAT_00fb7b78 + 4))();
    (**(code **)(*DAT_00fb7b78 + 0xc))();
    _DAT_00fb7bac = DAT_00fb7bc0;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 2;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c = 0xffffffff;
    }
    _DAT_00fb7bb8 = 10;
    _DAT_00fb7bbc = 0x1e;
    DAT_00fb7bc0 = 0x2d0;
    uVar5 = FUN_006dfd00();
    uVar6 = FUN_006dfd60();
    if ((_DAT_00fc18dc & 1) == 0) {
      _DAT_00fc18dc = _DAT_00fc18dc | 1;
      _DAT_00fc18f0 = 0;
      DAT_00fc18f4 = 0;
      _DAT_00fc18f8 = 0x1ff0000;
      _atexit((_func_4879 *)&DAT_00bce270);
    }
    _DAT_00fc18e0 = uVar5;
    _DAT_00fc18e4 = uVar6;
    puVar7 = (undefined4 *)FUN_00891268();
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = FunctorArg0Inst<void,CSplashScreen>::vftable;
      puVar7[1] = &DAT_00fc18e0;
      puVar7[2] = FUN_00558eb0;
    }
    DAT_00fc18f4 = FUN_004fb770();
    if ((DAT_00fb75c0 & 1) == 0) {
      DAT_00fb75c0 = DAT_00fb75c0 | 1;
      local_c = 3;
      FUN_0081e5f0();
      _atexit((_func_4879 *)&LAB_00bcd250);
      local_c = 0xffffffff;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 4;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fbaaf8 = DAT_00fb911d;
    if ((_DAT_00fdf3d8 & 1) == 0) {
      _DAT_00fdf3d8 = _DAT_00fdf3d8 | 1;
      DAT_00fdf3dc = 0;
      DAT_00fdf3e0 = 0;
      _DAT_00fdf3e4 = 0;
      _atexit((_func_4879 *)&LAB_00bce280);
    }
    FUN_0049eb20();
    uVar2 = DAT_00fb8828 & 1;
    piVar10 = *(int **)(*(int *)(*(int *)(local_5c + 0xbfdc) + 8) + 4);
    piVar10[1] = 1;
    if (uVar2 == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 5;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    (**(code **)(*piVar10 + 4))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      puStack_10 = (undefined1 *)0x6;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      puStack_10 = (undefined1 *)0x7;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_006f4a50();
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      puStack_10 = (undefined1 *)0x8;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_006f4a50();
    if ((DAT_00fb761c & 1) == 0) {
      DAT_00fb761c = DAT_00fb761c | 1;
      puStack_10 = (undefined1 *)0x9;
      FUN_0054e750();
      _atexit((_func_4879 *)&LAB_00bcd260);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      puStack_10 = (undefined1 *)0xa;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    _DAT_00fbaae0 = 0;
    FUN_004ccdd0();
    *(int *)(DAT_00fbaae8 + 4) = DAT_00fbaae8;
    *(int *)DAT_00fbaae8 = DAT_00fbaae8;
    *(int *)(DAT_00fbaae8 + 8) = DAT_00fbaae8;
    _DAT_00fbaaec = 0;
    FUN_0082bb00();
    if ((DAT_00fd8ef8 & 1) == 0) {
      DAT_00fd8ef8 = DAT_00fd8ef8 | 1;
      puStack_10 = (undefined1 *)0xb;
      FUN_00498280();
      _atexit(FUN_00bcddd0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0053e3f0();
    _ArgList = (void *)FUN_00489ee0();
    uVar8 = __beginthread(FUN_004e7430,0,_ArgList);
    uVar2 = DAT_00fc0e40 & 1;
    *(uintptr_t *)((int)_ArgList + 0x44) = uVar8;
    if (uVar2 == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      puStack_10 = (undefined1 *)0xc;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      puStack_10 = (undefined1 *)0xd;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00551030();
    if ((DAT_00fc0e40 & 1) == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      puStack_10 = (undefined1 *)0xe;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fe1e1c & 1) == 0) {
      DAT_00fe1e1c = DAT_00fe1e1c | 1;
      puStack_10 = (undefined1 *)0xf;
      FUN_007c30c0();
      _atexit(FUN_00bcf1b0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_007c2880();
    FUN_007a3c00();
    FUN_007aaac0();
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10 = (undefined1 *)0x10;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    DAT_00fba82c = FUN_0080ae20();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10 = (undefined1 *)0x11;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    puStack_6c = DAT_00fb90bc;
    if ((DAT_00fd93f0 & 1) == 0) {
      DAT_00fd93f0 = DAT_00fd93f0 | 1;
      puStack_10 = (undefined1 *)0x12;
      FUN_007ab4e0();
      _atexit((_func_4879 *)&LAB_00bce6a0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    _DAT_00fd93dc = (float)puStack_6c + (float)puStack_6c;
    iVar9 = FUN_00891268();
    puStack_10 = (undefined1 *)0x13;
    if (iVar9 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = FUN_00797a50();
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      puStack_10 = (undefined1 *)0x14;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    DAT_00fb76e8 = iVar9;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10 = (undefined1 *)0x15;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    uVar2 = DAT_00fb8828 & 1;
    *(undefined4 *)(iVar9 + 0x28) = DAT_00fb90a4;
    if (uVar2 == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10 = (undefined1 *)0x16;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    uVar2 = DAT_00fb8828 & 1;
    *(undefined4 *)(iVar9 + 0x18) = DAT_00fb9094;
    *(undefined4 *)(iVar9 + 0xcc) = 0;
    if (uVar2 == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10 = (undefined1 *)0x17;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    uVar2 = DAT_00fdf6dc & 1;
    *(undefined4 *)(iVar9 + 0x24) = DAT_00fb907c;
    *(undefined4 *)(iVar9 + 0x20) = 0;
    *(undefined4 *)(iVar9 + 0xcc) = 0;
    if (uVar2 == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      puStack_10 = (undefined1 *)0x18;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
    }
    puStack_10 = (undefined1 *)0xffffffff;
    if ((_DAT_00fb79ec & 1) == 0) {
      _DAT_00fb79ec = _DAT_00fb79ec | 1;
      DAT_00fb79f0 = CCheckPointMgr::vftable;
      DAT_00fb79f4 = 0;
      DAT_00fb79f8 = 0;
      DAT_00fb79fc = 0;
      DAT_00fb7a04 = 1;
      _atexit((_func_4879 *)&LAB_00bcd270);
    }
    piVar10 = (int *)FUN_0048a2e0();
    (**(code **)(*piVar10 + 8))();
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      puStack_10 = (undefined1 *)0x19;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fdf3ec & 1) == 0) {
      DAT_00fdf3ec = DAT_00fdf3ec | 1;
      puStack_10 = (undefined1 *)0x1a;
      FUN_006d1da0();
      _atexit((_func_4879 *)&LAB_00bce330);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00507280();
    if ((_DAT_00fc1690 & 1) == 0) {
      _DAT_00fc1690 = _DAT_00fc1690 | 1;
      _atexit((_func_4879 *)&DAT_00bce690);
    }
    FUN_007ac7e0();
    if ((DAT_00fc0e40 & 1) == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      puStack_10 = (undefined1 *)0x1b;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00540b10();
    if ((DAT_00fc0e40 & 1) == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      puStack_10 = (undefined1 *)0x1c;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_005413f0();
    if ((DAT_00fc1094 & 1) == 0) {
      DAT_00fc1094 = DAT_00fc1094 | 1;
      puStack_10 = (undefined1 *)0x1d;
      FUN_0052f7e0();
      _atexit((_func_4879 *)&LAB_00bcdc80);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00530890();
    FUN_0052fc50();
    if ((DAT_00fc0dc4 & 1) == 0) {
      DAT_00fc0dc4 = DAT_00fc0dc4 | 1;
      puStack_10 = (undefined1 *)0x1e;
      FUN_0052a3b0();
      _atexit(FUN_00bcd980);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00529d50();
    if ((DAT_00fab230 & 1) == 0) {
      DAT_00fab230 = DAT_00fab230 | 1;
      puStack_10 = (undefined1 *)0x1f;
      FUN_005292c0();
      _atexit(FUN_00bcce40);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00528d00();
    if ((DAT_00fb11a8 & 1) == 0) {
      DAT_00fb11a8 = DAT_00fb11a8 | 1;
      puStack_10 = (undefined1 *)0x20;
      FUN_00813890();
      _atexit((_func_4879 *)&LAB_00bccec0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_008170e0();
    FUN_00813b60();
    if ((DAT_00fab278 & 1) == 0) {
      DAT_00fab278 = DAT_00fab278 | 1;
      puStack_10 = (undefined1 *)0x21;
      FUN_00817da0();
      _atexit((_func_4879 *)&LAB_00bcced0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00402a70("Table/Skill/SkillMatrix.xml",0x1b);
    FUN_008180c0();
    FUN_00819280();
    if ((DAT_00fc7f08 & 1) == 0) {
      DAT_00fc7f08 = DAT_00fc7f08 | 1;
      puStack_10 = (undefined1 *)0x22;
      FUN_004d3590();
      _atexit(FUN_00bce530);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_004d3610();
    *(int *)(DAT_00fc7f10 + 4) = DAT_00fc7f10;
    *(int *)DAT_00fc7f10 = DAT_00fc7f10;
    *(int *)(DAT_00fc7f10 + 8) = DAT_00fc7f10;
    DAT_00fc7f14 = 0;
    FUN_004d2ff0();
    if ((DAT_00fc0dd8 & 1) == 0) {
      DAT_00fc0dd8 = DAT_00fc0dd8 | 1;
      puStack_10 = (undefined1 *)0x23;
      FUN_00484f20();
      _atexit((_func_4879 *)&LAB_00bcd9f0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00485200();
    FUN_00485470();
    FUN_0040f860();
    FUN_0081a3a0();
    if ((DAT_00fc16e8 & 1) == 0) {
      DAT_00fc16e8 = DAT_00fc16e8 | 1;
      puStack_10 = (undefined1 *)0x24;
      FUN_0082aa80();
      _atexit(FUN_00bce450);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0082a7b0();
    if ((DAT_00fbace4 & 1) == 0) {
      DAT_00fbace4 = DAT_00fbace4 | 1;
      puStack_10 = (undefined1 *)0x25;
      FUN_00825080();
      _atexit((_func_4879 *)&LAB_00bcd6d0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00825210();
    if ((DAT_00fd93f4 & 1) == 0) {
      DAT_00fd93f4 = DAT_00fd93f4 | 1;
      puStack_10 = (undefined1 *)0x26;
      FUN_00828c00();
      _atexit(FUN_00bcde40);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00827ec0();
    if ((_DAT_00fc16fc & 1) == 0) {
      _DAT_00fc16fc = _DAT_00fc16fc | 1;
      DAT_00fc1700 = 0;
      DAT_00fc1704 = 0;
      _DAT_00fc1708 = 0;
      _atexit((_func_4879 *)&LAB_00bce4c0);
    }
    FUN_0082b130();
    if ((DAT_00fb7a08 & 1) == 0) {
      DAT_00fb7a08 = DAT_00fb7a08 | 1;
      puStack_10 = (undefined1 *)0x27;
      FUN_0081ee80();
      _atexit(FUN_00bcd310);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0081eed0();
    if ((DAT_00fb7b58 & 1) == 0) {
      DAT_00fb7b58 = DAT_00fb7b58 | 1;
      puStack_10 = (undefined1 *)0x28;
      FUN_0081faa0();
      _atexit(FUN_00bcd450);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0081faf0();
    if ((DAT_00fb7324 & 1) == 0) {
      DAT_00fb7324 = DAT_00fb7324 | 1;
      puStack_10 = (undefined1 *)0x29;
      FUN_0081b920();
      _atexit((_func_4879 *)&LAB_00bcd080);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0081bd10();
    FUN_0081c760();
    if ((_DAT_00fc1aec & 1) == 0) {
      _DAT_00fc1aec = _DAT_00fc1aec | 1;
      DAT_00fc1af0 = 0;
      DAT_00fc1af4 = 0;
      _DAT_00fc1af8 = 0;
      _atexit((_func_4879 *)&LAB_00bcdd10);
    }
    timeGetTime();
    FUN_0052eb80();
    timeGetTime();
    if ((DAT_00fd9260 & 1) == 0) {
      DAT_00fd9260 = DAT_00fd9260 | 1;
      puStack_10 = (undefined1 *)0x2a;
      FUN_004c6790();
      _atexit(FUN_00bcdd60);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_004c62b0();
    if ((DAT_00fb93b8 & 1) == 0) {
      DAT_00fb93b8 = DAT_00fb93b8 | 1;
      puStack_10 = (undefined1 *)0x2b;
      FUN_00823720();
      _atexit(FUN_00bcd5a0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00822890();
    if ((DAT_00fc1710 & 1) == 0) {
      DAT_00fc1710 = DAT_00fc1710 | 1;
      puStack_10 = (undefined1 *)0x2c;
      FUN_0082a2a0();
      _atexit((_func_4879 *)&LAB_00bce440);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0082a3c0();
    if ((DAT_00fd9288 & 1) == 0) {
      DAT_00fd9288 = DAT_00fd9288 | 1;
      puStack_10 = (undefined1 *)0x2d;
      FUN_0043f500();
      _atexit((_func_4879 *)&LAB_00bce590);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0043e7c0();
    if ((DAT_00fc0dfc & 1) == 0) {
      DAT_00fc0dfc = DAT_00fc0dfc | 1;
      puStack_10 = (undefined1 *)0x2e;
      FUN_008263c0();
      _atexit(FUN_00bcda40);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00826440();
    if ((_DAT_00fc0e10 & 1) == 0) {
      _DAT_00fc0e10 = _DAT_00fc0e10 | 1;
      DAT_00fc0e14 = 0;
      _DAT_00fc0e18 = 0;
      _DAT_00fc0e1c = 0;
      DAT_00fc0e24 = 0;
      _DAT_00fc0e28 = 0;
      _DAT_00fc0e2c = 0;
      _atexit((_func_4879 *)&LAB_00bcdaa0);
    }
    FUN_00474740();
    if ((_DAT_00fdf3c0 & 1) == 0) {
      _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
      DAT_00fdf3c4 = 0;
      _atexit((_func_4879 *)&DAT_00bcdf50);
    }
    iVar9 = FUN_00891268();
    puStack_10 = (undefined1 *)0x2f;
    if (iVar9 == 0) {
      DAT_00fdf3c4 = 0;
    }
    else {
      DAT_00fdf3c4 = FUN_0056de30();
    }
    if ((DAT_00fc1b00 & 1) == 0) {
      DAT_00fc1b00 = DAT_00fc1b00 | 1;
      puStack_10 = (undefined1 *)0x30;
      FUN_00829b30();
      _atexit(FUN_00bce3e0);
    }
    puStack_10 = (undefined1 *)0xffffffff;
    FUN_00829640();
    FUN_0046c580();
    if ((_DAT_00fc1ca8 & 1) == 0) {
      _DAT_00fc1ca8 = _DAT_00fc1ca8 | 1;
      DAT_00fc1cac = 0;
      DAT_00fc1cb0 = 0;
      _DAT_00fc1cb4 = 0;
      _atexit((_func_4879 *)&LAB_00bce5a0);
    }
    FUN_0082b2c0();
    if ((DAT_00faaffc & 1) == 0) {
      DAT_00faaffc = DAT_00faaffc | 1;
      puStack_10 = (undefined1 *)0x31;
      FUN_008132e0();
      _atexit((_func_4879 *)&LAB_00bccce0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_008134a0();
    FUN_00813670();
    if ((DAT_00fb7bcc & 1) == 0) {
      DAT_00fb7bcc = DAT_00fb7bcc | 1;
      puStack_10 = (undefined1 *)0x32;
      FUN_00820290();
      _atexit((_func_4879 *)&LAB_00bcd520);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00820540();
    if ((DAT_00fc1b14 & 1) == 0) {
      DAT_00fc1b14 = DAT_00fc1b14 | 1;
      puStack_10 = (undefined1 *)0x33;
      FUN_0055ee90();
      _atexit((_func_4879 *)&LAB_00bcdf90);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    iVar9 = DAT_00fc1b1c;
    uVar2 = DAT_00fc1b88 & 1;
    *(undefined4 *)(DAT_00fc1b1c + 0x30) = 0x230;
    *(undefined4 *)(iVar9 + 0x2c) = 200;
    *(undefined4 *)(DAT_00fc1b1c + 0x1c) = 0xc0000000;
    *(undefined4 *)(DAT_00fc1b1c + 0x38) = 1;
    if (uVar2 == 0) {
      DAT_00fc1b88 = DAT_00fc1b88 | 1;
      puStack_10 = (undefined1 *)0x34;
      FUN_00581c10();
      _atexit((_func_4879 *)&LAB_00bcdfa0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    iVar9 = DAT_00fc1b94;
    uVar2 = DAT_00fc1bf4 & 1;
    *(undefined4 *)(DAT_00fc1b94 + 0x2c) = 200;
    *(undefined4 *)(iVar9 + 0x30) = 600;
    *(undefined4 *)(DAT_00fc1b94 + 0x1c) = 0xc0ffffff;
    *(undefined4 *)(DAT_00fc1b94 + 0x38) = 1;
    iVar9 = DAT_00fc1b94;
    *(undefined4 *)(DAT_00fc1b94 + 0x20) = 0;
    *(undefined4 *)(iVar9 + 0x24) = 1;
    if (uVar2 == 0) {
      DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
      puStack_10 = (undefined1 *)0x35;
      FUN_0057ef90();
      _atexit((_func_4879 *)&LAB_00bcdfb0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0057f390();
    if ((_DAT_00fd2cf0 & 1) == 0) {
      _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
      FUN_00738090();
      _atexit((_func_4879 *)&DAT_00bce680);
    }
    DAT_00fd2bbc = 8;
    DAT_00fd2bc0 = 0x78;
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      puStack_10 = (undefined1 *)0x36;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      puStack_10 = (undefined1 *)0x37;
      FUN_00560170();
      _atexit((_func_4879 *)&LAB_00bcd110);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00560600();
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      puStack_10 = (undefined1 *)0x38;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fc0f80 & 1) == 0) {
      DAT_00fc0f80 = DAT_00fc0f80 | 1;
      puStack_10 = (undefined1 *)0x39;
      FUN_0047aeb0();
      _atexit((_func_4879 *)&LAB_00bcdb70);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_004a88e0();
    puVar7 = (undefined4 *)FUN_00891268();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = IS3DIMP::CCellShader::vftable;
      puVar7[1] = 0;
      puVar7[2] = 0;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      puStack_10 = (undefined1 *)0x3a;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    puStack_6c = puVar7;
    FUN_007bb350();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10 = (undefined1 *)0x3b;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if (DAT_00fb92e5 == '\0') {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        puStack_10 = (undefined1 *)0x3d;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        puStack_10 = (undefined1 *)0xffffffff;
      }
      DAT_00fb774c = 0;
    }
    else {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        puStack_10 = (undefined1 *)0x3c;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        puStack_10 = (undefined1 *)0xffffffff;
      }
      DAT_00fb774c = 3;
    }
    if ((_DAT_00fc183c & 1) == 0) {
      _DAT_00fc183c = _DAT_00fc183c | 1;
      FUN_006f1ff0();
      DAT_00fc18d8 = 1;
      _atexit((_func_4879 *)&LAB_00bce3a0);
    }
    GetKeyboardLayout(0);
    FUN_006f2170();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      puStack_10 = (undefined1 *)0x3e;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_00589b90();
    if ((DAT_00fbacd0 & 1) == 0) {
      DAT_00fbacd0 = DAT_00fbacd0 | 1;
      puStack_10 = (undefined1 *)0x3f;
      DAT_00fbacd4 = 0;
      DAT_00fbacd4 = FUN_006d6300();
      _atexit((_func_4879 *)&LAB_00bcd670);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((DAT_00fbacd4 != 0) && (*(int *)(DAT_00fbacd4 + 0x28) == 2)) {
      if ((DAT_00fbacd0 & 1) == 0) {
        DAT_00fbacd0 = DAT_00fbacd0 | 1;
        puStack_10 = (undefined1 *)0x40;
        DAT_00fbacd4 = 0;
        DAT_00fbacd4 = FUN_006d6300();
        _atexit((_func_4879 *)&LAB_00bcd670);
        puStack_10 = (undefined1 *)0xffffffff;
      }
      FUN_006d6350();
    }
    if (DAT_00fba80c == 0) {
      iVar9 = FUN_00891268();
      if (iVar9 == 0) {
        DAT_00fba80c = 0;
      }
      else {
        DAT_00fba80c = FUN_006f1370();
      }
    }
    FUN_006f1430();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10 = (undefined1 *)0x41;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if ((_DAT_00fc1a6c & 1) == 0) {
      _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
      _atexit((_func_4879 *)&DAT_00bce3b0);
    }
    if (DAT_00fba80c == 0) {
      iVar9 = FUN_00891268();
      if (iVar9 == 0) {
        DAT_00fba80c = 0;
      }
      else {
        DAT_00fba80c = FUN_006f1370();
      }
    }
    piVar10 = (int *)FUN_006f1640();
    if (piVar10 != (int *)0x0) {
      (**(code **)(*piVar10 + 0x28))();
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10 = (undefined1 *)0x42;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if (DAT_00fb9111 != '\0') {
      if ((DAT_00fc1724 & 1) == 0) {
        DAT_00fc1724 = DAT_00fc1724 | 1;
        puStack_10 = (undefined1 *)0x43;
        FUN_006ccd20();
        _atexit((_func_4879 *)&LAB_00bce3c0);
        puStack_10 = (undefined1 *)0xffffffff;
      }
      FUN_006ccfc0();
    }
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10 = (undefined1 *)0x44;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_0080afe0();
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10 = (undefined1 *)0x45;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    puStack_40 = &DAT_00fab028;
    uStack_28 = 0xf;
    uStack_2c = 0;
    uStack_3c = uStack_3c & 0xffffff00;
    puStack_10 = (undefined1 *)0x46;
    FUN_00543050();
    uStack_48 = 0xf;
    uStack_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0040b310();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x48;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puVar7 = DAT_00fb9234;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x49;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_68 = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x4a;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    puStack_10._0_1_ = 0x47;
    puStack_6c = (undefined4 *)FUN_0080c1c0();
    if ((puStack_6c == DAT_00fab054) || (cVar4 = FUN_005436a0(), cVar4 != '\0')) {
      puStack_64 = DAT_00fab054;
      ppuVar11 = &puStack_64;
    }
    else {
      ppuVar11 = &puStack_6c;
    }
    iVar9 = DAT_00fab04c;
    if (*ppuVar11 != DAT_00fab054) {
      iVar9 = (*ppuVar11)[10];
    }
    *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) | 1;
    uVar2 = DAT_00fab0d4 & 1;
    *(float *)(iVar9 + 0x24) = (float)local_68 * (float)puVar7;
    if (uVar2 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x4b;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      puStack_10._0_1_ = 0x47;
    }
    FUN_0080c0a0();
    puStack_10._0_1_ = 0x46;
    if (0xf < uStack_48) {
      FUN_0089120c();
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0040b310();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x4d;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_6c = DAT_00fb9234;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x4e;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_64 = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x4f;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    puStack_10._0_1_ = 0x4c;
    puVar7 = (undefined4 *)FUN_0080c1c0();
    if ((puVar7 == DAT_00fab054) || (cVar4 = FUN_005436a0(), cVar4 != '\0')) {
      local_68 = DAT_00fab054;
      ppuVar11 = &local_68;
    }
    else {
      ppuVar11 = (undefined4 **)&stack0xffffff90;
    }
    iVar9 = DAT_00fab04c;
    if (*ppuVar11 != DAT_00fab054) {
      iVar9 = (*ppuVar11)[10];
    }
    *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) | 1;
    uVar2 = DAT_00fab0d4 & 1;
    *(float *)(iVar9 + 0x24) = (float)puStack_6c * 0.57 * (float)puStack_64;
    if (uVar2 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x50;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      puStack_10._0_1_ = 0x4c;
    }
    FUN_0080c0a0();
    puStack_10._0_1_ = 0x46;
    if (0xf < uStack_48) {
      FUN_0089120c();
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0040b310();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x52;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_6c = DAT_00fb9234;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x53;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_64 = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x54;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    puStack_10._0_1_ = 0x51;
    puVar7 = (undefined4 *)FUN_0080c1c0();
    if ((puVar7 == DAT_00fab054) || (cVar4 = FUN_005436a0(), cVar4 != '\0')) {
      local_68 = DAT_00fab054;
      ppuVar11 = &local_68;
    }
    else {
      ppuVar11 = (undefined4 **)&stack0xffffff90;
    }
    iVar9 = DAT_00fab04c;
    if (*ppuVar11 != DAT_00fab054) {
      iVar9 = (*ppuVar11)[10];
    }
    *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) | 1;
    uVar2 = DAT_00fab0d4 & 1;
    *(float *)(iVar9 + 0x24) = (float)puStack_6c * 0.714 * (float)puStack_64;
    if (uVar2 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x55;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      puStack_10._0_1_ = 0x51;
    }
    FUN_0080c0a0();
    puStack_10._0_1_ = 0x46;
    if (0xf < uStack_48) {
      FUN_0089120c();
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0040b310();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x57;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_64 = DAT_00fb924c;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x58;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_6c = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x59;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    puStack_10._0_1_ = 0x56;
    puVar7 = (undefined4 *)FUN_0080c1c0();
    if ((puVar7 == DAT_00fab054) || (cVar4 = FUN_005436a0(), cVar4 != '\0')) {
      local_68 = DAT_00fab054;
      ppuVar11 = &local_68;
    }
    else {
      ppuVar11 = (undefined4 **)&stack0xffffff90;
    }
    iVar9 = DAT_00fab04c;
    if (*ppuVar11 != DAT_00fab054) {
      iVar9 = (*ppuVar11)[10];
    }
    *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) | 1;
    uVar2 = DAT_00fab0d4 & 1;
    *(float *)(iVar9 + 0x24) = (float)puStack_6c * (float)puStack_64;
    if (uVar2 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x5a;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      puStack_10._0_1_ = 0x56;
    }
    FUN_0080c0a0();
    puStack_10._0_1_ = 0x46;
    if (0xf < uStack_48) {
      FUN_0089120c();
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0040b310();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x5c;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_64 = DAT_00fb9264;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x5d;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_6c = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x5e;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    puStack_10._0_1_ = 0x5b;
    puVar7 = (undefined4 *)FUN_0080c1c0();
    if ((puVar7 == DAT_00fab054) || (cVar4 = FUN_005436a0(), cVar4 != '\0')) {
      local_68 = DAT_00fab054;
    }
    FUN_0080ca50();
    puStack_10._0_1_ = 0x46;
    if (0xf < uStack_48) {
      FUN_0089120c();
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    local_5c = local_5c & 0xffffff00;
    FUN_0040b310();
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x60;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    sVar3 = DAT_00fb92d6;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      puStack_10._0_1_ = 0x61;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    puStack_6c = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 0x62;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    puStack_10._0_1_ = 0x5f;
    puVar7 = (undefined4 *)FUN_0080c1c0();
    if ((puVar7 == DAT_00fab054) || (cVar4 = FUN_005436a0(), cVar4 != '\0')) {
      local_68 = DAT_00fab054;
      ppuVar11 = &local_68;
    }
    else {
      ppuVar11 = (undefined4 **)&stack0xffffff90;
    }
    iVar9 = DAT_00fab04c;
    if (*ppuVar11 != DAT_00fab054) {
      iVar9 = (*ppuVar11)[10];
    }
    *(uint *)(iVar9 + 0x20) = *(uint *)(iVar9 + 0x20) | 1;
    uVar2 = DAT_00fab0d4 & 1;
    *(float *)(iVar9 + 0x24) = (float)(int)sVar3 * (float)puStack_6c;
    if (uVar2 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      puStack_10._0_1_ = 99;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      puStack_10._0_1_ = 0x5f;
    }
    FUN_0080c0a0();
    puStack_10._0_1_ = 0x46;
    if (0xf < uStack_48) {
      FUN_0089120c();
    }
    if ((_DAT_00fc1698 & 1) == 0) {
      _DAT_00fc1698 = _DAT_00fc1698 | 1;
      FUN_0080c8a0();
      _atexit((_func_4879 *)&LAB_00bce320);
    }
    FUN_0080c950();
    if ((DAT_00fc1a34 & 1) == 0) {
      DAT_00fc1a34 = DAT_00fc1a34 | 1;
      puStack_10._0_1_ = 100;
      FUN_00737210();
      _atexit(FUN_00bce000);
      puStack_10._0_1_ = 0x46;
    }
    FUN_007376f0();
    if ((DAT_00fc1a34 & 1) == 0) {
      DAT_00fc1a34 = DAT_00fc1a34 | 1;
      puStack_10._0_1_ = 0x65;
      FUN_00737210();
      _atexit(FUN_00bce000);
      puStack_10._0_1_ = 0x46;
    }
    if (DAT_00fc1a54 != 0) {
      DAT_00fc1a54 = 0;
      _DAT_00fc1a5c = 1;
      FUN_008438c0();
      if (local_68 == DAT_00fc1a48) {
        _DAT_00fc1a5c = 0;
        _DAT_00fc1a58 = 0;
      }
      else {
        _DAT_00fc1a58 = local_68[4];
      }
      FUN_00737450();
    }
    if ((DAT_00fc1a34 & 1) == 0) {
      DAT_00fc1a34 = DAT_00fc1a34 | 1;
      puStack_10._0_1_ = 0x66;
      FUN_00737210();
      _atexit(FUN_00bce000);
      puStack_10._0_1_ = 0x46;
    }
    _DAT_00fc1a60 = 1;
    FUN_00489cb0();
    FUN_004054c0();
    FUN_0058b3d0();
    if (0xf < uStack_28) {
      FUN_0089120c();
    }
    ExceptionList = pvStack_18;
    __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff90);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

