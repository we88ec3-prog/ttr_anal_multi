
int FUN_008b81c0(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 == 0) {
    if (param_1 < 0) {
      return -param_4;
    }
  }
  else if (param_1 == 0) {
    param_4 = param_3;
    if (-1 < param_2) {
      return -param_3;
    }
  }
  else {
    if (param_4 == 0) {
      if (param_3 < 0) {
        param_2 = -param_2;
      }
      return param_2;
    }
    if (param_3 != 0) {
      FUN_008b7d00();
      FUN_008b7d00();
      if (local_8 <= local_10) {
        if (local_8 < local_10) {
          return -1;
        }
        if (local_c <= local_14) {
          return -(uint)(local_c < local_14);
        }
      }
      return 1;
    }
    bVar1 = -1 < param_4;
    param_4 = param_1;
    if (bVar1) {
      return -param_1;
    }
  }
  return param_4;
}

