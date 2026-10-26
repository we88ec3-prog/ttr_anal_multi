
int FUN_008ca8e0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  iVar1 = FUN_008ca450(param_1,"CHARSET_REGISTRY",&local_14);
  if (iVar1 == 0) {
    iVar1 = FUN_008ca450(param_1,"CHARSET_ENCODING",&local_c);
    if (iVar1 == 0) {
      if ((local_14 == 1) && (local_c == 1)) {
        *param_2 = local_8;
        *param_3 = local_10;
        return 0;
      }
      iVar1 = 6;
    }
  }
  return iVar1;
}

