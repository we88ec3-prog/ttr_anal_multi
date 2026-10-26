
ushort * FUN_00819460(ushort *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  int in_ECX;
  ushort *puVar3;
  ushort local_3c [2];
  undefined1 local_38 [4];
  undefined4 *local_34;
  undefined1 local_28 [4];
  undefined4 *local_24;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c172;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = *(ushort **)(in_ECX + 4);
  if (*(char *)((int)*(ushort **)(puVar3 + 2) + 0x21) == '\0') {
    puVar1 = *(ushort **)(puVar3 + 2);
    do {
      if (puVar1[6] < *param_1) {
        puVar2 = *(ushort **)(puVar1 + 4);
      }
      else {
        puVar2 = *(ushort **)puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 == *(ushort **)(in_ECX + 4)) || (*param_1 < puVar3[6])) {
    local_20 = 0;
    local_24 = (undefined4 *)FUN_00820120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *local_24 = local_24;
    local_24[1] = local_24;
    local_24[2] = local_24;
    *(undefined1 *)(local_24 + 6) = 1;
    *(undefined1 *)((int)local_24 + 0x19) = 1;
    local_8 = 0;
    local_3c[0] = *param_1;
    FUN_00819c30(local_38,local_28);
    local_8._0_1_ = 1;
    FUN_0081a210(local_3c);
    FUN_00819e30(in_ECX,puVar3);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00535ac0(*local_34,local_34);
    FUN_0089120c(local_34);
    local_8 = 3;
    FUN_00535ac0(*local_24,local_24);
    FUN_0089120c(local_24);
    puVar3 = param_1;
  }
  ExceptionList = local_10;
  return puVar3 + 8;
}

