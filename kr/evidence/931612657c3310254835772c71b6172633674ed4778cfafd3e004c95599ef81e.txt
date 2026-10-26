
uint * FUN_005083a0(int param_1,uint *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908749;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007e8a90(param_2,param_1 + 0x14);
  local_8 = 0;
  local_14 = 1;
  do {
    iVar3 = local_14;
    if (((uint)*(ushort *)(param_1 + 0x10) & 1 << ((char)local_14 - 1U & 0x1f)) != 0) {
      piVar1 = (int *)param_2[1];
      if ((&local_14 < piVar1) && (piVar2 = (int *)*param_2, piVar2 <= &local_14)) {
        if (piVar1 == (int *)param_2[2]) {
          FUN_006d6240(uVar4);
        }
        if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_2[1] =
               *(undefined4 *)(*param_2 + ((int)&local_14 - (int)piVar2 >> 2) * 4);
        }
      }
      else {
        if (piVar1 == (int *)param_2[2]) {
          FUN_006d6240(uVar4);
        }
        if ((int *)param_2[1] != (int *)0x0) {
          *(int *)param_2[1] = iVar3;
        }
      }
      param_2[1] = param_2[1] + 4;
    }
    local_14 = iVar3 + 1;
  } while (local_14 < 10);
  ExceptionList = local_10;
  return param_2;
}

