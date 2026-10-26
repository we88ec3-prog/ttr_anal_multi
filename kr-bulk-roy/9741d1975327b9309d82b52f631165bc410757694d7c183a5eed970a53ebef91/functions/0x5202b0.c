
void FUN_005202b0(undefined4 *param_1,undefined4 *param_2,code *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_28;
  int local_24 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b248;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar5 = param_1 + 5;
  if (puVar5 != param_2) {
    local_14 = param_1;
    do {
      local_28 = *puVar5;
      puVar6 = local_14 + 6;
      FUN_004fcd00(local_24,puVar6);
      local_8 = 0;
      cVar3 = (*param_3)(&local_28,param_1,uVar4);
      puVar2 = local_14;
      puVar1 = puVar5;
      if (cVar3 == '\0') {
        cVar3 = (*param_3)(&local_28,local_14);
        while (cVar3 != '\0') {
          *puVar1 = *puVar2;
          FUN_004fcdc0(puVar2 + 1);
          cVar3 = (*param_3)(&local_28,puVar2 + -5);
          puVar1 = puVar2;
          puVar2 = puVar2 + -5;
        }
        *puVar1 = local_28;
      }
      else {
        while (param_1 != puVar1) {
          puVar6[-1] = puVar6[-6];
          FUN_004fcdc0(puVar6 + -5);
          puVar1 = puVar6 + -6;
          puVar6 = puVar6 + -5;
        }
        *param_1 = local_28;
      }
      FUN_004fcdc0(local_24);
      local_8 = 0xffffffff;
      if (local_24[0] != 0) {
        FUN_0089120c(local_24[0]);
      }
      local_14 = local_14 + 5;
      puVar5 = puVar5 + 5;
    } while (puVar5 != param_2);
  }
  ExceptionList = local_10;
  return;
}

