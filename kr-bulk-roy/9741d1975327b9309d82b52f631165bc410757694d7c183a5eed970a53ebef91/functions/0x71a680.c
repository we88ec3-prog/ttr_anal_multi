
undefined4 FUN_0071a680(char param_1,char param_2)

{
  char in_CL;
  char in_DL;
  
  if (param_1 == '\0') {
    if (in_CL != '\0') {
      if (in_CL != '<') {
        return 1;
      }
      if ((in_DL == '\0') && (param_2 == '?')) {
        return 3;
      }
      return 3;
    }
    if (in_DL == -2) {
      if (param_2 != -1) {
        return 1;
      }
      return 6;
    }
    if (in_DL != '\0') {
      return 1;
    }
    if (param_2 != '<') {
      return 1;
    }
    return 6;
  }
  if (param_1 == -1) {
    if (in_CL != -2) {
      return 1;
    }
  }
  else {
    if (param_1 == -2) {
      if (in_CL != -1) {
        return 1;
      }
      return 3;
    }
    if (param_1 == -0x11) {
      return 1;
    }
    if (param_1 != '<') {
      return 1;
    }
    if (in_CL != '\0') {
      if (in_CL == '?') {
        return 1;
      }
      if (in_CL == '\0') {
        return 2;
      }
      return 1;
    }
  }
  if ((in_DL == '\0') && (param_2 == '\0')) {
    return 5;
  }
  return 2;
}

