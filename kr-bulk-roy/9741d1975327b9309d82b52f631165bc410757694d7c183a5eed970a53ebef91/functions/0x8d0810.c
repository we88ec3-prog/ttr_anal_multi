
void FUN_008d0810(uint *param_1,int *param_2,int param_3,int *param_4)

{
  int *piVar1;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int *local_8;
  
  *param_4 = -1;
  FUN_008d06f0(param_1,&local_1c);
  if (local_14 == 3) {
    local_10 = param_1[2];
    local_c = *param_1;
    local_8 = param_2 + param_3 * 3;
    *param_1 = local_1c + 1U;
    param_1[2] = local_18 - 1U;
    piVar1 = param_2;
    if (local_1c + 1U < local_18 - 1U) {
      do {
        FUN_008d06f0(param_1,&local_1c);
        if (local_14 == 0) break;
        if ((param_2 != (int *)0x0) && (piVar1 < local_8)) {
          *piVar1 = local_1c;
          piVar1[1] = local_18;
          piVar1[2] = local_14;
        }
        piVar1 = piVar1 + 3;
      } while (*param_1 < param_1[2]);
    }
    *param_4 = ((int)piVar1 - (int)param_2) / 0xc;
    *param_1 = local_c;
    param_1[2] = local_10;
  }
  return;
}

