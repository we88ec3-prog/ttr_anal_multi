
int FUN_00858690(int param_1,int param_2,int param_3)

{
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00906aa1;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  uStack_7 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x14) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_0052f3b0(param_3,param_1);
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    }
    param_3 = param_3 + 0x14;
  }
  *unaff_FS_OFFSET = local_10;
  return param_3;
}

