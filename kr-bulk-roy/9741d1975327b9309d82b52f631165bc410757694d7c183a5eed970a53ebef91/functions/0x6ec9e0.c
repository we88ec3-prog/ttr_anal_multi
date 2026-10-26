
int FUN_006ec9e0(uint *param_1,uint *param_2)

{
  if (*param_1 <= *param_2) {
    if (*param_1 < *param_2) {
      return -1;
    }
    if (param_1[1] <= param_2[1]) {
      if (param_1[1] < param_2[1]) {
        return -1;
      }
      if ((int)param_1[3] <= (int)param_2[3]) {
        if ((int)param_1[3] < (int)param_2[3]) {
          return -1;
        }
        if (param_1[2] <= param_2[2]) {
          return -(uint)(param_1[2] < param_2[2]);
        }
      }
    }
  }
  return 1;
}

