
void FUN_0068a9a0(int param_1)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_ac [4];
  undefined4 local_a8;
  undefined4 local_98;
  uint local_94;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  uint local_5c;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092a8c8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_ac;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff48;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0x10) == 1000) {
    if (*(char *)(in_ECX + 0x141) != '\0') {
      FUN_006edb10("Not supported operation",uVar1);
    }
    FUN_00526870(local_54);
    local_c = 0;
    local_94 = 7;
    local_98 = 0;
    local_a8 = (uint)local_a8._2_2_ << 0x10;
    FUN_00402160(&DAT_00bed1fc,0);
    local_c._0_1_ = 1;
    local_8c = (uint)local_8c._2_2_ << 0x10;
    local_78 = 7;
    local_7c = 0;
    FUN_00402160(&DAT_00c1ae14,1);
    local_c = CONCAT31(local_c._1_3_,2);
    FUN_00759330(local_54,&local_8c,&local_a8);
    if (7 < local_78) {
      FUN_0089120c(local_8c);
    }
    local_c = local_c & 0xffffff00;
    local_78 = 7;
    local_7c = 0;
    local_8c = local_8c & 0xffff0000;
    if (7 < local_94) {
      FUN_0089120c(local_a8);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8 = local_a8 & 0xffff0000;
    if (*(char *)(in_ECX + 0x141) != '\0') {
      FUN_006edb10("Not supported operation");
    }
    FUN_00405300(in_ECX + 0x108);
    *(undefined4 *)(in_ECX + 0x168) = 0;
    *(undefined4 *)(in_ECX + 0x160) = 0;
    *(undefined4 *)(in_ECX + 0x164) = 0;
    FUN_00761fe0();
    local_c = 0xffffffff;
    FUN_00757640(local_54);
  }
  else if (*(int *)(param_1 + 0x10) == 0x3e9) {
    if (*(char *)(in_ECX + 0x141) != '\0') {
      FUN_006edb10("Not supported operation",uVar1);
    }
    piVar2 = (int *)(in_ECX + 0x108);
    if (7 < *(uint *)(in_ECX + 0x11c)) {
      piVar2 = (int *)*piVar2;
    }
    FUN_008935e3(piVar2);
    FUN_00412df0();
    local_c = 3;
    if (*(char *)(in_ECX + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation",uVar1);
    }
    *(undefined4 *)(in_ECX + 0x168) = 0;
    *(undefined4 *)(in_ECX + 0x160) = 0;
    *(undefined4 *)(in_ECX + 0x164) = 0;
    *(undefined4 *)(in_ECX + 0x14c) = 0;
    if (7 < local_5c) {
      FUN_0089120c(local_70);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_ac);
  return;
}

