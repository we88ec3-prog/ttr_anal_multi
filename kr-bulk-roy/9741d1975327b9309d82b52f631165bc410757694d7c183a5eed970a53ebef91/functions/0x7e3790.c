
void FUN_007e3790(int param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *unaff_ESI;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ba68;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = 0;
  local_58 = 0;
  local_20 = 0xf;
  local_54 = 0;
  local_24 = 0;
  local_50 = 0;
  local_34 = local_34 & 0xffffff00;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0x3f800000;
  local_40 = 0x3f800000;
  local_3c = 0x3f800000;
  local_38 = 0x3f800000;
  local_8 = 0;
  pcVar3 = unaff_ESI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
  FUN_007e3d00(&local_5c);
  FUN_007e2130(*(undefined4 *)(param_1 + 0x1c));
  if (0xf < local_20) {
    FUN_0089120c(local_34,uVar2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

