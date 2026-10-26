
void FUN_0047fcd0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint *in_EDX;
  undefined4 *puVar4;
  undefined1 local_54 [4];
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  uint local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091bc80;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x2d) == '\0') {
    puVar2 = (undefined4 *)puVar4[1];
    do {
      if ((uint)puVar2[3] < *in_EDX) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar4 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  local_14 = uVar1;
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*in_EDX < (uint)puVar4[3])) {
    local_34 = *in_EDX;
    local_3c = 7;
    local_40 = 0;
    local_50[0] = local_50[0] & 0xffff0000;
    local_8 = 0;
    local_20 = 0;
    local_1c = 7;
    local_30 = local_30 & 0xffff0000;
    FUN_00402800(local_50);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_005063f0(&local_34);
    FUN_00480420(local_54,puVar4);
    if (7 < local_1c) {
      FUN_0089120c(local_30,uVar1);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    if (7 < local_3c) {
      FUN_0089120c(local_50[0],uVar1);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

