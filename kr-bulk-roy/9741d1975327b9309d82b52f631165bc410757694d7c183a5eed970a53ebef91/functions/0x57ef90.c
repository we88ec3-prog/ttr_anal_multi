
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0057ef90(void)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00921132;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_00fc1c10 = 0xffffffff;
  DAT_00fc1c2c = (undefined4 *)0x0;
  _DAT_00fc1c30 = 0;
  _DAT_00fc1c34 = 0;
  DAT_00fc1c50 = 0;
  DAT_00fc1c54 = 0;
  _DAT_00fc1c58 = 0;
  local_8 = 1;
  uStack_7 = 0;
  DAT_00fc1c00 = 0;
  DAT_00fc1c04 = 0;
  _DAT_00fc1c08 = 0;
  _DAT_00fc1c0c = 0;
  _DAT_00fc1bf8 = 0;
  _DAT_00fc1bfc = 0;
  DAT_00fc1c4c = 0;
  _DAT_00fc1c60 = 0;
  _DAT_00fc1c70 = 0;
  DAT_00fc1c74 = 0;
  iVar2 = FUN_00891268(0x38,uVar1);
  local_8 = 2;
  if (iVar2 != 0) {
    FUN_0057fbf0(iVar2,"Synopsis/book01.gb3");
  }
  local_8 = 1;
  FUN_00443d10();
  iVar2 = FUN_00891268(0x38,uVar1);
  local_8 = 3;
  if (iVar2 != 0) {
    FUN_0057fbf0(iVar2,"Synopsis/book02.gb3");
  }
  local_8 = 1;
  FUN_00443d10();
  iVar2 = FUN_00891268(0x38);
  local_8 = 4;
  if (iVar2 != 0) {
    FUN_0057fbf0(iVar2,"Synopsis/book03.gb3");
  }
  local_8 = 1;
  FUN_00443d10();
  iVar2 = FUN_00891268(0x38);
  local_8 = 5;
  if (iVar2 != 0) {
    FUN_0057fbf0(iVar2,"Synopsis/book04.gb3");
  }
  _local_8 = CONCAT31(uStack_7,1);
  FUN_00443d10();
  DAT_00fc1c3c = (undefined4 *)FUN_00891268(0x10);
  if (DAT_00fc1c3c == (undefined4 *)0x0) {
    DAT_00fc1c3c = (undefined4 *)0x0;
  }
  else {
    DAT_00fc1c3c[1] = &DAT_00fc1bf8;
    DAT_00fc1c3c[3] = 0;
    *DAT_00fc1c3c = Synopsis::CBookState1::vftable;
  }
  DAT_00fc1c40 = (undefined4 *)FUN_00891268(0x48);
  if (DAT_00fc1c40 == (undefined4 *)0x0) {
    DAT_00fc1c40 = (undefined4 *)0x0;
  }
  else {
    DAT_00fc1c40[1] = &DAT_00fc1bf8;
    DAT_00fc1c40[3] = 0;
    *DAT_00fc1c40 = Synopsis::CBookState2::vftable;
    DAT_00fc1c40[4] = 0x40a00000;
    DAT_00fc1c40[6] = 0x40a00000;
    DAT_00fc1c40[5] = 0;
    DAT_00fc1c40[7] = 0;
    DAT_00fc1c40[8] = 0x3f800000;
    DAT_00fc1c40[10] = 0x3f800000;
    DAT_00fc1c40[9] = 0;
    DAT_00fc1c40[0xb] = 0;
    DAT_00fc1c40[0xc] = 0;
    DAT_00fc1c40[0xd] = 0x44400000;
    DAT_00fc1c40[0xe] = 0;
    DAT_00fc1c40[0xf] = 1;
    DAT_00fc1c40[0x10] = 0;
  }
  DAT_00fc1c44 = (undefined4 *)FUN_00891268(0x10);
  if (DAT_00fc1c44 == (undefined4 *)0x0) {
    DAT_00fc1c44 = (undefined4 *)0x0;
  }
  else {
    DAT_00fc1c44[1] = &DAT_00fc1bf8;
    DAT_00fc1c44[3] = 0;
    *DAT_00fc1c44 = Synopsis::CBookState3::vftable;
  }
  DAT_00fc1c48 = (undefined4 *)FUN_00891268(0x10);
  if (DAT_00fc1c48 == (undefined4 *)0x0) {
    DAT_00fc1c48 = (undefined4 *)0x0;
  }
  else {
    DAT_00fc1c48[1] = &DAT_00fc1bf8;
    DAT_00fc1c48[3] = 0;
    *DAT_00fc1c48 = Synopsis::CBookState4::vftable;
  }
  DAT_00fc1c3c[3] = *DAT_00fc1c2c;
  DAT_00fc1c40[3] = DAT_00fc1c2c[1];
  DAT_00fc1c44[3] = DAT_00fc1c2c[2];
  DAT_00fc1c48[3] = DAT_00fc1c2c[3];
  _DAT_00fc1c64 = 0;
  DAT_00fc1c6c = 0;
  _DAT_00fc1c68 = 0;
  _DAT_00fc1c78 = 0xffffffff;
  ExceptionList = local_10;
  return &DAT_00fc1bf8;
}

