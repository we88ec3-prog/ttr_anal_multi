
undefined4 FUN_008e9fe0(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 0x1ec);
  if (iVar1 != 0) {
    local_8 = 0;
    if (0 < *(int *)(iVar1 + 0x20)) {
      param_1 = 0;
      do {
        piVar3 = (int *)(*(int *)(iVar1 + 0x1c) + param_1);
        if (*piVar3 == param_3) {
          if (param_2 < piVar3[1]) {
            *param_4 = piVar3[2];
          }
          else if (piVar3[3] < param_2) {
            *param_4 = piVar3[4];
          }
          else {
            iVar2 = FUN_008b7dc0(param_2 - piVar3[1],piVar3[4] - piVar3[2],piVar3[3] - piVar3[1]);
            *param_4 = iVar2 + piVar3[2];
          }
        }
        param_1 = param_1 + 0x14;
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(iVar1 + 0x20));
    }
    return 0;
  }
  return 6;
}

