
void FUN_007f9050(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c [4];
  undefined4 local_3c;
  undefined4 local_2c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092b8fe;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff58;
  ExceptionList = &local_14;
  local_94 = *(undefined4 *)(in_ECX + 0x24);
  local_90 = *(undefined4 *)(in_ECX + 0x28);
  local_88 = 0;
  local_8c = *(undefined4 *)(in_ECX + 0x2c);
  local_84 = 0;
  local_80 = 0;
  local_7c = 0x3f800000;
  local_78 = 0x3f800000;
  local_74 = 0x3f800000;
  local_70 = 0x3f800000;
  local_50 = 3;
  uVar1 = *(undefined4 *)(in_ECX + 0x30);
  local_6c = 1;
  uVar2 = *(undefined4 *)(in_ECX + 0x34);
  uVar3 = *(undefined4 *)(in_ECX + 0x38);
  _memset(local_4c,0,0x34);
  local_2c = 0x3f800000;
  local_3c = 0x3f800000;
  local_4c[0] = 0x3f800000;
  FUN_00790dc0(uVar1);
  FUN_00790e90(uVar2);
  FUN_00790f60(uVar3);
  FUN_00780890(uVar4);
  local_78 = *(undefined4 *)(in_ECX + 0x3c);
  local_74 = *(undefined4 *)(in_ECX + 0x40);
  local_70 = *(undefined4 *)(in_ECX + 0x44);
  local_68 = *(undefined4 *)(in_ECX + 0xe4);
  local_64 = *(undefined4 *)(in_ECX + 0xe8);
  local_60 = *(undefined4 *)(in_ECX + 0xec);
  local_5c = *(undefined4 *)(in_ECX + 0xf0);
  local_58 = *(undefined4 *)(in_ECX + 0xf4);
  local_54 = *(undefined4 *)(in_ECX + 0xf8);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  FUN_0079a920(&DAT_00fb76a8,&local_68,&local_94,0xffffffff);
  ExceptionList = local_14;
  return;
}

