
void FUN_007f4d90(int param_1)

{
  int in_ECX;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  int *piStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  int *piStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  int *piStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  int *piStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  int *piStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  int *piStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  int *piStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  int *piStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  int *piStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int *piStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  int *piStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  int *piStack_140;
  uint uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  int *piStack_12c;
  undefined4 uStack_128;
  int *piStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int *piStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  int *piStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  int *piStack_100;
  undefined4 uStack_fc;
  int *piStack_f8;
  undefined4 uStack_f4;
  int *piStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  int *piStack_e0;
  undefined4 uStack_dc;
  undefined4 *puStack_d8;
  undefined1 auStack_b4 [4];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  uint local_1c;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092b93c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_b4;
  ExceptionList = &local_14;
  if ((*(char *)(in_ECX + 0x34c) != '\0') && (*(int *)(in_ECX + 0x354) != 0)) {
    piVar2 = (int *)0x0;
    if (*(int *)(param_1 + 0xec) != 0) {
      (**(code **)(**(int **)(param_1 + 0xec) + 4))();
      piVar2 = *(int **)(param_1 + 0xec);
    }
    (**(code **)(*piVar2 + 0xb4))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_18 = 0;
      FUN_00798de0();
      puStack_d8 = (undefined4 *)0x7f4e49;
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_18 = 0xffffffff;
    }
    puStack_d8 = (undefined4 *)0x7f4e64;
    (**(code **)(*DAT_00fb773c + 0x10))();
    uStack_78 = 0;
    puStack_d8 = &uStack_b0;
    uStack_7c = 0;
    uStack_80 = 0;
    uStack_dc = 0x100;
    uStack_84 = 0;
    uStack_8c = 0;
    uStack_90 = 0;
    uStack_94 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    uStack_a4 = 0;
    uStack_a8 = 0;
    uStack_ac = 0;
    uStack_74 = 0x3f800000;
    uStack_88 = 0x3f800000;
    uStack_9c = 0x3f800000;
    uStack_b0 = 0x3f800000;
    uStack_e4 = 0x7f4ebd;
    piStack_e0 = piVar2;
    (**(code **)(*piVar2 + 0xb0))();
    uStack_e4 = 0;
    uStack_e8 = 0xb;
    uStack_ec = 0;
    uStack_f4 = 0x7f4ece;
    piStack_f0 = piVar2;
    (**(code **)(*piVar2 + 0x10c))();
    uStack_f4 = 0;
    uStack_fc = 0x7f4edb;
    piStack_f8 = piVar2;
    (**(code **)(*piVar2 + 0x170))();
    uStack_fc = 0;
    uStack_104 = 0x7f4ee8;
    piStack_100 = piVar2;
    (**(code **)(*piVar2 + 0x1a0))();
    uStack_104 = 0;
    uStack_108 = 0;
    uStack_110 = 0x7f4ef7;
    piStack_10c = piVar2;
    (**(code **)(*piVar2 + 0x104))();
    uStack_110 = 0;
    uStack_114 = 1;
    uStack_11c = 0x7f4f06;
    piStack_118 = piVar2;
    (**(code **)(*piVar2 + 0x104))();
    uStack_11c = 0;
    uStack_120 = 2;
    uStack_128 = 0x7f4f15;
    piStack_124 = piVar2;
    (**(code **)(*piVar2 + 0x104))();
    uStack_128 = 0x112;
    uStack_130 = 0x7f4f25;
    piStack_12c = piVar2;
    (**(code **)(*piVar2 + 0x164))();
    uStack_138 = *(undefined4 *)(in_ECX + 4);
    uStack_130 = 0x20;
    uStack_134 = 0;
    uStack_13c = 0;
    uStack_144 = 0x7f4f3a;
    piStack_140 = piVar2;
    (**(code **)(*piVar2 + 400))();
    uStack_144 = 0;
    uStack_148 = 0xe;
    uStack_150 = 0x7f4f49;
    piStack_14c = piVar2;
    (**(code **)(*piVar2 + 0xe4))();
    uStack_13c = *(uint *)(in_ECX + 0x350) >> 0x18;
    piStack_12c = (int *)((float)uStack_13c * 0.003921569);
    piStack_164 = piVar2;
    piStack_158 = piVar2;
    if (1.0 <= (float)piStack_12c) {
      uStack_150 = 0;
      uStack_154 = 0x1b;
      uStack_15c = 0x7f501c;
      (**(code **)(*piVar2 + 0xe4))();
      uStack_15c = 0;
      uStack_160 = 0xf;
      uStack_168 = 0x7f502b;
      (**(code **)(*piVar2 + 0xe4))();
    }
    else {
      uStack_150 = 1;
      uStack_154 = 0x1b;
      uStack_15c = 0x7f4f84;
      (**(code **)(*piVar2 + 0xe4))();
      uStack_15c = 5;
      uStack_160 = 0x13;
      uStack_168 = 0x7f4f93;
      (**(code **)(*piVar2 + 0xe4))();
      uStack_168 = 6;
      uStack_16c = 0x14;
      uStack_174 = 0x7f4fa2;
      piStack_170 = piVar2;
      (**(code **)(*piVar2 + 0xe4))();
      uStack_174 = 5;
      uStack_178 = 1;
      uStack_17c = 0;
      uStack_184 = 0x7f4fb3;
      piStack_180 = piVar2;
      (**(code **)(*piVar2 + 0x10c))();
      uStack_184 = 2;
      uStack_188 = 2;
      uStack_18c = 0;
      uStack_194 = 0x7f4fc4;
      piStack_190 = piVar2;
      (**(code **)(*piVar2 + 0x10c))();
      uStack_194 = 3;
      uStack_198 = 3;
      uStack_19c = 0;
      uStack_1a4 = 0x7f4fd5;
      piStack_1a0 = piVar2;
      (**(code **)(*piVar2 + 0x10c))();
      uStack_1a4 = 4;
      uStack_1a8 = 4;
      uStack_1ac = 0;
      uStack_1b4 = 0x7f4fe6;
      piStack_1b0 = piVar2;
      (**(code **)(*piVar2 + 0x10c))();
      uStack_1b4 = 3;
      uStack_1b8 = 5;
      uStack_1bc = 0;
      uStack_1c4 = 0x7f4ff7;
      piStack_1c0 = piVar2;
      (**(code **)(*piVar2 + 0x10c))();
      uStack_1c4 = *(undefined4 *)(in_ECX + 0x350);
      uStack_1c8 = 0x3c;
      uStack_1d0 = 0x7f500b;
      piStack_1cc = piVar2;
      (**(code **)(*piVar2 + 0xe4))();
    }
    uStack_1d0 = 0;
    uStack_1d4 = 0x89;
    uStack_1dc = 0x7f503d;
    piStack_1d8 = piVar2;
    (**(code **)(*piVar2 + 0xe4))();
    uStack_1dc = 0;
    uStack_1e0 = 0x1c;
    (**(code **)(*piVar2 + 0xe4))(piVar2);
    (**(code **)(*piVar2 + 0x114))(piVar2,0,1,3);
    (**(code **)(*piVar2 + 0x114))(piVar2,0,2,3);
    (**(code **)(*piVar2 + 0x114))(piVar2,0,5,2);
    (**(code **)(*piVar2 + 0x114))(piVar2,0,6,2);
    (**(code **)(*piVar2 + 0x114))(piVar2,0,7,0);
    (**(code **)(*piVar2 + 0x10c))(piVar2,0,0x18,0);
    uStack_1a8 = 0;
    uStack_1ac = 0;
    piStack_1b0 = (int *)0x0;
    iVar4 = 2;
    (**(code **)(*piVar2 + 0xb0))(piVar2,2,&uStack_1e0);
    piVar1 = (int *)(in_ECX + 0x308);
    iVar3 = 6;
    do {
      if (*piVar1 != 0) {
        (**(code **)(*piVar2 + 0x104))(piVar2,0,*piVar1);
        (**(code **)(*piVar2 + 0x144))(piVar2,6,iVar4 + (int)piVar1,2);
      }
      piVar1 = piVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_198 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_198 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x14))(DAT_00fb773c);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_b4);
  return;
}

