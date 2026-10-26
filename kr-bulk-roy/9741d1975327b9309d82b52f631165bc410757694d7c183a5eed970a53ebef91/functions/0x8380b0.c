
void FUN_008380b0(void)

{
  int in_EAX;
  int *piVar1;
  int local_c;
  int local_8;
  
  piVar1 = (int *)PTR_PTR_00d639fc;
  if ((undefined **)PTR_PTR_00d639fc == &PTR_DAT_00f7ae98) {
    if (DAT_00fba7c7 != '\0') {
      piVar1 = (int *)FUN_00837e90();
      DAT_00fba7c7 = '\0';
    }
    if (DAT_00fba920 != '\0') {
      FID_conflict__wprintf
                ("********************************* PROFILE *********************************\n");
      FUN_00837ed0();
      FID_conflict__wprintf
                ("*********************************   END   *********************************\n\n");
      DAT_00fba920 = '\0';
      piVar1 = (int *)PTR_PTR_00d639fc;
    }
  }
  if (in_EAX != *piVar1) {
    piVar1 = (int *)FUN_00837e20(in_EAX);
    PTR_PTR_00d639fc = (undefined *)piVar1;
  }
  piVar1[0xc] = piVar1[0xc] + 1;
  FUN_008381b0(&local_c);
  piVar1[4] = local_c;
  piVar1[5] = local_8;
  return;
}

