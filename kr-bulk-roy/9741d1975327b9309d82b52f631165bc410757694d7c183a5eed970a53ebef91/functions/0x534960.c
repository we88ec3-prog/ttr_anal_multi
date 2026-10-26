
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00534960(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_100c [1024];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar6 = 2;
  puVar2 = *(undefined4 **)(param_1 + 4);
  local_100c[0]._0_2_ = 0xbd6;
  local_c = 2;
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (iVar6 + 4U < 0x1001) {
      *(undefined4 *)((int)local_100c + iVar6) = puVar3[3];
      iVar6 = local_c + 4;
      local_c = iVar6;
    }
    if (*(char *)((int)puVar3 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x11);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x11);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  (**(code **)(*DAT_00fba854 + 0x10))(2,local_100c,iVar6);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

