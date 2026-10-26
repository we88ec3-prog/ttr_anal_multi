
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d6ed0(int param_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  undefined2 *puVar3;
  int *piVar4;
  undefined1 local_1028 [4];
  undefined4 local_1024;
  undefined4 local_1018;
  undefined4 local_1014 [1024];
  int local_14;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((_DAT_00fe658c & 1) == 0) {
    _DAT_00fe658c = _DAT_00fe658c | 1;
    _DAT_00fe6588 = timeGetTime();
  }
  if ((*(int *)(param_1 + 0x18) != 0) && (DVar2 = timeGetTime(), 0xfa < DVar2 - _DAT_00fe6588)) {
    _DAT_00fe6588 = timeGetTime();
    local_1014[0]._0_2_ = 0xb6;
    local_14 = 2;
    piVar4 = (int *)**(int **)(param_1 + 0x14);
    if (piVar4 != *(int **)(param_1 + 0x14)) {
      do {
        uVar1 = *(undefined4 *)((int)piVar4 + 0x14);
        local_1024 = *(undefined4 *)((int)piVar4 + 0x10);
        puVar3 = (undefined2 *)FUN_006d6d80(param_1,local_1024,uVar1);
        local_1018 = CONCAT22(*puVar3,(short)uVar1);
        if (local_14 + 8U < 0x1001) {
          *(undefined4 *)((int)local_1014 + local_14) = local_1024;
          *(undefined4 *)((int)local_1014 + local_14 + 4) = local_1018;
          local_14 = local_14 + 8;
        }
        piVar4 = (int *)FUN_00535c60(param_1 + 0x10,local_1028,piVar4);
        piVar4 = (int *)*piVar4;
      } while (piVar4 != (int *)*(int *)(param_1 + 0x14));
    }
    (**(code **)(*DAT_00fba854 + 0x10))(0,local_1014,local_14);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

