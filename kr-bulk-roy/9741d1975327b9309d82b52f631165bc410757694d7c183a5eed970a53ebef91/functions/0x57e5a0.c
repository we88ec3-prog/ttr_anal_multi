
/* WARNING: Removing unreachable block (ram,0x0057e663) */

void FUN_0057e5a0(int *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint in_stack_0000001c;
  uint local_5c [4];
  undefined4 local_4c;
  uint local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091dc78;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = local_5c[0] & 0xffffff00;
  FUN_00402a70(&DAT_00bf2375,0);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_8._0_1_ = 1;
  pcVar2 = param_2;
  pcVar3 = param_2;
  if (in_stack_0000001c < 0x10) {
    pcVar2 = (char *)&param_2;
    pcVar3 = pcVar2;
  }
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_0040b310(pcVar3);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00572fd0(*(undefined4 *)(in_ECX + 8),local_5c);
  iVar4 = local_38 - local_40;
  iVar5 = local_34 - local_3c;
  local_40 = FUN_008fed10();
  local_3c = FUN_008fed10();
  *param_1 = local_40;
  param_1[1] = local_3c;
  param_1[2] = local_40 + iVar4;
  param_1[3] = local_3c + iVar5;
  if (0xf < local_48) {
    FUN_0089120c(local_5c[0]);
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c[0] = local_5c[0] & 0xffffff00;
  if (0xf < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

