
void FUN_008a491c(undefined2 *param_1,int param_2)

{
  int iVar1;
  int *in_EAX;
  int unaff_EBX;
  int *unaff_EDI;
  
  iVar1 = *unaff_EDI;
  if (((*(byte *)(unaff_EBX + 0xc) & 0x40) == 0) || (*(int *)(unaff_EBX + 8) != 0)) {
    *unaff_EDI = 0;
    if (0 < param_2) {
      do {
        param_2 = param_2 + -1;
        write_char(*param_1);
        param_1 = param_1 + 1;
        if (*in_EAX == -1) {
          if (*unaff_EDI != 0x2a) break;
          write_char(0x3f);
        }
      } while (0 < param_2);
      if (*unaff_EDI != 0) {
        return;
      }
    }
    *unaff_EDI = iVar1;
  }
  else {
    *in_EAX = *in_EAX + param_2;
  }
  return;
}

