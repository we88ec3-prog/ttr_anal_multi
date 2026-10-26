
undefined4 FUN_00849b50(undefined4 param_1,int param_2)

{
  int *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_a0 [13];
  undefined4 local_6c [13];
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_18;
  
  _memset(local_38,0,0x34);
  local_18 = 0x3f800000;
  local_28 = 0x3f800000;
  local_38[0] = 0x3f800000;
  FUN_007cd220();
  puVar2 = local_6c;
  puVar3 = local_a0;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00790b40();
  (**(code **)(*in_ECX + 0x40))(local_38);
  if (param_2 != 0) {
    FUN_00849e30();
  }
  return 1;
}

