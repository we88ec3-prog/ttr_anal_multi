
undefined4 * FUN_00854e20(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918167;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00843b20(param_1,in_ECX);
  local_8 = 0;
  *param_1 = gbStdMaterial::vftable;
  param_1[99] = 0;
  uVar2 = FUN_007b2620(uVar1);
  param_1[0x62] = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(undefined4 *)(param_1[0x62] + 4) = param_1[0x62];
  *(undefined4 *)(param_1[0x62] + 8) = param_1[0x62];
  *(undefined1 *)(param_1[0x62] + 0x38) = 1;
  *(undefined1 *)(param_1[0x62] + 0x39) = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  param_1[0x65] = 0x3f800000;
  param_1[0x66] = 0x3f800000;
  param_1[0x67] = 0x3f800000;
  param_1[0x68] = 0x3f800000;
  param_1[0x69] = 0x3f800000;
  param_1[0x6a] = 0x3f800000;
  param_1[0x6b] = 0x3f800000;
  param_1[0x6c] = 0x3f800000;
  param_1[0x6d] = 0x3f800000;
  param_1[0x6e] = 0x3f800000;
  param_1[0x6f] = 0x3f800000;
  param_1[0x70] = 0x3f800000;
  param_1[0x65] = *(undefined4 *)(in_ECX + 0x194);
  param_1[0x66] = *(undefined4 *)(in_ECX + 0x198);
  param_1[0x67] = *(undefined4 *)(in_ECX + 0x19c);
  param_1[0x68] = *(undefined4 *)(in_ECX + 0x1a0);
  param_1[0x69] = *(undefined4 *)(in_ECX + 0x1a4);
  param_1[0x6a] = *(undefined4 *)(in_ECX + 0x1a8);
  param_1[0x6b] = *(undefined4 *)(in_ECX + 0x1ac);
  param_1[0x6c] = *(undefined4 *)(in_ECX + 0x1b0);
  param_1[0x6d] = *(undefined4 *)(in_ECX + 0x1b4);
  param_1[0x6e] = *(undefined4 *)(in_ECX + 0x1b8);
  param_1[0x6f] = *(undefined4 *)(in_ECX + 0x1bc);
  param_1[0x70] = *(undefined4 *)(in_ECX + 0x1c0);
  param_1[0x71] = *(undefined4 *)(in_ECX + 0x1c4);
  param_1[0x72] = *(undefined4 *)(in_ECX + 0x1c8);
  param_1[0x73] = *(undefined4 *)(in_ECX + 0x1cc);
  if (param_1 + 0x61 != (undefined4 *)(in_ECX + 0x184)) {
    FUN_00855d00(*(undefined4 *)param_1[0x62],(undefined4 *)param_1[0x62]);
    FUN_008561c0((undefined4 *)(in_ECX + 0x184));
  }
  ExceptionList = local_10;
  return param_1;
}

