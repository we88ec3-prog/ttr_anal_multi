
void FUN_007f9bf0(void)

{
  int in_ECX;
  int *piStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  int *piStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  int *piStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  int *piStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  int *piStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  int *piStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  int *piStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  int *piStack_11c;
  undefined4 uStack_118;
  float fStack_114;
  int *piStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  int *piStack_104;
  float fStack_100;
  undefined4 uStack_fc;
  int *piStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  int *piStack_ec;
  undefined4 uStack_e8;
  undefined1 *puStack_e4;
  int *piStack_e0;
  undefined4 uStack_dc;
  int **ppiStack_d8;
  int *piStack_c0;
  undefined4 uStack_bc;
  undefined1 *puStack_b8;
  uint uStack_b4;
  undefined1 auStack_a8 [8];
  undefined1 local_a0 [20];
  undefined1 auStack_8c [100];
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092b87c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_a8;
  uStack_b4 = DAT_00d61f20 ^ (uint)&stack0xffffff50;
  ExceptionList = &local_14;
  piStack_c0 = *(int **)(in_ECX + 4);
  puStack_b8 = local_a0;
  uStack_bc = 2;
  (**(code **)(*piStack_c0 + 0xb4))();
  (**(code **)(**(int **)(in_ECX + 4) + 0xb4))();
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    uStack_24 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    uStack_24 = 0xffffffff;
  }
  (**(code **)(*DAT_00fb773c + 0x10))();
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    uStack_28 = 1;
    FUN_00798de0();
    ppiStack_d8 = (int **)0x7f9cc7;
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    uStack_28 = 0xffffffff;
  }
  ppiStack_d8 = (int **)0x7f9ce2;
  (**(code **)(*DAT_00fb7738 + 0x14))();
  piStack_e0 = *(int **)(in_ECX + 4);
  ppiStack_d8 = &piStack_c0;
  uStack_dc = 2;
  puStack_e4 = (undefined1 *)0x7f9cf7;
  (**(code **)(*piStack_e0 + 0xb0))();
  piStack_ec = *(int **)(in_ECX + 4);
  puStack_e4 = auStack_8c;
  uStack_e8 = 3;
  uStack_f0 = 0x7f9d0c;
  (**(code **)(*piStack_ec + 0xb0))();
  piStack_f8 = *(int **)(in_ECX + 4);
  uStack_f0 = 0;
  uStack_f4 = 0x89;
  uStack_fc = 0x7f9d21;
  (**(code **)(*piStack_f8 + 0xe4))();
  piStack_104 = *(int **)(in_ECX + 4);
  uStack_fc = 1;
  fStack_100 = 2.18603e-43;
  uStack_108 = 0x7f9d35;
  (**(code **)(*piStack_104 + 0xe4))();
  piStack_110 = *(int **)(in_ECX + 4);
  uStack_108 = 1;
  uStack_10c = 0x9d;
  fStack_114 = 1.1719531e-38;
  (**(code **)(*piStack_110 + 0xe4))();
  fStack_114 = *(float *)(in_ECX + 0xc0) * *(float *)(in_ECX + 0x3c);
  piStack_11c = *(int **)(in_ECX + 4);
  uStack_118 = 0x9a;
  uStack_120 = 0x7f9d6e;
  fStack_100 = fStack_114;
  (**(code **)(*piStack_11c + 0xe4))();
  piStack_128 = *(int **)(in_ECX + 4);
  uStack_10c = 0;
  uStack_120 = 0;
  uStack_124 = 0x9b;
  uStack_12c = 0x7f9d8c;
  (**(code **)(*piStack_128 + 0xe4))();
  piStack_134 = *(int **)(in_ECX + 4);
  uStack_118 = 0;
  uStack_12c = 0;
  uStack_130 = 0x9e;
  uStack_138 = 0x7f9daa;
  (**(code **)(*piStack_134 + 0xe4))();
  piStack_140 = *(int **)(in_ECX + 4);
  uStack_124 = 0;
  uStack_138 = 0;
  uStack_13c = 0x9f;
  uStack_144 = 0x7f9dc8;
  (**(code **)(*piStack_140 + 0xe4))();
  piStack_14c = *(int **)(in_ECX + 4);
  uStack_130 = 0x3f800000;
  uStack_144 = 0x3f800000;
  uStack_148 = 0xa0;
  uStack_150 = 0x7f9de6;
  (**(code **)(*piStack_14c + 0xe4))();
  piStack_15c = *(int **)(in_ECX + 4);
  uStack_150 = 2;
  uStack_154 = 5;
  uStack_158 = 0;
  uStack_160 = 0x7f9dfa;
  (**(code **)(*piStack_15c + 0x10c))();
  piStack_16c = *(int **)(in_ECX + 4);
  uStack_160 = 2;
  uStack_164 = 4;
  uStack_168 = 0;
  uStack_170 = 0x7f9e0e;
  (**(code **)(*piStack_16c + 0x10c))();
  piStack_178 = *(int **)(in_ECX + 4);
  uStack_170 = 1;
  uStack_174 = 0x1b;
  (**(code **)(*piStack_178 + 0xe4))();
  (**(code **)(**(int **)(in_ECX + 4) + 0xe4))(*(int **)(in_ECX + 4),0xe,0);
  ExceptionList = puStack_e4;
  __security_check_cookie((uint)piStack_ec ^ (uint)&piStack_178);
  return;
}

