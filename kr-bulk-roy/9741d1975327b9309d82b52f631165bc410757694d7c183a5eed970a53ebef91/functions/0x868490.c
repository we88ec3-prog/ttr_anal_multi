
void FUN_00868490(undefined4 param_1)

{
  code *pcVar1;
  undefined4 ****ppppuVar2;
  int in_ECX;
  uint uStack_16c;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 local_154;
  undefined4 uStack_14c;
  undefined1 auStack_148 [4];
  undefined **appuStack_144 [2];
  undefined1 local_13c [8];
  undefined **appuStack_134 [4];
  undefined **appuStack_124 [4];
  undefined **appuStack_114 [4];
  undefined **appuStack_104 [4];
  undefined **appuStack_f4 [4];
  undefined **appuStack_e4 [4];
  undefined **appuStack_d4 [4];
  undefined **appuStack_c4 [4];
  undefined **appuStack_b4 [8];
  undefined4 uStack_94;
  undefined1 local_84;
  uint uStack_80;
  undefined4 ***pppuStack_78;
  undefined4 local_74;
  undefined4 local_70;
  int iStack_68;
  uint uStack_64;
  undefined4 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_3c;
  uint uStack_2c;
  void *pvStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0091c2c1;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_15c;
  uStack_16c = DAT_00d61f20 ^ (uint)&stack0xfffffe98;
  ExceptionList = &local_14;
  local_154 = param_1;
  local_70 = 0xf;
  local_74 = 0;
  local_84 = 0;
  local_c = 0;
  FUN_00781ea0();
  FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),local_13c,4,0);
  switch(uStack_14c) {
  case 1:
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  case 2:
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&stack0xfffffea0,4,0);
    FUN_00867960(appuStack_d4,&stack0xfffffea0);
    local_1c = CONCAT31(local_1c._1_3_,2);
    FUN_00867730();
    appuStack_d4[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 3:
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&stack0xfffffea0,4,0);
    FUN_008679b0(appuStack_114,&stack0xfffffea0);
    local_1c = CONCAT31(local_1c._1_3_,3);
    FUN_00867730();
    appuStack_114[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 4:
    uStack_64 = 0xf;
    iStack_68 = 0;
    pppuStack_78 = (undefined4 ***)((uint)pppuStack_78._1_3_ << 8);
    local_1c._0_1_ = 4;
    FUN_00781ea0();
    ppppuVar2 = (undefined4 ****)pppuStack_78;
    if (uStack_64 < 0x10) {
      ppppuVar2 = &pppuStack_78;
    }
    FUN_00867a50(appuStack_144,ppppuVar2);
    local_1c = CONCAT31(local_1c._1_3_,5);
    FUN_00867730();
    appuStack_144[0] = gbParam::vftable;
    goto LAB_00868ab1;
  case 5:
    uStack_15c = 0;
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&stack0xfffffea0,8,0);
    FUN_00867b20(appuStack_f4,&stack0xfffffea0);
    local_1c = CONCAT31(local_1c._1_3_,6);
    FUN_00867730();
    appuStack_f4[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 6:
    uStack_15c = 0;
    uStack_158 = 0;
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&stack0xfffffea0,0xc,0);
    FUN_00867ab0(appuStack_b4,&stack0xfffffea0);
    local_1c = CONCAT31(local_1c._1_3_,7);
    FUN_00867730();
    appuStack_b4[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 7:
    uStack_15c = 0;
    uStack_158 = 0;
    local_154 = 0x3f800000;
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&stack0xfffffea0,0x10,0);
    FUN_00867b90(appuStack_134,&stack0xfffffea0);
    local_1c = CONCAT31(local_1c._1_3_,8);
    FUN_00867730();
    appuStack_134[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 8:
    _memset(&pppuStack_78,0,0x34);
    uStack_58 = 0x3f800000;
    iStack_68 = 0x3f800000;
    pppuStack_78 = (undefined4 ****)0x3f800000;
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&pppuStack_78,0x34,0);
    FUN_00867c10(appuStack_124,&pppuStack_78);
    local_1c = CONCAT31(local_1c._1_3_,9);
    FUN_00867730();
    appuStack_124[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 9:
    _memset(&pppuStack_78,0,0x44);
    uStack_3c = 0x3f800000;
    uStack_50 = 0x3f800000;
    uStack_64 = 0x3f800000;
    pppuStack_78 = (undefined4 ****)0x3f800000;
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&pppuStack_78,0x44,0);
    FUN_00867c90(appuStack_104,&pppuStack_78);
    local_1c = CONCAT31(local_1c._1_3_,10);
    FUN_00867730();
    appuStack_104[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 10:
    FUN_006ddcc0(*(undefined4 *)(in_ECX + 0x84),&stack0xfffffea0,8,0);
    FUN_00867a00(appuStack_e4,&stack0xfffffea0);
    local_1c = CONCAT31(local_1c._1_3_,0xb);
    FUN_00867730();
    appuStack_e4[0] = gbParam::vftable;
    FUN_00867f40();
    break;
  case 0xb:
    uStack_64 = 0xf;
    iStack_68 = 0;
    pppuStack_78 = (undefined4 ***)((uint)pppuStack_78._1_3_ << 8);
    local_1c = CONCAT31(local_1c._1_3_,0xc);
    FUN_00781ea0();
    if (iStack_68 != 0) {
      ppppuVar2 = (undefined4 ****)pppuStack_78;
      if (uStack_64 < 0x10) {
        ppppuVar2 = &pppuStack_78;
      }
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x54))(auStack_148,ppppuVar2);
    }
    FUN_00867d10(appuStack_c4,&stack0xfffffea0);
    local_1c = CONCAT31(local_1c._1_3_,0xd);
    FUN_00867730();
    appuStack_c4[0] = gbParam::vftable;
LAB_00868ab1:
    FUN_00867f40();
    FUN_00402c50();
    break;
  default:
    if (0xf < uStack_80) {
      FUN_0089120c(uStack_94);
    }
    goto LAB_00868aff;
  }
  if (0xf < uStack_80) {
    FUN_0089120c(uStack_94);
  }
LAB_00868aff:
  ExceptionList = pvStack_24;
  __security_check_cookie(uStack_2c ^ (uint)&uStack_16c);
  return;
}

