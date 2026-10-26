
void FUN_005e3b30(void)

{
  short sVar1;
  short *psVar2;
  undefined1 local_f4 [12];
  undefined4 local_e8;
  int local_e4;
  int local_e0;
  short local_d0;
  undefined1 local_ce [198];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_00897163(local_f4,&stack0x00000004);
  FUN_004b7c80(L"%d.%02d.%02d",local_e0 + 0x76c,local_e4 + 1,local_e8);
  psVar2 = &local_d0;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00404300(&local_d0,(int)psVar2 - (int)local_ce >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

