
void FUN_008097e0(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908783;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  uVar4 = 0;
  uVar3 = param_1[1] - *param_1 >> 2;
  if (uVar3 != 0) {
    do {
      if (*(int *)(*param_1 + uVar4 * 4) != 0) {
        puVar1 = *(undefined4 **)(*param_1 + uVar4 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1,uVar2);
        }
        *(undefined4 *)(*param_1 + uVar4 * 4) = 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  uVar3 = 0;
  uVar2 = param_1[5] - param_1[4] >> 2;
  if (uVar2 != 0) {
    do {
      if (*(int *)(param_1[4] + uVar3 * 4) != 0) {
        puVar1 = *(undefined4 **)(param_1[4] + uVar3 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(param_1[4] + uVar3 * 4) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  if (param_1[4] != 0) {
    FUN_0089120c(param_1[4]);
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if (*param_1 != 0) {
    FUN_0089120c(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}

