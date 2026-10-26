
byte * FUN_005158e0(byte *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  byte local_3c [4];
  undefined1 local_38 [4];
  undefined4 *local_34;
  undefined4 *local_24;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009103e2;
  local_10 = ExceptionList;
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(in_ECX + 4)) && (*(byte *)(puVar3 + 3) <= *param_1)) {
    return (byte *)(puVar3 + 4);
  }
  local_20 = 0;
  ExceptionList = &local_10;
  local_24 = (undefined4 *)FUN_00820120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *local_24 = local_24;
  local_24[1] = local_24;
  local_24[2] = local_24;
  *(undefined1 *)(local_24 + 6) = 1;
  *(undefined1 *)((int)local_24 + 0x19) = 1;
  local_8 = 0;
  local_3c[0] = *param_1;
  FUN_00517630(local_38);
  local_8._0_1_ = 1;
  FUN_00518e50(local_3c);
  FUN_00517980(in_ECX,puVar3);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00535ac0(*local_34,local_34);
  FUN_0089120c(local_34);
  local_8 = 3;
  FUN_00535ac0(*local_24,local_24);
  FUN_0089120c(local_24);
  ExceptionList = local_10;
  return param_1 + 0x10;
}

