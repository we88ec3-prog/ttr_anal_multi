
void FUN_007eb290(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 ***pppuVar3;
  int *in_ECX;
  bool bVar4;
  double dVar5;
  undefined1 local_64 [12];
  int local_58;
  float local_54;
  float local_50;
  undefined4 **local_4c [5];
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c650;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = param_1;
  if (in_ECX == (int *)0x0) goto LAB_007eb422;
  (**(code **)(*in_ECX + 0x14))(local_14);
  local_1c = 0xf;
  local_20 = 0;
  local_30 = local_30 & 0xffffff00;
  FUN_00402a70("Texture",7);
  local_8 = 0;
  FUN_0072ecf0(&DAT_00bf2375);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0xf < local_1c) {
    FUN_0089120c(local_30);
  }
  local_20 = 0;
  local_1c = 0xf;
  local_30 = local_30 & 0xffffff00;
  FUN_0072e360();
  FUN_007e3f30(local_64);
  iVar1 = FUN_007300a0("Rotation");
  if (iVar1 == 0) {
LAB_007eb376:
    local_50 = 0.0;
  }
  else {
    pcVar2 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      pcVar2 = *(char **)pcVar2;
    }
    if (pcVar2 == (char *)0x0) goto LAB_007eb376;
    dVar5 = _atof(pcVar2);
    local_50 = (float)dVar5;
  }
  iVar1 = FUN_007300a0(&DAT_00c506ac);
  if (iVar1 == 0) {
LAB_007eb3a5:
    local_54 = 0.0;
  }
  else {
    pcVar2 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      pcVar2 = *(char **)pcVar2;
    }
    if (pcVar2 == (char *)0x0) goto LAB_007eb3a5;
    dVar5 = _atof(pcVar2);
    local_54 = (float)dVar5;
  }
  iVar1 = FUN_007300a0("IsAlphaADD");
  if (iVar1 == 0) {
LAB_007eb3db:
    bVar4 = false;
  }
  else {
    pcVar2 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      pcVar2 = *(char **)pcVar2;
    }
    if (pcVar2 == (char *)0x0) goto LAB_007eb3db;
    iVar1 = __stricmp(pcVar2,"true");
    bVar4 = iVar1 == 0;
  }
  pppuVar3 = (undefined4 ***)local_4c[0];
  if (local_38 < 0x10) {
    pppuVar3 = local_4c;
  }
  FUN_007bb150(*(undefined4 *)(local_58 + 4),pppuVar3,local_50,local_54,bVar4);
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0]);
  }
LAB_007eb422:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

