
void FUN_007d6380(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  char *in_ECX;
  char *in_EDX;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_35;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934d7e;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = in_ECX;
  if (0xf < *(uint *)(in_ECX + 0x14)) {
    pcVar3 = *(char **)in_ECX;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = local_34 & 0xffffff00;
  pcVar2 = pcVar3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar3,(int)pcVar2 - (int)(pcVar3 + 1));
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  FUN_00401fc0("Face/",5);
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    local_8._0_1_ = 1;
    FUN_007d0fb0(&local_35);
    _atexit((_func_4879 *)&LAB_00bd09c0);
    local_8._0_1_ = 0;
  }
  puVar4 = (undefined4 *)FUN_007d0920(0);
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (puVar4 != (undefined4 *)0x0) {
    FUN_007c7dd0(puVar4,&local_48);
    piVar5 = (int *)FUN_007c6700(puVar4,"Face.GEOM");
    if (piVar5 != (int *)0x0) {
      uVar6 = (**(code **)(*piVar5 + 0xc))();
      FUN_007d6510(in_ECX,param_1,uVar6);
    }
    (**(code **)*puVar4)(1);
    if (local_48 != 0) {
      FUN_0089120c(local_48);
    }
  }
  local_40 = 0;
  local_44 = 0;
  local_48 = 0;
  if (0xf < local_20) {
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    FUN_0089120c(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

