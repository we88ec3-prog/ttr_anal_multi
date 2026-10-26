
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00590760(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  undefined *puVar6;
  short *psVar7;
  undefined4 uVar8;
  undefined **local_3c [3];
  undefined **local_30 [3];
  undefined *local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927075;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24 = &DAT_00fdfb18;
  _DAT_00fdfb18 = FUI::CKeyDescMgr::vftable;
  _eh_vector_constructor_iterator_
            (&DAT_00fdfb1c,0x1c,0x100,(_func_void_void_ptr *)&LAB_00402140,FUN_004fa440);
  local_8 = 0;
  _DAT_00fe1724 = 0;
  iVar4 = FUN_00891268(0x30,uVar3);
  if (iVar4 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_3c,&local_1c);
    local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_3c,&DAT_00c857a8);
  }
  DAT_00fe1720 = iVar4;
  *(int *)iVar4 = iVar4;
  *(int *)(DAT_00fe1720 + 4) = DAT_00fe1720;
  *(int *)(DAT_00fe1720 + 8) = DAT_00fe1720;
  *(undefined1 *)(DAT_00fe1720 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fe1720 + 0x2d) = 1;
  local_8._0_1_ = 1;
  _DAT_00fe1734 = 0;
  iVar4 = FUN_00891268(0x30,uVar3);
  if (iVar4 == 0) {
    local_20 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_20);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  DAT_00fe1730 = iVar4;
  *(int *)iVar4 = iVar4;
  *(int *)(DAT_00fe1730 + 4) = DAT_00fe1730;
  *(int *)(DAT_00fe1730 + 8) = DAT_00fe1730;
  *(undefined1 *)(DAT_00fe1730 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fe1730 + 0x2d) = 1;
  local_8._0_1_ = 2;
  FUN_00402160(&DAT_00c1ad34,3);
  FUN_00402160(&DAT_00c1ad3c,1);
  FUN_00402160(&DAT_00c1ad40,1);
  FUN_00402160(&DAT_00c1ad44,1);
  FUN_00402160(&DAT_00c1ad48,1);
  FUN_00402160(&DAT_00c1ad4c,1);
  FUN_00402160(&DAT_00c1ad50,1);
  FUN_00402160(&DAT_00c1ad54,1);
  FUN_00402160(&DAT_00c1ad58,1);
  FUN_00402160(&DAT_00c1ad5c,1);
  FUN_00402160(&DAT_00bf9280,1);
  FUN_00402160(&DAT_00c1ad60,1);
  FUN_00402160(&DAT_00c1ad64,1);
  FUN_00402160(L"BackSpace",9);
  FUN_00402160(&PTR_switchdataD_00610054_00c1ad7c,3);
  FUN_00402160(&DAT_00c1ad84,1);
  FUN_00402160(&DAT_00c1ad88,1);
  FUN_00402160(&DAT_00c114e0,1);
  FUN_00402160(&DAT_00c1ad8c,1);
  FUN_00402160(&DAT_00c1ad90,1);
  FUN_00402160(&DAT_00c1ad94,1);
  FUN_00402160(&DAT_00c1ad98,1);
  FUN_00402160(&DAT_00c1ad9c,1);
  FUN_00402160(&DAT_00c1ada0,1);
  FUN_00402160(&DAT_00c1ada4,1);
  FUN_00402160(&DAT_00c07ac8,1);
  FUN_00402160(&DAT_00c07acc,1);
  FUN_00402160(L"Return",6);
  FUN_00402160(L"Ctrl",4);
  FUN_00402160(&DAT_00c114d4,1);
  FUN_00402160(&DAT_00c114d0,1);
  FUN_00402160(&DAT_00c114dc,1);
  FUN_00402160(&DAT_00c114e4,1);
  FUN_00402160(&DAT_00c1adc4,1);
  FUN_00402160(&DAT_00c1adc8,1);
  FUN_00402160(&DAT_00c1adcc,1);
  FUN_00402160(&DAT_00c1add0,1);
  FUN_00402160(&DAT_00c1add4,1);
  FUN_00402160(&DAT_00c1add8,1);
  FUN_00402160(L"APOSTROPHE",10);
  FUN_00402160(&DAT_00c1adf4,1);
  FUN_00402160(L"L.Shift",7);
  FUN_00402160(&DAT_00c1ae08,1);
  FUN_00402160(&DAT_00c115a4,1);
  FUN_00402160(&DAT_00c115a0,1);
  FUN_00402160(&DAT_00c1159c,1);
  FUN_00402160(&DAT_00c11580,1);
  FUN_00402160(&DAT_00c114d8,1);
  FUN_00402160(&DAT_00c1ae0c,1);
  FUN_00402160(&DAT_00c1ae10,1);
  FUN_00402160(&DAT_00c1ae14,1);
  FUN_00402160(&DAT_00c1ae18,1);
  FUN_00402160(&DAT_00c0cd8c,1);
  FUN_00402160(L"R.Shift",7);
  FUN_00402160(L"MULTIPLY",8);
  FUN_00402160(&DAT_00c1ae40,3);
  FUN_00402160(L"Space",5);
  FUN_00402160(L"CapsLock",8);
  FUN_00402160(&DAT_00c1ae68,2);
  FUN_00402160(&DAT_00c1ae70,2);
  FUN_00402160(&DAT_00c1ae78,2);
  FUN_00402160(&DAT_00c1ae80,2);
  FUN_00402160(&DAT_00c1ae88,2);
  FUN_00402160(&DAT_00c1ae90,2);
  FUN_00402160(&DAT_00c1ae98,2);
  FUN_00402160(&DAT_00c1aea0,2);
  FUN_00402160(&DAT_00c1aea8,2);
  FUN_00402160(&DAT_00c1aeb0,3);
  FUN_00402160(L"NumLock",7);
  FUN_00402160(L"ScrollLock",10);
  FUN_00402160(L"Numpad7",7);
  FUN_00402160(L"Numpad8",7);
  FUN_00402160(L"Numpad9",7);
  FUN_00402160(L"Numpad(-)",9);
  FUN_00402160(L"Numpad4",7);
  FUN_00402160(L"Numpad5",7);
  FUN_00402160(L"Numpad6",7);
  FUN_00402160(L"Numpad(+)",9);
  FUN_00402160(L"Numpad1",7);
  FUN_00402160(L"Numpad2",7);
  FUN_00402160(L"Numpad3",7);
  FUN_00402160(L"Numpad0",7);
  FUN_00402160(L"Numpad(.)",9);
  FUN_00402160(L"OEM_102",7);
  FUN_00402160(&DAT_00c1afcc,3);
  FUN_00402160(&DAT_00c1afd4,3);
  FUN_00402160(&DAT_00c1afdc,3);
  FUN_00402160(&DAT_00c1afe4,3);
  FUN_00402160(&DAT_00c1afec,3);
  FUN_00402160(L"KANA",4);
  FUN_00402160(L"ABNT_C1",7);
  FUN_00402160(L"CONVERT",7);
  FUN_00402160(L"NOCONVERT",9);
  FUN_00402160(&PTR_LAB_00c1b034,3);
  FUN_00402160(L"ABNT_C2",7);
  FUN_00402160(L"NUMPADEQUALS",0xc);
  FUN_00402160(L"PREVTRACK",9);
  FUN_00402160(&DAT_00c1b07c,2);
  FUN_00402160(L"COLON",5);
  FUN_00402160(L"UNDERLINE",9);
  FUN_00402160(L"KANJI",5);
  FUN_00402160(L"STOP",4);
  FUN_00402160(&DAT_00c1b0bc,2);
  FUN_00402160(L"UNLABELED",9);
  FUN_00402160(L"NEXTTRACK",9);
  FUN_00402160(L"NUMPADENTER",0xb);
  FUN_00402160(L"Ctrl",4);
  FUN_00402160(L"MUTE",4);
  FUN_00402160(L"CALCULATOR",10);
  FUN_00402160(L"PLAYPAUSE",9);
  FUN_00402160(L"MEDIASTOP",9);
  FUN_00402160(L"VOLUMEDOWN",10);
  FUN_00402160(L"VOLUMEUP",8);
  FUN_00402160(L"WEBHOME",7);
  FUN_00402160(L"NUMPADCOMMA",0xb);
  FUN_00402160(L"DIVIDE",6);
  FUN_00402160(L"SYSRQ",5);
  FUN_00402160(L"RALT",4);
  FUN_00402160(L"PAUSE",5);
  FUN_00402160(L"HOME",4);
  FUN_00402160(&DAT_00c1b1e4,2);
  FUN_00402160(L"PRIOR",5);
  FUN_00402160(L"LEFT",4);
  FUN_00402160(L"RIGHT",5);
  FUN_00402160(&DAT_00c1b210,3);
  FUN_00402160(L"DOWN",4);
  FUN_00402160(L"NEXT",4);
  FUN_00402160(L"INSERT",6);
  FUN_00402160(L"DELETE",6);
  FUN_00402160(L"LWIN",4);
  FUN_00402160(L"RWIN",4);
  FUN_00402160(L"APPS",4);
  FUN_00402160(L"POWER",5);
  FUN_00402160(L"SLEEP",5);
  FUN_00402160(L"WAKE",4);
  FUN_00402160(L"WEBSEARCH",9);
  FUN_00402160(L"WEBFAVORITES",0xc);
  FUN_00402160(L"WEBREFRESH",10);
  FUN_00402160(L"WEBSTOP",7);
  FUN_00402160(L"WEBFORWARD",10);
  FUN_00402160(L"WEBBACK",7);
  FUN_00402160(L"MYCOMPUTER",10);
  FUN_00402160(L"MAIL",4);
  FUN_00402160(L"MEDIASELECT",0xb);
  local_1c = (char *)0x1;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 2;
  }
  local_14 = 0x85;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 2;
  local_1c = (char *)0x86;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 3;
  local_1c = (char *)0x87;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 4;
  local_1c = (char *)0x88;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0xd;
  local_1c = (char *)0x89;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0xe;
  local_1c = (char *)0x8a;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0xf;
  local_1c = (char *)0x8b;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x18;
  local_1c = (char *)0x8c;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x1a;
  local_1c = (char *)0x8d;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x19;
  local_1c = (char *)0x8e;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x10;
  local_1c = &DAT_0000008f;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x27;
  local_1c = (char *)0x95;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x11;
  local_1c = (char *)0x90;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x12;
  local_1c = (char *)0x91;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x13;
  local_1c = (char *)0x92;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x14;
  local_1c = (char *)0x93;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x1b;
  local_1c = (char *)0x94;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x16;
  local_1c = (char *)0xa2;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x15;
  local_1c = (char *)0x96;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x17;
  local_1c = (char *)0x97;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 6;
  local_1c = (char *)0x98;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 7;
  local_1c = (char *)0x99;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 8;
  local_1c = (char *)0x9a;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 9;
  local_1c = (char *)0x9b;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0xc;
  local_1c = (char *)0x9c;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 10;
  local_1c = (char *)0x9d;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0xb;
  local_1c = (char *)0x9e;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x2774;
  local_1c = (char *)0xf4;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x2775;
  local_1c = (char *)0xf5;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x2776;
  local_1c = (char *)0xf6;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x1c;
  local_1c = (char *)0xf7;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  uVar8 = 0xf8;
  local_1c = &DAT_0000001d;
  FUN_00585620(0xf8);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xf9;
  local_1c = (char *)0x1e;
  FUN_00585620(0xf9);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xfa;
  local_1c = (char *)0x1f;
  FUN_00585620(0xfa);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xfb;
  local_1c = (char *)0x20;
  FUN_00585620(0xfb);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xfc;
  local_1c = (char *)0x21;
  FUN_00585620(0xfc);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xfd;
  local_1c = (char *)0x22;
  FUN_00585620(0xfd);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xfe;
  local_1c = (char *)0x23;
  FUN_00585620(0xfe);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xff;
  local_1c = (char *)0x24;
  FUN_00585620(0xff);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x100;
  local_1c = &DAT_00000025;
  FUN_00585620(0x100);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x101;
  local_1c = (char *)0x283c;
  FUN_00585620(0x101);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x102;
  local_1c = (char *)0x283d;
  FUN_00585620(0x102);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x103;
  local_1c = (char *)0x283e;
  FUN_00585620(0x103);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x104;
  local_1c = (char *)0x283f;
  FUN_00585620(0x104);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x105;
  local_1c = (char *)0x2840;
  FUN_00585620(0x105);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x106;
  local_1c = (char *)0x2841;
  FUN_00585620(0x106);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x107;
  local_1c = (char *)0x2842;
  FUN_00585620(0x107);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x108;
  local_1c = (char *)0x2843;
  FUN_00585620(0x108);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x109;
  local_1c = (char *)0x2844;
  FUN_00585620(0x109);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x10a;
  local_1c = (char *)0x2845;
  FUN_00585620(0x10a);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x10b;
  local_1c = (char *)0x2846;
  FUN_00585620(0x10b);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x10c;
  local_1c = (char *)0x2847;
  FUN_00585620(0x10c);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x10d;
  local_1c = (char *)0x2848;
  FUN_00585620(0x10d);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x10e;
  local_1c = (char *)0x2849;
  FUN_00585620(0x10e);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x10f;
  local_1c = (char *)0x284a;
  FUN_00585620(0x10f);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x110;
  local_1c = (char *)0x284b;
  FUN_00585620(0x110);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x111;
  local_1c = (char *)0x284c;
  FUN_00585620(0x111);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x112;
  local_1c = (char *)0x284d;
  FUN_00585620(0x112);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x113;
  local_1c = (char *)0x28a0;
  FUN_00585620(0x113);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x114;
  local_1c = (char *)0x28a1;
  FUN_00585620(0x114);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x115;
  local_1c = (char *)0x28a2;
  FUN_00585620(0x115);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x116;
  local_1c = (char *)0x28a3;
  FUN_00585620(0x116);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x117;
  local_1c = (char *)0x28a4;
  FUN_00585620(0x117);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x118;
  local_1c = (char *)0x28a5;
  FUN_00585620(0x118);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x119;
  local_1c = (char *)0x28a6;
  FUN_00585620(0x119);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xa6;
  local_1c = (char *)0x2904;
  FUN_00585620(0xa6);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xa7;
  local_1c = (char *)0x2905;
  FUN_00585620(0xa7);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xa8;
  local_1c = (char *)0x2906;
  FUN_00585620(0xa8);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xa9;
  local_1c = (char *)0x2907;
  FUN_00585620(0xa9);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xaa;
  local_1c = (char *)0x2908;
  FUN_00585620(0xaa);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xab;
  local_1c = (char *)0x2909;
  FUN_00585620(0xab);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xac;
  local_1c = (char *)0x290a;
  FUN_00585620(0xac);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xae;
  local_1c = (char *)0x290c;
  FUN_00585620(0xae);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xaf;
  local_1c = (char *)0x290d;
  FUN_00585620(0xaf);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb0;
  local_1c = (char *)0x290e;
  FUN_00585620(0xb0);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb1;
  local_1c = (char *)0x290f;
  FUN_00585620(0xb1);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb2;
  local_1c = (char *)0x2910;
  FUN_00585620(0xb2);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb3;
  local_1c = (char *)0x2911;
  FUN_00585620(0xb3);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb4;
  local_1c = (char *)0x2912;
  FUN_00585620(0xb4);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb5;
  local_1c = (char *)0x2913;
  FUN_00585620(0xb5);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb6;
  local_1c = (char *)0x2914;
  FUN_00585620(0xb6);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb7;
  local_1c = (char *)0x2915;
  FUN_00585620(0xb7);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb8;
  local_1c = (char *)0x2916;
  FUN_00585620(0xb8);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xb9;
  local_1c = (char *)0x2918;
  FUN_00585620(0xb9);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xba;
  local_1c = (char *)0x2917;
  FUN_00585620(0xba);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xbb;
  local_1c = (char *)0x26;
  FUN_00585620(0xbb);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xbc;
  local_1c = (char *)0x2919;
  FUN_00585620(0xbc);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xbd;
  local_1c = (char *)0x291a;
  FUN_00585620(0xbd);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xd6;
  local_1c = (char *)0x1;
  FUN_00585620(0xd6);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xd7;
  local_1c = (char *)0x2;
  FUN_00585620(0xd7);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xd8;
  local_1c = (char *)0x3;
  FUN_00585620(0xd8);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xd9;
  local_1c = (char *)0x4;
  FUN_00585620(0xd9);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xda;
  local_1c = (char *)0xd;
  FUN_00585620(0xda);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xdb;
  local_1c = (char *)0xe;
  FUN_00585620(0xdb);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xdc;
  local_1c = (char *)0xf;
  FUN_00585620(0xdc);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xdd;
  local_1c = (char *)0x18;
  FUN_00585620(0xdd);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xde;
  local_1c = (char *)0x1a;
  FUN_00585620(0xde);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xdf;
  local_1c = (char *)0x19;
  FUN_00585620(0xdf);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe0;
  local_1c = (char *)0x10;
  FUN_00585620(0xe0);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe6;
  local_1c = (char *)0x27;
  FUN_00585620(0xe6);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe1;
  local_1c = &DAT_00000011;
  FUN_00585620(0xe1);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe2;
  local_1c = (char *)0x12;
  FUN_00585620(0xe2);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe3;
  local_1c = (char *)0x13;
  FUN_00585620(0xe3);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe4;
  local_1c = &DAT_00000014;
  FUN_00585620(0xe4);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe5;
  local_1c = &DAT_0000001b;
  FUN_00585620(0xe5);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xf3;
  local_1c = (char *)0x16;
  FUN_00585620(0xf3);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe7;
  local_1c = (char *)0x15;
  FUN_00585620(0xe7);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe8;
  local_1c = (char *)0x17;
  FUN_00585620(0xe8);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xe9;
  local_1c = (char *)0x6;
  FUN_00585620(0xe9);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xea;
  local_1c = (char *)0x7;
  FUN_00585620(0xea);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xeb;
  local_1c = (char *)0x8;
  FUN_00585620(0xeb);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xec;
  local_1c = (char *)0x9;
  FUN_00585620(0xec);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xed;
  local_1c = (char *)0xc;
  FUN_00585620(0xed);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xee;
  local_1c = (char *)0xa;
  FUN_00585620(0xee);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0xef;
  local_1c = (char *)0xb;
  FUN_00585620(0xef);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x11a;
  local_1c = (char *)0x2774;
  FUN_00585620(0x11a);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x11b;
  local_1c = (char *)0x2775;
  FUN_00585620(0x11b);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x11c;
  local_1c = (char *)0x2776;
  FUN_00585620(0x11c);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x11d;
  local_1c = (char *)0x1c;
  FUN_00585620(0x11d);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x11e;
  local_1c = &DAT_0000001d;
  FUN_00585620(0x11e);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x11f;
  local_1c = (char *)0x1e;
  FUN_00585620(0x11f);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x120;
  local_1c = (char *)0x1f;
  FUN_00585620(0x120);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x121;
  local_1c = (char *)0x20;
  FUN_00585620(0x121);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x122;
  local_1c = (char *)0x21;
  FUN_00585620(0x122);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x123;
  local_1c = (char *)0x22;
  FUN_00585620(0x123);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x124;
  local_1c = (char *)0x23;
  FUN_00585620(0x124);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x125;
  local_1c = (char *)0x24;
  FUN_00585620(0x125);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  uVar8 = 0x126;
  local_1c = &DAT_00000025;
  FUN_00585620(0x126);
  psVar5 = (short *)FUN_00585330(uVar8);
  FUN_00594b10();
  psVar7 = psVar5;
  do {
    sVar1 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
  iVar4 = 0;
  do {
    FUN_0041e5c0();
    psVar5 = (short *)FUN_0049f480();
    local_1c = (char *)(iVar4 + 0x283c);
    FUN_00594b10();
    psVar7 = psVar5;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar7 - (int)(psVar5 + 1) >> 1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x13);
  local_14 = 0x28a0;
  local_1c = (char *)0x7e;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x28a1;
  local_1c = (char *)0x7f;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  FUN_00594b10();
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_14 = 0x28a2;
  local_1c = (char *)0x80;
  iVar4 = FUN_00585620();
  FUN_005740f0(&local_1c);
  if (local_18 != *(int *)(iVar4 + 4)) {
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x28a3;
    local_1c = (char *)0x81;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x28a4;
    local_1c = (char *)0x82;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x28a5;
    local_1c = (char *)0x83;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x28a6;
    local_1c = (char *)0x84;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2904;
    local_1c = (char *)0xbe;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2905;
    local_1c = (char *)0xbf;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2906;
    local_1c = (char *)0xc0;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2907;
    local_1c = (char *)0xc1;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2908;
    local_1c = (char *)0xc2;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2909;
    local_1c = (char *)0xc3;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x290e;
    local_1c = (char *)0xc8;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x290f;
    local_1c = (char *)0xc9;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2913;
    local_1c = (char *)0xcd;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2914;
    local_1c = (char *)0xce;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2915;
    local_1c = (char *)0xcf;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2916;
    local_1c = (char *)0xd0;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2918;
    local_1c = (char *)0xd1;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    FUN_00594b10();
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
    local_14 = 0x2917;
    local_1c = (char *)0xd2;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 != *(int *)(iVar4 + 4)) {
      psVar7 = (short *)(local_18 + 0x10);
      if (7 < *(uint *)(local_18 + 0x24)) {
        psVar7 = *(short **)psVar7;
      }
      FUN_00594b10();
      psVar5 = psVar7;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
      local_14 = 0x26;
      local_1c = (char *)0xd3;
      iVar4 = FUN_00585620();
      FUN_005740f0(&local_1c);
      if (local_18 == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        puVar6 = (undefined *)(*pcVar2)();
        return puVar6;
      }
      psVar7 = (short *)(local_18 + 0x10);
      if (7 < *(uint *)(local_18 + 0x24)) {
        psVar7 = *(short **)psVar7;
      }
      FUN_00594b10();
      psVar5 = psVar7;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
      local_14 = 0x2919;
      local_1c = (char *)0xd4;
      iVar4 = FUN_00585620();
      FUN_005740f0(&local_1c);
      if (local_18 == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        puVar6 = (undefined *)(*pcVar2)();
        return puVar6;
      }
      psVar7 = (short *)(local_18 + 0x10);
      if (7 < *(uint *)(local_18 + 0x24)) {
        psVar7 = *(short **)psVar7;
      }
      FUN_00594b10();
      psVar5 = psVar7;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
      local_14 = 0x291a;
      local_1c = (char *)0xd5;
      iVar4 = FUN_00585620();
      FUN_005740f0(&local_1c);
      if (local_18 != *(int *)(iVar4 + 4)) {
        psVar7 = (short *)(local_18 + 0x10);
        if (7 < *(uint *)(local_18 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        FUN_00594b10();
        psVar5 = psVar7;
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
        ExceptionList = local_10;
        return &DAT_00fdfb18;
      }
      pcVar2 = (code *)swi(3);
      puVar6 = (undefined *)(*pcVar2)();
      return puVar6;
    }
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined *)(*pcVar2)();
    return puVar6;
  }
  pcVar2 = (code *)swi(3);
  puVar6 = (undefined *)(*pcVar2)();
  return puVar6;
}

