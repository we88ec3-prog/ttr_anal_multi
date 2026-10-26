
void FUN_00858990(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *_String;
  char *pcVar3;
  int iVar4;
  int *in_ECX;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar5;
  undefined4 local_68;
  uint local_54;
  undefined4 local_4c;
  uint local_38;
  uint local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00928218;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  _String = __strdup(param_1);
  __strlwr(_String);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar3 = _String;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(_String,(int)pcVar3 - (int)(_String + 1));
  iVar5 = 0;
  local_8 = 0;
  FUN_00891d3d(_String,uVar2);
  iVar4 = FUN_00440930(local_30,&DAT_00c41190,1);
  while (iVar4 != -1) {
    FUN_007da7d0(iVar4 - iVar5);
    local_8._0_1_ = 1;
    FUN_00440c60();
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_54) {
      FUN_0089120c(local_68);
    }
    iVar5 = iVar4 + 1;
    iVar4 = FUN_00440930(local_30,&DAT_00c41190,1);
  }
  FUN_007da7d0(local_20 - iVar5);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00440c60();
  iVar5 = (in_ECX[1] - *in_ECX) / 0x1c + (in_ECX[1] - *in_ECX >> 0x1f);
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
    iVar5 = extraout_EDX;
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
    iVar5 = extraout_EDX_00;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,iVar5);
  return;
}

