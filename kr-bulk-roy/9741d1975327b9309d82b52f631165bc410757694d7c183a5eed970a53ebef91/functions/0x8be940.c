
undefined ** FUN_008be940(void)

{
  uint uVar1;
  char *in_EAX;
  int iVar2;
  int unaff_ESI;
  
  if ((in_EAX != (char *)0x0) && (*in_EAX != '\0')) {
    iVar2 = FUN_008bdf60(unaff_ESI + 0x44094);
    if (iVar2 != 0) {
      uVar1 = *(uint *)(iVar2 + 4);
      if (0x52 < uVar1) {
        return (undefined **)((uVar1 - 0x53) * 0x10 + *(int *)(unaff_ESI + 0x4408c));
      }
      return &PTR_s_ADD_STYLE_NAME_00bd74f0 + uVar1 * 4;
    }
  }
  return (undefined **)0x0;
}

