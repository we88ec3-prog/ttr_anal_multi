
void FUN_00657a20(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *in_ECX;
  undefined1 auStack_ac [20];
  undefined4 uStack_98;
  undefined1 **ppuStack_94;
  undefined ***pppuStack_90;
  undefined **local_78 [3];
  char *local_6c;
  undefined4 *local_68;
  undefined4 local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 *local_48;
  int local_44;
  undefined1 *local_40;
  undefined1 *local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d39d;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_68 = in_ECX;
  FUN_004285e0();
  local_8 = 0;
  *in_ECX = FUI::CMissionConditionPanel::vftable;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x4b] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x54] = 0;
  pppuStack_90 = (undefined ***)0x657aab;
  iVar3 = FUN_00891268();
  if (iVar3 == 0) {
    local_6c = (char *)0x0;
    pppuStack_90 = (undefined ***)0x658ea4;
    std::exception::exception((exception *)local_78,&local_6c);
    pppuStack_90 = local_78;
    local_78[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    ppuStack_94 = (undefined1 **)&UNK_00658eb9;
    __CxxThrowException_8();
  }
  in_ECX[0x53] = iVar3;
  *(int *)iVar3 = iVar3;
  *(undefined4 *)(in_ECX[0x53] + 4) = in_ECX[0x53];
  *(undefined4 *)(in_ECX[0x53] + 8) = in_ECX[0x53];
  *(undefined1 *)(in_ECX[0x53] + 0x20) = 1;
  *(undefined1 *)(in_ECX[0x53] + 0x21) = 1;
  in_ECX[0x57] = 0x3f800000;
  local_38 = 0;
  local_40 = (undefined1 *)0x1;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 2;
    pppuStack_90 = (undefined ***)0x657b1c;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x657b26;
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8._0_1_ = 1;
  local_48 = (undefined4 *)0x203;
  pppuStack_90 = (undefined ***)0x657b44;
  FUN_005740f0();
  if (local_44 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)(local_44 + 0x10);
  if (7 < *(uint *)(local_44 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_64 = (uint)local_64._2_2_ << 0x10;
  local_50 = 7;
  local_54 = 0;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x657b90;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,3);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_34 = (uint)local_34._2_2_ << 0x10;
  local_20 = 7;
  local_24 = 0;
  uStack_98 = 0x657bb3;
  FUN_004026e0();
  local_18 = 0x101;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x657bc8;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 4;
  pppuStack_90 = (undefined ***)0x657bf0;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x657c0a;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x657c28;
    FUN_0089120c();
  }
  local_48 = (undefined4 *)0x1;
  local_44 = 1;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 5;
    pppuStack_90 = (undefined ***)0x657c4d;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x657c57;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x204;
  pppuStack_90 = (undefined ***)0x657c75;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x657cc9;
  FUN_00402160();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_8 = CONCAT31(local_8._1_3_,6);
  local_20 = 7;
  local_24 = 0;
  local_34 = local_34 & 0xffff0000;
  uStack_98 = 0x657cec;
  FUN_004026e0();
  local_18 = 0x101;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x657d01;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 7;
  pppuStack_90 = (undefined ***)0x657d29;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x657d43;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x657d61;
    FUN_0089120c();
  }
  local_48 = (undefined4 *)0x2;
  local_44 = 1;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 8;
    pppuStack_90 = (undefined ***)0x657d8a;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x657d94;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x205;
  pppuStack_90 = (undefined ***)0x657db2;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_64 = local_64 & 0xffff0000;
  local_50 = 7;
  local_54 = 0;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x657dfe;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,9);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_34 = local_34 & 0xffff0000;
  local_20 = 7;
  local_24 = 0;
  uStack_98 = 0x657e21;
  FUN_004026e0();
  local_18 = 0x101;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x657e36;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 10;
  pppuStack_90 = (undefined ***)0x657e5e;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x657e78;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x657e96;
    FUN_0089120c();
  }
  local_48 = (undefined4 *)0x0;
  local_44 = 2;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 0xb;
    pppuStack_90 = (undefined ***)0x657ebf;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x657ec9;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x206;
  pppuStack_90 = (undefined ***)0x657ee7;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x657f39;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,0xc);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_20 = 7;
  local_24 = 0;
  local_34 = local_34 & 0xffff0000;
  uStack_98 = 0x657f5c;
  FUN_004026e0();
  local_18 = 0x100;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x657f71;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 0xd;
  pppuStack_90 = (undefined ***)0x657f99;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x657fb3;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x657fd1;
    FUN_0089120c();
  }
  local_48 = (undefined4 *)0x1;
  local_44 = 2;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 0xe;
    pppuStack_90 = (undefined ***)0x657ffa;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x658004;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x207;
  pppuStack_90 = (undefined ***)0x658022;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_64 = local_64 & 0xffff0000;
  local_50 = 7;
  local_54 = 0;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x65806e;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,0xf);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_34 = local_34 & 0xffff0000;
  local_20 = 7;
  local_24 = 0;
  uStack_98 = 0x658091;
  FUN_004026e0();
  local_18 = 0x100;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x6580a6;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 0x10;
  pppuStack_90 = (undefined ***)0x6580ce;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x6580e8;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658106;
    FUN_0089120c();
  }
  local_48 = (undefined4 *)0x2;
  local_44 = 2;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 0x11;
    pppuStack_90 = (undefined ***)0x658130;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x65813a;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x208;
  pppuStack_90 = (undefined ***)0x658158;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x6581a9;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,0x12);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_20 = 7;
  local_24 = 0;
  local_34 = local_34 & 0xffff0000;
  uStack_98 = 0x6581cc;
  FUN_004026e0();
  local_18 = 0x100;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x6581e1;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 0x13;
  pppuStack_90 = (undefined ***)0x658209;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x658223;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658241;
    FUN_0089120c();
  }
  local_48 = (undefined4 *)0x0;
  local_44 = 3;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 0x14;
    pppuStack_90 = (undefined ***)0x65826a;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x658274;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x209;
  pppuStack_90 = (undefined ***)0x658292;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_64 = local_64 & 0xffff0000;
  local_50 = 7;
  local_54 = 0;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x6582de;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,0x15);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_34 = local_34 & 0xffff0000;
  local_20 = 7;
  local_24 = 0;
  uStack_98 = 0x658301;
  FUN_004026e0();
  local_18 = 0x101;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x658316;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 0x16;
  pppuStack_90 = (undefined ***)0x65833e;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x658358;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658376;
    FUN_0089120c();
  }
  local_48 = (undefined4 *)0x0;
  local_44 = 4;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 0x17;
    pppuStack_90 = (undefined ***)0x65839f;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x6583a9;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x20a;
  pppuStack_90 = (undefined ***)0x6583c7;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x658419;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,0x18);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_20 = 7;
  local_24 = 0;
  local_34 = local_34 & 0xffff0000;
  uStack_98 = 0x65843c;
  FUN_004026e0();
  local_18 = 0x101;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x658451;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 0x19;
  pppuStack_90 = (undefined ***)0x658479;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x658493;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x6584b1;
    FUN_0089120c();
  }
  local_3c = (undefined1 *)0x1;
  local_44 = 4;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 0x1a;
    pppuStack_90 = (undefined ***)0x6584da;
    FUN_00584c40();
    pppuStack_90 = (undefined ***)0x6584e4;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_38 = 0x20b;
  pppuStack_90 = (undefined ***)0x658502;
  FUN_005740f0();
  if (local_40 == (undefined1 *)DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pppuStack_90 = (undefined ***)((int)local_40 + 0x10);
  if (7 < *(uint *)((int)local_40 + 0x24)) {
    pppuStack_90 = (undefined ***)*pppuStack_90;
  }
  local_64 = local_64 & 0xffff0000;
  local_50 = 7;
  local_54 = 0;
  psVar4 = (short *)pppuStack_90;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  ppuStack_94 = (undefined1 **)0x65854e;
  FUN_00402160();
  local_8 = CONCAT31(local_8._1_3_,0x1b);
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_64;
  local_34 = local_34 & 0xffff0000;
  local_20 = 7;
  local_24 = 0;
  uStack_98 = 0x658571;
  FUN_004026e0();
  local_18 = 0x101;
  if (7 < local_50) {
    pppuStack_90 = (undefined ***)0x658586;
    FUN_0089120c();
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = local_64 & 0xffff0000;
  local_8._0_1_ = 0x1c;
  local_48 = local_68 + 0x52;
  pppuStack_90 = (undefined ***)0x6585b1;
  FUN_0065afb0();
  iVar3 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  ppuStack_94 = (undefined1 **)&local_34;
  uStack_98 = 0x6585cb;
  FUN_004026e0();
  *(undefined1 *)(iVar3 + 0x1c) = (undefined1)local_18;
  *(undefined1 *)(iVar3 + 0x1d) = local_18._1_1_;
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x6585e9;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 2;
  local_40 = (undefined1 *)0x4;
  local_3c = (undefined1 *)0x20c;
  ppuStack_94 = (undefined1 **)0x658608;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658618;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x1d;
  pppuStack_90 = (undefined ***)0x65865d;
  FUN_0065afb0();
  local_3c = (undefined1 *)FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658675;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  local_3c[0x1c] = *(undefined1 *)(iVar3 + 0x1c);
  local_3c[0x1d] = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658696;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 3;
  local_40 = (undefined1 *)0x4;
  local_3c = (undefined1 *)0x20d;
  ppuStack_94 = (undefined1 **)0x6586b5;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x6586c5;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x1e;
  pppuStack_90 = (undefined ***)0x65870a;
  FUN_0065afb0();
  local_3c = (undefined1 *)FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658722;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  local_3c[0x1c] = *(undefined1 *)(iVar3 + 0x1c);
  local_3c[0x1d] = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658743;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 4;
  local_40 = (undefined1 *)0x4;
  local_3c = (undefined1 *)0x20e;
  ppuStack_94 = (undefined1 **)0x65875f;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x65876f;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x1f;
  pppuStack_90 = (undefined ***)0x6587b4;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x6587cc;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x6587ea;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 5;
  local_40 = (undefined1 *)0x4;
  local_3c = (undefined1 *)0x20f;
  ppuStack_94 = (undefined1 **)0x658809;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658819;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x20;
  pppuStack_90 = (undefined ***)0x65885e;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658876;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658894;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x0;
  local_44 = 0;
  local_40 = (undefined1 *)0x5;
  local_3c = (undefined1 *)0x210;
  ppuStack_94 = (undefined1 **)0x6588b5;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x6588c5;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x21;
  pppuStack_90 = (undefined ***)0x65890a;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658922;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658940;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 0;
  local_40 = (undefined1 *)0x6;
  local_3c = (undefined1 *)0x211;
  ppuStack_94 = (undefined1 **)0x65895f;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x65896f;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x22;
  pppuStack_90 = (undefined ***)0x6589b4;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x6589cc;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x6589ea;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 1;
  local_40 = (undefined1 *)0x6;
  local_3c = (undefined1 *)0x212;
  ppuStack_94 = (undefined1 **)0x658a05;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658a15;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x23;
  pppuStack_90 = (undefined ***)0x658a5a;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658a72;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658a90;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 0;
  local_40 = (undefined1 *)0x7;
  local_3c = (undefined1 *)0x213;
  ppuStack_94 = (undefined1 **)0x658aaf;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658abf;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x24;
  pppuStack_90 = (undefined ***)0x658b09;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658b21;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658b3f;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 1;
  local_40 = (undefined1 *)0x7;
  local_3c = (undefined1 *)0x214;
  ppuStack_94 = (undefined1 **)0x658b5a;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658b6a;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x25;
  local_48 = local_68 + 0x52;
  pppuStack_90 = (undefined ***)0x658bb7;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658bcf;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658bf1;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 2;
  local_40 = (undefined1 *)0x7;
  local_3c = (undefined1 *)0x215;
  ppuStack_94 = (undefined1 **)0x658c10;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658c20;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x26;
  pppuStack_90 = (undefined ***)0x658c64;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658c7c;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658c9a;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 0;
  local_40 = (undefined1 *)0x8;
  local_3c = (undefined1 *)0x216;
  ppuStack_94 = (undefined1 **)0x658cba;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658cca;
  FUN_005740f0();
  if (local_38 == *(int *)(iVar3 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar5 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  local_3c = auStack_ac;
  FUN_00402250(puVar5);
  iVar3 = FUN_00657540();
  local_8._0_1_ = 0x27;
  pppuStack_90 = (undefined ***)0x658d0e;
  FUN_0065afb0();
  iVar6 = FUN_0065b1f0();
  pppuStack_90 = (undefined ***)0x0;
  uStack_98 = 0x658d26;
  ppuStack_94 = (undefined1 **)iVar3;
  FUN_004026e0();
  *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
  *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
  local_8._0_1_ = 1;
  if (7 < local_20) {
    pppuStack_90 = (undefined ***)0x658d44;
    FUN_0089120c();
  }
  pppuStack_90 = (undefined ***)0x1;
  local_44 = 1;
  local_40 = (undefined1 *)0x8;
  local_3c = (undefined1 *)0x217;
  ppuStack_94 = (undefined1 **)0x658d60;
  iVar3 = FUN_00585620();
  ppuStack_94 = &local_3c;
  uStack_98 = 0x658d70;
  FUN_005740f0();
  if (local_38 != *(int *)(iVar3 + 4)) {
    puVar5 = (undefined4 *)(local_38 + 0x10);
    if (7 < *(uint *)(local_38 + 0x24)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    local_3c = auStack_ac;
    FUN_00402250(puVar5);
    iVar3 = FUN_00657540();
    local_8._0_1_ = 0x28;
    pppuStack_90 = (undefined ***)0x658db9;
    FUN_0065afb0();
    iVar6 = FUN_0065b1f0();
    pppuStack_90 = (undefined ***)0x0;
    uStack_98 = 0x658dd1;
    ppuStack_94 = (undefined1 **)iVar3;
    FUN_004026e0();
    *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
    *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
    local_8._0_1_ = 1;
    if (7 < local_20) {
      pppuStack_90 = (undefined ***)0x658def;
      FUN_0089120c();
    }
    pppuStack_90 = (undefined ***)0x1;
    ppuStack_94 = (undefined1 **)0x218;
    local_38 = 0;
    local_3c = (undefined1 *)0xb;
    uStack_98 = 0x658e0c;
    FUN_00585620();
    uStack_98 = 0x658e13;
    uVar7 = FUN_00585330();
    local_40 = auStack_ac;
    FUN_00402250(uVar7);
    iVar3 = FUN_00657540();
    local_8 = CONCAT31(local_8._1_3_,0x29);
    pppuStack_90 = (undefined ***)0x658e41;
    FUN_0065afb0();
    iVar6 = FUN_0065b1f0();
    pppuStack_90 = (undefined ***)0x0;
    uStack_98 = 0x658e59;
    ppuStack_94 = (undefined1 **)iVar3;
    FUN_004026e0();
    *(undefined1 *)(iVar6 + 0x1c) = *(undefined1 *)(iVar3 + 0x1c);
    *(undefined1 *)(iVar6 + 0x1d) = *(undefined1 *)(iVar3 + 0x1d);
    if (7 < local_20) {
      pppuStack_90 = (undefined ***)0x658e74;
      FUN_0089120c();
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

