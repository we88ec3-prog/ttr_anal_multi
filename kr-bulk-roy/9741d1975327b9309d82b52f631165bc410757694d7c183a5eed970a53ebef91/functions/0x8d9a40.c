
undefined4 FUN_008d9a40(int param_1)

{
  int *in_ECX;
  
  if ((0 < *in_ECX) && (0 < in_ECX[1])) {
    FUN_008d9440();
    if (param_1 != 0) {
      if (param_1 == 1) {
        FUN_008d9530();
        return 0;
      }
      if (param_1 != 2) {
        return 3;
      }
      FUN_008d9620();
      return 0;
    }
    FUN_008d9480();
  }
  return 0;
}

