
undefined4 FUN_008d14e0(void)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 *unaff_EBX;
  char *unaff_EDI;
  char *local_8;
  
  pcVar2 = (char *)*unaff_EBX;
  local_8 = pcVar2;
  uVar1 = FUN_008d13f0(&local_8);
  if (local_8 == pcVar2) {
    return 0;
  }
  if ((local_8 < unaff_EDI) && (*local_8 == '#')) {
    pcVar2 = local_8 + 1;
    local_8 = pcVar2;
    uVar1 = FUN_008d13f0(&local_8);
    if (local_8 == pcVar2) {
      return 0;
    }
  }
  *unaff_EBX = local_8;
  return uVar1;
}

