
undefined4 FUN_0071f590(void)

{
  int iVar1;
  char cVar2;
  undefined1 *in_ECX;
  
  switch(*in_ECX) {
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x38:
  case 0x39:
    goto switchD_0071f5a5_caseD_f;
  default:
    if ((*(int *)(in_ECX + 4) != 0) && (cVar2 = FUN_0071f590(), cVar2 == '\0')) {
      return 0;
    }
    for (iVar1 = *(int *)(in_ECX + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      cVar2 = FUN_0071f590();
      if (cVar2 == '\0') {
        return 0;
      }
    }
switchD_0071f5a5_caseD_f:
    return 1;
  case 0x16:
    return 0;
  }
}

