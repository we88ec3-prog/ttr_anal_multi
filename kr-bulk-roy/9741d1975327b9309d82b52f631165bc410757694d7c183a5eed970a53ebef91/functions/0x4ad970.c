
void FUN_004ad970(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 *in_ECX;
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_3c [4];
  int local_2c;
  uint local_28;
  char local_20 [12];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091b640;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = 0xf;
  local_2c = 0;
  local_3c[0] = local_3c[0] & 0xffffff00;
  local_8 = 0;
  local_14 = uVar2;
  __itoa_s(*(int *)*in_ECX,local_20,0xc,10);
  pcVar3 = local_20;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_20,(int)pcVar3 - (int)(local_20 + 1));
  if (local_2c < (int)in_ECX[1]) {
    local_44 = 0xf;
    local_48 = 0;
    local_58[0] = local_58[0] & 0xffffff00;
    local_8._0_1_ = 1;
    FUN_0046e1b0(in_ECX[1] - local_2c,in_ECX[2]);
    FUN_00401ed0(local_3c,0,0xffffffff);
    FUN_00403040(local_58,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_44) {
      FUN_0089120c(local_58[0]);
    }
  }
  FUN_00401ed0(local_3c,0,0xffffffff);
  if (0xf < local_28) {
    FUN_0089120c(local_3c[0],uVar2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

