
void FUN_007beb30(uint param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  puStack_c = &LAB_0092bbbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x30))(0);
  FUN_0077efc0();
  FUN_0077f030(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x2c));
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_007e9d50(param_2);
    iVar5 = *(int *)(param_1 + 0xc);
    FUN_0077f030(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                 *(undefined4 *)(iVar5 + 0x20));
    FUN_00780150(piVar3,piVar3[0xc]);
    uVar4 = (**(code **)(*piVar3 + 0x34))();
    param_1 = 0;
    if (uVar4 != 0) {
      do {
        iVar5 = (**(code **)(*piVar3 + 0x30))(param_1);
        if (*(int *)(iVar5 + 0xdc) - *(int *)(iVar5 + 0xd8) >> 2 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = **(int **)(iVar5 + 0xd8);
        }
        if (*(int **)(iVar5 + 0x74) == (int *)0x0) {
LAB_007bec98:
          iVar5 = 0;
        }
        else {
          iVar6 = (**(code **)(**(int **)(iVar5 + 0x74) + 0x24))();
          if (iVar6 == 0) {
            iVar5 = *(int *)(iVar5 + 0x74);
          }
          else {
            iVar6 = (**(code **)(**(int **)(iVar5 + 0x74) + 0x38))();
            if (iVar6 < 1) goto LAB_007bec98;
            iVar5 = (**(code **)(**(int **)(iVar5 + 0x74) + 0x28))(0);
          }
        }
        fVar1 = *(float *)(*(int *)(iVar2 + 0xc) + 0x24);
        if (fVar1 <= 0.0) {
          fVar1 = 0.0;
        }
        else if (1.0 <= fVar1) {
          fVar1 = 1.0;
        }
        *(float *)(iVar5 + 0x1cc) = fVar1;
        param_1 = param_1 + 1;
      } while (param_1 < uVar4);
    }
  }
  (**(code **)(**(int **)(iVar2 + 4) + 0x18))();
  ExceptionList = local_10;
  return;
}

