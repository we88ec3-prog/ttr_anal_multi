
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007393e0(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  undefined4 in_stack_00000018;
  undefined4 in_stack_00000030;
  float in_stack_00000034;
  float in_stack_00000038;
  float in_stack_0000003c;
  float in_stack_00000040;
  uint local_34;
  uint local_2c;
  undefined1 local_24 [16];
  undefined1 local_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(char *)(in_ECX + 4) == '\x01') {
    FUN_007392e0(&stack0x0000001c,in_stack_00000030,&stack0x00000004,local_14);
    if ((DAT_00fe38c8 & 1) == 0) {
      DAT_00fe38c8 = DAT_00fe38c8 | 1;
    }
    if ((DAT_00fe38c8 & 2) == 0) {
      DAT_00fe38c8 = DAT_00fe38c8 | 2;
    }
    _DAT_00fe38c0 = 0;
    _DAT_00fe38bc = 0;
    _DAT_00fe38b8 = 0;
    _DAT_00fe38b4 = 0;
    _DAT_00fe38ac = 0;
    _DAT_00fe38a8 = 0;
    _DAT_00fe38a4 = 0;
    _DAT_00fe38a0 = 0;
    _DAT_00fe3898 = 0;
    _DAT_00fe3894 = 0;
    _DAT_00fe3890 = 0;
    _DAT_00fe388c = 0;
    _DAT_00fe38c4 = 0x3f800000;
    _DAT_00fe38b0 = 0x3f800000;
    _DAT_00fe389c = 0x3f800000;
    _DAT_00fe3888 = 0x3f800000;
    _DAT_00fe3884 = 0x3f800000;
    _DAT_00fe3870 = 0x3f800000;
    _DAT_00fe385c = 0x3f800000;
    _DAT_00fe3848 = 0x3f800000;
    _DAT_00fe3880 = 0;
    _DAT_00fe387c = 0;
    _DAT_00fe3878 = 0;
    _DAT_00fe3874 = 0;
    _DAT_00fe386c = 0;
    _DAT_00fe3868 = 0;
    _DAT_00fe3864 = 0;
    _DAT_00fe3860 = 0;
    _DAT_00fe3858 = 0;
    _DAT_00fe3854 = 0;
    _DAT_00fe3850 = 0;
    _DAT_00fe384c = 0;
    D3DXMatrixTransformation2D
              (&DAT_00fe3888,0,0,&stack0x00000010,0,in_stack_00000018,&stack0x00000004);
    (**(code **)(**(int **)(in_ECX + 8) + 0x14))(*(int **)(in_ECX + 8),&DAT_00fe3888);
    if (in_stack_00000034 < 1.0) {
      if (0.0 < in_stack_00000034) {
        local_34 = (uint)(longlong)ROUND(in_stack_00000034 * 255.0 + 0.5);
        uVar3 = local_34;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xff;
    }
    if (in_stack_00000038 < 1.0) {
      if (in_stack_00000038 < 0.0 == (in_stack_00000038 == 0.0)) {
        local_34 = (uint)(longlong)ROUND(in_stack_00000038 * 255.0 + 0.5);
        local_2c = local_34;
      }
      else {
        local_2c = 0;
      }
    }
    else {
      local_2c = 0xff;
    }
    if (in_stack_0000003c < 1.0) {
      if (in_stack_0000003c < 0.0 == (in_stack_0000003c == 0.0)) {
        local_34 = (uint)(longlong)ROUND(in_stack_0000003c * 255.0 + 0.5);
        uVar2 = local_34;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xff;
    }
    if (in_stack_00000040 < 1.0) {
      if (0.0 < in_stack_00000040) {
        local_34 = (uint)(longlong)ROUND(in_stack_00000040 * 255.0 + 0.5);
      }
      else {
        local_34 = 0;
      }
    }
    else {
      local_34 = 0xff;
    }
    iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))
                      (*(int **)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),local_24,local_14,0,
                       ((local_34 << 8 | uVar3) << 8 | local_2c) << 8 | uVar2);
    if (iVar1 < 0) {
      *(undefined1 *)(in_ECX + 4) = 0;
    }
    (**(code **)(**(int **)(in_ECX + 8) + 0x14))(*(int **)(in_ECX + 8),&DAT_00fe3848);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

