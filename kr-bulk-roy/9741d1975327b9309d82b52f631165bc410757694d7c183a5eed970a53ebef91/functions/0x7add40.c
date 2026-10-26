
void FUN_007add40(char *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 ***pppuVar4;
  int *piVar5;
  char *unaff_EDI;
  undefined1 local_34 [4];
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917838;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  pcVar3 = unaff_EDI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(unaff_EDI,(int)pcVar3 - (int)(unaff_EDI + 1));
  local_8 = 0;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(param_1,(int)pcVar3 - (int)(param_1 + 1));
  pppuVar4 = (undefined4 ***)local_30[0];
  if (local_1c < 0x10) {
    pppuVar4 = local_30;
  }
  piVar5 = (int *)FUN_00714770(pppuVar4,&DAT_00bed1e0,uVar2);
  if (piVar5 == (int *)0x0) {
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    goto LAB_007ade5c;
  }
  (**(code **)(*piVar5 + 0x10))(local_34,1,2);
  (**(code **)(*piVar5 + 0x34))(0,0);
  if ((char)local_34._0_2_ == '<') {
    if (SUB21(local_34._0_2_,1) == '?') {
LAB_007ade2f:
      FUN_007d5060(param_2);
    }
  }
  else if (((char)local_34._0_2_ == 'E') && (SUB21(local_34._0_2_,1) == 'X')) goto LAB_007ade2f;
  (**(code **)(*piVar5 + 4))();
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_007ade5c:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

