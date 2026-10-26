
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00598890(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *in_ECX;
  int *piStack_58;
  int *piStack_54;
  int *piStack_50;
  int *piStack_4c;
  int *piStack_48;
  int *piStack_44;
  int *piStack_40;
  int *piStack_3c;
  int *piStack_38;
  int *piStack_34;
  int *piStack_30;
  undefined **local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093f8a2;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_005a3980(DAT_00d61f20 ^ (uint)&stack0xffffff90);
  if ((_DAT_00f8d910 & 1) == 0) {
    _DAT_00f8d910 = _DAT_00f8d910 | 1;
    _atexit((_func_4879 *)&DAT_00bccc60);
  }
  FUN_006cb750(&DAT_00f8d914);
  if ((_DAT_00f8d8a8 & 1) == 0) {
    _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
    FUN_005e93a0();
    _atexit((_func_4879 *)&DAT_00bccc40);
  }
  FUN_005e9720();
  if ((_DAT_00fc0db0 & 1) == 0) {
    _DAT_00fc0db0 = _DAT_00fc0db0 | 1;
    DAT_00fc0db4 = 0;
    DAT_00fc0db8 = 0;
    DAT_00fc0dbc = 0;
    DAT_00fc0dc0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd9e0);
  }
  FUN_0060c4d0(&DAT_00fc0db4);
  if ((_DAT_00fe2c60 & 1) == 0) {
    _DAT_00fe2c60 = _DAT_00fe2c60 | 1;
    DAT_00fe2c64 = 0;
    _atexit((_func_4879 *)&DAT_00bcf430);
  }
  FUN_006bee30();
  if ((_DAT_00fe2c78 & 1) == 0) {
    _DAT_00fe2c78 = _DAT_00fe2c78 | 1;
    DAT_00fe2c7c = 0;
    _atexit((_func_4879 *)&DAT_00bcf440);
  }
  FUN_006ca6f0(&DAT_00fe2c7c);
  if ((_DAT_00fe2c68 & 1) == 0) {
    _DAT_00fe2c68 = _DAT_00fe2c68 | 1;
    DAT_00fe2c6c = 0;
    _atexit((_func_4879 *)&DAT_00bcf450);
  }
  FUN_004649d0(&DAT_00fe2c6c);
  if ((_DAT_00fbacd8 & 1) == 0) {
    _DAT_00fbacd8 = _DAT_00fbacd8 | 1;
    _DAT_00fbacdc = 0;
    _DAT_00fbace0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd6c0);
  }
  FUN_00479ec0();
  if ((_DAT_00fe2c70 & 1) == 0) {
    _DAT_00fe2c70 = _DAT_00fe2c70 | 1;
    DAT_00fe2c74 = 0;
    _atexit((_func_4879 *)&DAT_00bcf460);
  }
  FUN_004a7500(&DAT_00fe2c74);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_2c = FUI::CFXUIBinder::vftable;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  FUN_0059e0b0();
  FUN_005a9f40(in_ECX + 0x5a);
  FUN_0059e190();
  FUN_005a9f40(in_ECX + 0x5f);
  FUN_0059e270();
  FUN_005a9f40(in_ECX + 0x5e);
  FUN_0059e350();
  FUN_005a9f40(in_ECX + 0x5c);
  FUN_0059e430();
  FUN_005a9f40(in_ECX + 0x5d);
  (**(code **)(*in_ECX + 0x1a4))();
  FUN_005a9f40(in_ECX + 0x59);
  FUN_0059e510();
  FUN_005a9f40(in_ECX + 0x5b);
  FUN_0059e5f0();
  FUN_005a9f40(in_ECX + 0x60);
  FUN_0059e6d0();
  FUN_005a9f40(in_ECX + 0x61);
  FUN_0059e7b0();
  FUN_005a9f40(in_ECX + 0x62);
  FUN_0059e890();
  FUN_005a9f40(in_ECX + 99);
  piStack_58 = in_ECX + 0x65;
  FUN_0059e970();
  FUN_005a9f40(in_ECX + 0x65);
  FUN_0059ea50();
  FUN_005a9f40(in_ECX + 0x66);
  FUN_0059eb30();
  FUN_005a9f40(in_ECX + 0x67);
  FUN_0059ec10();
  FUN_005a9f40(in_ECX + 0x68);
  FUN_0059ecf0();
  FUN_005a9f40(in_ECX + 100);
  FUN_0059edd0();
  FUN_005a9f40(in_ECX + 0x69);
  piStack_54 = in_ECX + 0x6a;
  FUN_0059eeb0();
  FUN_005a9f40(in_ECX + 0x6a);
  piStack_50 = in_ECX + 0x6b;
  FUN_0059ef90();
  FUN_005a9f40(in_ECX + 0x6b);
  piStack_4c = in_ECX + 0x6c;
  FUN_0059f070();
  FUN_005a9f40(in_ECX + 0x6c);
  FUN_0059f150();
  FUN_005a9f40(in_ECX + 0x6d);
  piStack_3c = in_ECX + 0x6e;
  FUN_0059f230();
  FUN_005a9f40(in_ECX + 0x6e);
  FUN_0059f310();
  FUN_005a9f40(in_ECX + 0x6f);
  piStack_48 = in_ECX + 0x70;
  FUN_0059f3f0();
  FUN_005a9f40(in_ECX + 0x70);
  piStack_40 = in_ECX + 0x71;
  FUN_0059f4d0();
  FUN_005a9f40(in_ECX + 0x71);
  FUN_0059f5b0();
  FUN_005a9f40(in_ECX + 0x72);
  piVar1 = in_ECX + 0x73;
  FUN_0059f690();
  FUN_005a9f40(piVar1);
  piVar2 = in_ECX + 0x74;
  FUN_0059f770();
  FUN_005a9f40(piVar2);
  piStack_34 = in_ECX + 0x75;
  FUN_0059f850();
  FUN_005a9f40(in_ECX + 0x75);
  FUN_0059f930();
  FUN_005a9f40(in_ECX + 0x83);
  FUN_0059fa10();
  FUN_005a9f40(in_ECX + 0x76);
  FUN_0059faf0();
  FUN_005a9f40(in_ECX + 0x77);
  FUN_0059fbd0();
  FUN_005a9f40(in_ECX + 0x78);
  FUN_0059fcb0();
  FUN_005a9f40(in_ECX + 0x7a);
  FUN_0059fd90();
  FUN_005a9f40(in_ECX + 0x7b);
  FUN_0059fe70();
  FUN_005a9f40(in_ECX + 0x79);
  FUN_0059ff50();
  FUN_005a9f40(in_ECX + 0x7c);
  FUN_005a0030();
  FUN_005a9f40(in_ECX + 0x7d);
  FUN_005a0110();
  FUN_005a9f40(in_ECX + 0x7f);
  FUN_005a01f0();
  FUN_005a9f40(in_ECX + 0x80);
  FUN_005a02d0();
  FUN_005a9f40(in_ECX + 0x81);
  FUN_005a03b0();
  FUN_005a9f40(in_ECX + 0x82);
  FUN_005a0490();
  FUN_005a9f40(in_ECX + 0x84);
  FUN_005a0570();
  FUN_005a9f40(in_ECX + 0x85);
  FUN_005a0650();
  FUN_005a9f40(in_ECX + 0x7e);
  FUN_005a0730();
  FUN_005a9f40(in_ECX + 0x86);
  FUN_0040b670(in_ECX);
  *(int *)(in_ECX[0x60] + 0x124) = in_ECX[0x61];
  *(int *)(in_ECX[0x60] + 0x128) = in_ECX[0x62];
  *(int *)(in_ECX[0x61] + 0xf4) = in_ECX[0x60];
  *(int *)(in_ECX[0x62] + 0xf4) = in_ECX[0x60];
  (**(code **)(*(int *)in_ECX[0x59] + 0xd0))();
  uVar7 = DAT_00fb8828 & 1;
  *(int *)(in_ECX[0x7a] + 0x110) = in_ECX[0x7b];
  if (uVar7 == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 2;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c._0_1_ = 1;
  }
  if (DAT_00fb92fd != '\0') {
    (**(code **)(*(int *)in_ECX[0x77] + 0xd0))();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c._0_1_ = 1;
  }
  *(undefined4 *)(in_ECX[0x86] + 0x108) = DAT_00f94310;
  FUN_00596d70(in_ECX,in_ECX[0x66],1,0,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x67],1,0,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[99],1,1,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x85],1,0,0,0,0);
  piVar3 = in_ECX + 0x69;
  FUN_00596d70(in_ECX,in_ECX[0x69],0,0,1,0,0);
  piStack_44 = in_ECX + 0x6d;
  FUN_00596d70(in_ECX,*piStack_44,0,0,1,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x84],0,0,1,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x60],0,0,1,0,0);
  piStack_38 = in_ECX + 0x72;
  FUN_00596d70(in_ECX,*piStack_38,0,0,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[100],0,0,1,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x68],1,0,1,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x7e],1,1,0,1,0x11);
  FUN_00596d70(in_ECX,in_ECX[0x78],1,1,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x7a],1,1,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x79],1,1,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x7c],0,0,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x82],1,1,0,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x83],0,0,0,0,0);
  piStack_30 = in_ECX + 0x5a;
  FUN_00596d70(in_ECX,*piStack_30,0,0,0,0,0);
  piVar4 = in_ECX + 0x5c;
  FUN_00596d70(in_ECX,*piVar4,0,0,1,0,0);
  FUN_00596d70(in_ECX,in_ECX[0x86],0,0,1,0,0);
  piStack_58 = (int *)*piStack_58;
  iVar5 = in_ECX[99];
  piStack_58[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_58);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_54 = (int *)*piStack_54;
  iVar5 = *piVar3;
  piStack_54[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_54);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_50 = (int *)*piStack_50;
  iVar5 = *piVar3;
  piStack_50[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_50);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_4c = (int *)*piStack_4c;
  iVar5 = *piVar3;
  piStack_4c[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_4c);
  piVar3 = piStack_44;
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_48 = (int *)*piStack_48;
  iVar5 = *piStack_44;
  piStack_48[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_48);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_40 = (int *)*piStack_40;
  iVar5 = *piVar3;
  piStack_40[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_40);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_3c = (int *)*piStack_3c;
  iVar5 = *piVar3;
  piStack_3c[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_3c);
  piVar3 = piStack_38;
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_3c = (int *)*piVar1;
  iVar5 = *piStack_38;
  piStack_3c[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_3c);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_38 = (int *)*piVar2;
  iVar5 = *piVar3;
  piStack_38[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_38);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  piStack_34 = (int *)*piStack_34;
  iVar5 = *piVar4;
  piStack_34[0x1c] = iVar5;
  iVar6 = *(int *)(iVar5 + 0x74);
  iVar8 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&piStack_34);
  if (*(int *)(iVar5 + 0x78) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  uVar7 = DAT_00faaf7c & 1;
  *(int *)(iVar5 + 0x78) = *(int *)(iVar5 + 0x78) + 1;
  *(int *)(iVar6 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  if (uVar7 == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 4;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*piStack_30);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 5;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*piVar4);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 6;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*piVar3);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 7;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*piVar1);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 8;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*piVar2);
  local_2c = FoxUI::FXUIBinderBase::vftable;
  if (local_28 != 0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

