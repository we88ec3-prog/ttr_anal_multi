
void FUN_0048b730(void)

{
  char cVar1;
  undefined4 ***pppuVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_124 [4];
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined1 local_54;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922393;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_11c = 0;
  local_118 = 0;
  FUN_0071bc20(local_14);
  local_54 = 0;
  local_3c = 0xf;
  local_40 = 0;
  local_50 = local_50 & 0xffffff00;
  local_8 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  FUN_00402a70("Integrity.xml",0xd);
  local_8 = CONCAT31(local_8._1_3_,1);
  pppuVar2 = (undefined4 ***)local_30[0];
  if (local_1c < 0x10) {
    pppuVar2 = local_30;
  }
  piVar3 = (int *)FUN_00714770(pppuVar2,&DAT_00bed1e0);
  if (piVar3 == (int *)0x0) {
    cVar1 = '\0';
  }
  else {
    (**(code **)(*piVar3 + 0x38))();
    uVar4 = (**(code **)(*piVar3 + 0x2c))();
    cVar1 = FUN_00499340(uVar4);
    (**(code **)(*piVar3 + 4))();
  }
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  if (cVar1 != '\0') {
    local_120 = local_11c;
    puVar5 = (undefined4 *)FUN_0071ba40("PATCH");
    local_120 = *puVar5;
    puVar5 = (undefined4 *)FUN_00719da0(local_124);
    FUN_0048b380(*puVar5,&DAT_00bf2375);
  }
  local_8 = 0xffffffff;
  if (0xf < local_3c) {
    FUN_0089120c(local_50);
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = local_50 & 0xffffff00;
  FUN_0071bc90(&local_11c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

