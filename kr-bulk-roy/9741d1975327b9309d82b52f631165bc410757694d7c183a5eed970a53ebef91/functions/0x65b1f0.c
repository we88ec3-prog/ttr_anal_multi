
void FUN_0065b1f0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int *in_EDX;
  undefined4 *puVar4;
  undefined1 auStack_68 [4];
  undefined1 local_64 [4];
  int local_60;
  uint local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_40;
  undefined1 local_3f;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined1 local_20;
  undefined1 local_1f;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090f690;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_68;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x31) == '\0') {
    puVar2 = (undefined4 *)puVar4[1];
    do {
      if ((int)puVar2[3] < *in_EDX) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar4 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x31) == '\0');
  }
  if ((puVar4 == *(undefined4 **)(in_ECX + 4)) || (*in_EDX < (int)puVar4[3])) {
    local_60 = *in_EDX;
    local_28 = 7;
    local_2c = 0;
    local_3c[0] = local_3c[0] & 0xffff0000;
    local_c = 0;
    local_4c = 0;
    local_48 = 7;
    local_5c = local_5c & 0xffff0000;
    FUN_004026e0(local_3c,0,0xffffffff);
    local_40 = local_20;
    local_3f = local_1f;
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_0065c9d0(in_ECX);
    FUN_0065c290(local_64,puVar4);
    if (7 < local_48) {
      FUN_0089120c(local_5c,uVar1);
    }
    local_48 = 7;
    local_4c = 0;
    local_5c = local_5c & 0xffff0000;
    if (7 < local_28) {
      FUN_0089120c(local_3c[0],uVar1);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_68);
  return;
}

