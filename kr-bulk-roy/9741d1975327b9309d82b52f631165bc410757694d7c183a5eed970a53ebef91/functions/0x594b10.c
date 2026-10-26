
void FUN_00594b10(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint *in_EDX;
  undefined4 *puVar4;
  undefined1 auStack_60 [4];
  undefined1 local_5c [4];
  uint local_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091ae80;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_60;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
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
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*in_EDX < (uint)puVar4[3])) {
    local_58 = *in_EDX;
    local_24 = 7;
    local_28 = 0;
    local_38[0] = local_38[0] & 0xffff0000;
    local_c = 0;
    local_44 = 0;
    local_40 = 7;
    local_54 = local_54 & 0xffff0000;
    FUN_00402800(local_38);
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_005063f0(&local_58);
    FUN_00480420(local_5c,puVar4);
    if (7 < local_40) {
      FUN_0089120c(local_54,uVar1);
    }
    local_40 = 7;
    local_44 = 0;
    local_54 = local_54 & 0xffff0000;
    if (7 < local_24) {
      FUN_0089120c(local_38[0],uVar1);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_60);
  return;
}

