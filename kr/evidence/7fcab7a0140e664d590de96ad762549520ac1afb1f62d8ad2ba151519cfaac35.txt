
void FUN_007197e0(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 local_74;
  uint local_70 [4];
  undefined4 local_60;
  uint local_5c;
  char local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915bf8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  _strcpy_s(local_54,0x40,param_1);
  FUN_007198b0(local_54);
  pcVar3 = local_54;
  local_5c = 0xf;
  local_60 = 0;
  local_70[0] = local_70[0] & 0xffffff00;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(local_54,(int)pcVar3 - (int)(local_54 + 1));
  local_8 = 0;
  FUN_007b86f0(&local_74,local_70);
  if (0xf < local_5c) {
    FUN_0089120c(local_70[0],uVar2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

