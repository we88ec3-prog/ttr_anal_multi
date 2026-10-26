
uint * FUN_008500d0(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  int in_ECX;
  uint *puVar3;
  uint local_3c;
  undefined1 local_38 [4];
  undefined4 *local_34;
  undefined4 *local_24;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e7d2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = *(uint **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (uint *)puVar3[1];
    do {
      if (puVar1[3] < *param_1) {
        puVar2 = (uint *)puVar1[2];
      }
      else {
        puVar2 = (uint *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 == *(uint **)(in_ECX + 4)) || (*param_1 < puVar3[3])) {
    local_20 = 0;
    local_24 = (undefined4 *)FUN_006db770(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *local_24 = local_24;
    local_24[1] = local_24;
    local_24[2] = local_24;
    *(undefined1 *)(local_24 + 0xd) = 1;
    *(undefined1 *)((int)local_24 + 0x35) = 1;
    local_8 = 0;
    local_3c = *param_1;
    FUN_008520c0(local_38);
    local_8._0_1_ = 1;
    FUN_008537e0(&local_3c);
    FUN_008528c0(in_ECX,puVar3);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00850e70(*local_34,local_34);
    FUN_0089120c(local_34);
    local_8 = 3;
    FUN_00850e70(*local_24,local_24);
    FUN_0089120c(local_24);
    puVar3 = param_1;
  }
  ExceptionList = local_10;
  return puVar3 + 4;
}

