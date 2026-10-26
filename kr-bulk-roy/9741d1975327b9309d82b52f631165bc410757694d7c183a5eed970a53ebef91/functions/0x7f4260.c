
void FUN_007f4260(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093760e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar4 = DAT_00fb76a8;
  local_8 = 0xffffffff;
  if (*(char *)(in_ECX + 0x34c) != '\0') {
    MessageBoxA((HWND)0x0,&DAT_00c50bcc,"Error",0);
    ExceptionList = local_10;
    return;
  }
  piVar5 = (int *)0x0;
  if (*(int *)(DAT_00fb76a8 + 0xec) != 0) {
    (**(code **)(**(int **)(DAT_00fb76a8 + 0xec) + 4))(*(int **)(DAT_00fb76a8 + 0xec));
    piVar5 = *(int **)(iVar4 + 0xec);
  }
  *(undefined1 *)(in_ECX + 0x34c) = 1;
  FUN_007f51a0();
  *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x24) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x40) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x44) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x60) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 100) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x80) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x84) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0xa0) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0xa4) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0xc0) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0xc4) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0xe0) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0xe4) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x100) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x104) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x120) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x124) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x140) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x144) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x160) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x164) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x180) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x184) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x1a0) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x1a4) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x1c0) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x1c4) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x1e0) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x1e4) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x200) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x204) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x220) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x224) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x240) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x244) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x260) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x264) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x280) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x284) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x2a0) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x2a4) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x2c0) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x2c4) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x2e0) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x2e4) = 1.0 - *(float *)(in_ECX + 0x344);
  *(float *)(in_ECX + 0x300) = *(float *)(in_ECX + 0x344) + 0.0;
  *(float *)(in_ECX + 0x304) = 1.0 - *(float *)(in_ECX + 0x344);
  fVar1 = -*(float *)(in_ECX + 0x340);
  fVar3 = *(float *)(in_ECX + 0x340) - *(float *)(in_ECX + 0x348);
  *(float *)(in_ECX + 8) = fVar1;
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x10) = fVar3;
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x340);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x30) = fVar3;
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x4c) = fVar1;
  *(float *)(in_ECX + 0x50) = fVar3;
  *(float *)(in_ECX + 0x68) = fVar1;
  *(float *)(in_ECX + 0x6c) = fVar1;
  *(float *)(in_ECX + 0x70) = fVar3;
  *(float *)(in_ECX + 0x88) = fVar1;
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x90) = fVar3;
  fVar2 = fVar1 - *(float *)(in_ECX + 0x348);
  *(float *)(in_ECX + 0xa8) = fVar1;
  *(float *)(in_ECX + 0xac) = fVar1;
  *(float *)(in_ECX + 0xb0) = fVar3;
  *(float *)(in_ECX + 200) = fVar1;
  *(float *)(in_ECX + 0xcc) = fVar1;
  *(float *)(in_ECX + 0xd0) = fVar2;
  *(float *)(in_ECX + 0xe8) = fVar1;
  *(undefined4 *)(in_ECX + 0xec) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0xf0) = fVar2;
  *(undefined4 *)(in_ECX + 0x108) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x10c) = fVar1;
  *(float *)(in_ECX + 0x110) = fVar3;
  *(undefined4 *)(in_ECX + 0x128) = *(undefined4 *)(in_ECX + 0x340);
  *(undefined4 *)(in_ECX + 300) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x130) = fVar3;
  *(undefined4 *)(in_ECX + 0x148) = *(undefined4 *)(in_ECX + 0x340);
  *(undefined4 *)(in_ECX + 0x14c) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x150) = fVar2;
  *(undefined4 *)(in_ECX + 0x168) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x16c) = fVar1;
  *(float *)(in_ECX + 0x170) = fVar2;
  *(float *)(in_ECX + 0x188) = fVar1;
  *(float *)(in_ECX + 0x18c) = fVar1;
  *(float *)(in_ECX + 400) = fVar3;
  *(undefined4 *)(in_ECX + 0x1a8) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x1ac) = fVar1;
  *(float *)(in_ECX + 0x1b0) = fVar3;
  *(undefined4 *)(in_ECX + 0x1c8) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x1cc) = fVar1;
  *(float *)(in_ECX + 0x1d0) = fVar2;
  *(float *)(in_ECX + 0x1e8) = fVar1;
  *(float *)(in_ECX + 0x1ec) = fVar1;
  *(float *)(in_ECX + 0x1f0) = fVar2;
  *(undefined4 *)(in_ECX + 0x208) = *(undefined4 *)(in_ECX + 0x340);
  *(undefined4 *)(in_ECX + 0x20c) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x210) = fVar3;
  *(float *)(in_ECX + 0x228) = fVar1;
  *(undefined4 *)(in_ECX + 0x22c) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x230) = fVar3;
  *(float *)(in_ECX + 0x248) = fVar1;
  *(undefined4 *)(in_ECX + 0x24c) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x250) = fVar2;
  *(undefined4 *)(in_ECX + 0x268) = *(undefined4 *)(in_ECX + 0x340);
  *(undefined4 *)(in_ECX + 0x26c) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x270) = fVar2;
  *(float *)(in_ECX + 0x288) = fVar1;
  *(float *)(in_ECX + 0x28c) = fVar1;
  *(float *)(in_ECX + 0x290) = fVar2;
  *(undefined4 *)(in_ECX + 0x2a8) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x2ac) = fVar1;
  *(float *)(in_ECX + 0x2b0) = fVar2;
  *(undefined4 *)(in_ECX + 0x2c8) = *(undefined4 *)(in_ECX + 0x340);
  *(undefined4 *)(in_ECX + 0x2cc) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x2d0) = fVar2;
  *(float *)(in_ECX + 0x2e8) = fVar1;
  *(undefined4 *)(in_ECX + 0x2ec) = *(undefined4 *)(in_ECX + 0x340);
  *(float *)(in_ECX + 0x2f0) = fVar2;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0xf8) = 0;
  *(undefined4 *)(in_ECX + 0xd8) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  *(undefined4 *)(in_ECX + 0xdc) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)(in_ECX + 0x174) = 0;
  *(undefined4 *)(in_ECX + 0x154) = 0;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x178) = 0;
  *(undefined4 *)(in_ECX + 0x158) = 0;
  *(undefined4 *)(in_ECX + 0x138) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  *(undefined4 *)(in_ECX + 0x17c) = 0;
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x274) = 0;
  *(undefined4 *)(in_ECX + 0x254) = 0;
  *(undefined4 *)(in_ECX + 0x234) = 0;
  *(undefined4 *)(in_ECX + 0x214) = 0;
  *(undefined4 *)(in_ECX + 0x278) = 0;
  *(undefined4 *)(in_ECX + 600) = 0;
  *(undefined4 *)(in_ECX + 0x238) = 0;
  *(undefined4 *)(in_ECX + 0x218) = 0;
  *(undefined4 *)(in_ECX + 0x27c) = 0;
  *(undefined4 *)(in_ECX + 0x25c) = 0;
  *(undefined4 *)(in_ECX + 0x23c) = 0;
  *(undefined4 *)(in_ECX + 0x21c) = 0;
  puVar6 = (undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 500) = 0;
  *(undefined4 *)(in_ECX + 0x1d4) = 0;
  *(undefined4 *)(in_ECX + 0x1b4) = 0;
  *(undefined4 *)(in_ECX + 0x194) = 0;
  *(undefined4 *)(in_ECX + 0x1f8) = 0;
  *(undefined4 *)(in_ECX + 0x1d8) = 0;
  *(undefined4 *)(in_ECX + 0x1b8) = 0;
  *(undefined4 *)(in_ECX + 0x198) = 0;
  *(undefined4 *)(in_ECX + 0x1fc) = 0;
  *(undefined4 *)(in_ECX + 0x1dc) = 0;
  *(undefined4 *)(in_ECX + 0x1bc) = 0;
  *(undefined4 *)(in_ECX + 0x19c) = 0;
  *(undefined4 *)(in_ECX + 0x2f4) = 0;
  *(undefined4 *)(in_ECX + 0x2d4) = 0;
  *(undefined4 *)(in_ECX + 0x2b4) = 0;
  *(undefined4 *)(in_ECX + 0x294) = 0;
  *(undefined4 *)(in_ECX + 0x2f8) = 0;
  *(undefined4 *)(in_ECX + 0x2d8) = 0;
  *(undefined4 *)(in_ECX + 0x2b8) = 0;
  *(undefined4 *)(in_ECX + 0x298) = 0;
  *(undefined4 *)(in_ECX + 0x2fc) = 0;
  *(undefined4 *)(in_ECX + 0x2dc) = 0;
  *(undefined4 *)(in_ECX + 700) = 0;
  *(undefined4 *)(in_ECX + 0x29c) = 0;
  local_14 = puVar6;
  (**(code **)(*piVar5 + 0x68))(piVar5,0x300,0,0x112,1,puVar6,0);
  (**(code **)(*(int *)*puVar6 + 0x2c))((int *)*puVar6,0,0,&local_18,0);
  puVar6 = (undefined4 *)(in_ECX + 8);
  for (iVar4 = 0xc0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *local_18 = *puVar6;
    puVar6 = puVar6 + 1;
    local_18 = local_18 + 1;
  }
  (**(code **)(*(int *)*local_14 + 0x30))((int *)*local_14);
  (**(code **)(*piVar5 + 8))(piVar5);
  ExceptionList = local_10;
  return;
}

