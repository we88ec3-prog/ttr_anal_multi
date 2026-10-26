
void FUN_007bf960(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *unaff_ESI;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e28;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar3 = unaff_ESI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
  local_8 = 0;
  puVar4 = (undefined4 *)FUN_007c0080(local_30);
  *puVar4 = param_2;
  puVar4[1] = param_3;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar2);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  FUN_007bfcc0();
  pcVar3 = unaff_ESI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

