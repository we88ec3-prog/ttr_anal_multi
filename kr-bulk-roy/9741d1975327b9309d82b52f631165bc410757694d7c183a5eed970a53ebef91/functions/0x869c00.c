
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00869c00(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  _union_530 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  uint local_c;
  undefined1 local_8 [4];
  
  _DAT_00fe34f0 = 0x18;
  _DAT_00fe34f8 = FUN_00869b40();
  local_c = 0;
  cVar1 = FUN_00869aa0();
  if (cVar1 == '\0') {
    uVar2 = 1;
  }
  else {
    cVar1 = FUN_00869930(1,local_8,&local_c,local_8,local_8);
    if (cVar1 == '\0') {
      uVar2 = 1;
    }
    else {
      uVar2 = (undefined1)(local_c >> 0x10);
    }
  }
  _DAT_00fe34f5 = CONCAT11(DAT_00fe34f6,uVar2);
  local_38.dwOemId = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  GetSystemInfo((LPSYSTEM_INFO)&local_38.s);
  cVar1 = (char)(local_24 / DAT_00fe34f5);
  cVar3 = cVar1 * DAT_00fe34f5;
  _DAT_00fe34f5 = CONCAT11(cVar1,cVar3);
  if ((cVar1 == '\0') && (cVar3 == '\0')) {
    _DAT_00fe34f5 = 0x101;
  }
  cVar1 = FUN_00869930(1,local_14,local_10,local_8,&local_c);
  bVar4 = 0;
  if (cVar1 != '\0') {
    bVar4 = (byte)(local_c >> 4) & 1;
  }
  DAT_00fe34f4 = DAT_00fe34f4 ^ (DAT_00fe34f4 ^ bVar4) & 1;
  cVar1 = FUN_00869930(1,local_8,local_10,local_14,&local_c);
  bVar4 = 0;
  if (cVar1 != '\0') {
    bVar4 = (byte)(local_c >> 0xf) & 1;
  }
  DAT_00fe34f4 = DAT_00fe34f4 ^ (bVar4 * '\x02' ^ DAT_00fe34f4) & 2;
  cVar1 = FUN_00869930(1,local_8,local_10,local_14,&local_c);
  bVar4 = 0;
  if (cVar1 != '\0') {
    bVar4 = (byte)(local_c >> 0x10) & 1;
  }
  DAT_00fe34f4 = DAT_00fe34f4 ^ (bVar4 * '\x04' ^ DAT_00fe34f4) & 4;
  cVar1 = FUN_00869930(1,local_8,local_10,local_14,&local_c);
  bVar4 = 0;
  if (cVar1 != '\0') {
    bVar4 = (byte)(local_c >> 0x17) & 1;
  }
  DAT_00fe34f4 = DAT_00fe34f4 ^ (bVar4 << 6 ^ DAT_00fe34f4) & 0x40;
  cVar1 = FUN_00869930(1,local_8,local_10,local_14,&local_c);
  bVar4 = 0;
  if (cVar1 != '\0') {
    bVar4 = (byte)(local_c >> 0x19) & 1;
  }
  DAT_00fe34f4 = DAT_00fe34f4 ^ (bVar4 << 3 ^ DAT_00fe34f4) & 8;
  cVar1 = FUN_00869930(1,local_8,local_10,local_14,&local_c);
  bVar4 = 0;
  if (cVar1 != '\0') {
    bVar4 = (byte)(local_c >> 0x1a) & 1;
  }
  DAT_00fe34f4 = DAT_00fe34f4 ^ (bVar4 << 4 ^ DAT_00fe34f4) & 0x10;
  cVar1 = FUN_008699d0();
  DAT_00fe34f4 = DAT_00fe34f4 ^ (cVar1 << 5 ^ DAT_00fe34f4) & 0x20;
  _DAT_00fe3500 = FUN_00869a30();
  return &DAT_00fe34f0;
}

