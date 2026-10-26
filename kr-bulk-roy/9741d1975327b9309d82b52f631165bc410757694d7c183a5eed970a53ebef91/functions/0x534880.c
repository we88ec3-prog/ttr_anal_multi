
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00534880(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_1014 [1024];
  int local_14;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(param_1 + 4);
  iVar7 = 2;
  local_1014[0]._0_2_ = 0xbd5;
  local_14 = 2;
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    uVar4 = puVar3[5];
    if (iVar7 + 8U < 0x1001) {
      *(undefined4 *)((int)local_1014 + iVar7) = puVar3[4];
      *(undefined4 *)((int)local_1014 + iVar7 + 4) = uVar4;
      iVar7 = local_14 + 8;
      local_14 = iVar7;
    }
    if (*(char *)((int)puVar3 + 0x19) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x19) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x19);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x19);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x19);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x19);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  (**(code **)(*DAT_00fba854 + 0x10))(2,local_1014,iVar7);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

