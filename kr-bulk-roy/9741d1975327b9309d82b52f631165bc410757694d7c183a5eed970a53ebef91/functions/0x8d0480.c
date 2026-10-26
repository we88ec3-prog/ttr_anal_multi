
int FUN_008d0480(undefined4 *param_1)

{
  undefined1 *in_EAX;
  int iVar1;
  int local_c;
  undefined1 *local_8;
  
  local_8 = (undefined1 *)*param_1;
  iVar1 = 0;
  local_c = 0;
  if (local_8 < in_EAX) {
    do {
      if (iVar1 != 0) break;
      switch(*local_8) {
      case 0x25:
        FUN_008d02d0();
        break;
      case 0x28:
        iVar1 = FUN_008d0340(&local_8);
        break;
      case 0x3c:
        iVar1 = FUN_008d0420();
        break;
      case 0x7b:
        local_c = local_c + 1;
        break;
      case 0x7d:
        local_c = local_c + -1;
        if (local_c == 0) {
          local_8 = local_8 + 1;
          goto LAB_008d04c8;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < in_EAX);
    *param_1 = local_8;
    if (local_c != 0) {
      return 3;
    }
  }
  else {
LAB_008d04c8:
    *param_1 = local_8;
  }
  return iVar1;
}

