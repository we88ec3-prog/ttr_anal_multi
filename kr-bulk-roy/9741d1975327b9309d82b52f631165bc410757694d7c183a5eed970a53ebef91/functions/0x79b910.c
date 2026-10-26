
void FUN_0079b910(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uStack_138;
  undefined4 *puStack_134;
  undefined1 *puStack_130;
  undefined1 *puStack_12c;
  undefined4 *puStack_128;
  int *piStack_124;
  undefined4 uStack_120;
  undefined4 *puStack_11c;
  int *piStack_118;
  undefined4 uStack_114;
  undefined1 *puStack_110;
  int *piStack_10c;
  undefined4 uStack_108;
  undefined1 *puStack_104;
  int *piStack_100;
  int *piStack_fc;
  undefined4 uStack_f0;
  int *local_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 auStack_bc [20];
  undefined1 local_a8 [16];
  undefined1 auStack_98 [28];
  undefined1 auStack_7c [24];
  undefined1 auStack_64 [16];
  uint uStack_54;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&uStack_f0;
  iVar1 = *param_1;
  piVar2 = local_ec;
  if (*(int *)(iVar1 + 0xec) != 0) {
    piStack_fc = *(int **)(iVar1 + 0xec);
    piStack_100 = (int *)0x79b94b;
    (**(code **)(*piStack_fc + 4))();
    piVar2 = *(int **)(iVar1 + 0xec);
  }
  piStack_fc = (int *)local_a8;
  puStack_104 = (undefined1 *)0x79b967;
  piStack_100 = piVar2;
  (**(code **)(*piVar2 + 0xc0))();
  puStack_104 = auStack_98;
  uStack_108 = 2;
  puStack_110 = (undefined1 *)0x79b979;
  piStack_10c = piVar2;
  (**(code **)(*piVar2 + 0xb4))();
  puStack_110 = auStack_64;
  uStack_114 = 3;
  puStack_11c = (undefined4 *)0x79b98e;
  piStack_118 = piVar2;
  (**(code **)(*piVar2 + 0xb4))();
  uStack_d0 = 0;
  puStack_11c = &uStack_108;
  uStack_d4 = 0;
  uStack_d8 = 0;
  uStack_120 = 0x100;
  uStack_dc = 0;
  uStack_e4 = 0;
  uStack_e8 = 0;
  local_ec = (int *)0x0;
  uStack_f0 = 0;
  piStack_fc = (int *)0x0;
  piStack_100 = (int *)0x0;
  puStack_104 = (undefined1 *)0x0;
  uStack_cc = 0x3f800000;
  uStack_e0 = 0x3f800000;
  uStack_108 = 0x3f800000;
  puStack_128 = (undefined4 *)0x79b9e7;
  piStack_124 = piVar2;
  (**(code **)(*piVar2 + 0xb0))();
  puStack_128 = &uStack_114;
  puStack_12c = auStack_bc;
  puStack_130 = auStack_7c;
  puStack_134 = &uStack_d4;
  uStack_138 = param_2;
  D3DXVec3Project();
  (**(code **)(*piVar2 + 8))(piVar2);
  __security_check_cookie(uStack_54 ^ (uint)&uStack_138);
  return;
}

