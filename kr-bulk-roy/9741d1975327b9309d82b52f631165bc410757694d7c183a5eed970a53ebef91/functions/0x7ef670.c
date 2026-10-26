
void FUN_007ef670(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *in_ECX;
  int unaff_EDI;
  uint local_5c [4];
  undefined4 local_4c;
  uint local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009145c0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = local_5c[0] & 0xffffff00;
  local_8 = 0;
  local_40 = 0;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_18 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_3c = param_1;
  local_24 = 0xf;
  local_28 = 0;
  local_38 = local_38 & 0xffffff00;
  FUN_00403040(local_5c,0,0xffffffff);
  local_1c = local_40;
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar4 = FUN_007f0f60(unaff_EDI + 0x10c);
  FUN_007f0cf0(unaff_EDI + 0x10c,uVar4);
  if (0xf < local_24) {
    FUN_0089120c(local_38,uVar2);
  }
  if (0xf < local_48) {
    FUN_0089120c(local_5c[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

