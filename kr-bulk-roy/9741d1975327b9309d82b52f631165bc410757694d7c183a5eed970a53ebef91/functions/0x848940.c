
void FUN_00848940(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_38 [4];
  undefined4 local_28;
  undefined4 local_18;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    _memset(local_38,0,0x34);
    local_18 = 0x3f800000;
    local_28 = 0x3f800000;
    local_38[0] = 0x3f800000;
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = local_38;
      puVar3 = param_1;
      for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    param_1 = param_1 + 0xd;
  }
  return;
}

