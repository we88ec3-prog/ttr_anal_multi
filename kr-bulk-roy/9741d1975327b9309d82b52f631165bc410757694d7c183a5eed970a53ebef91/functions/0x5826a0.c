
void FUN_005826a0(void)

{
  int *piVar1;
  int unaff_EDI;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  float local_120;
  float local_11c;
  float local_118;
  char local_114;
  undefined1 local_113 [255];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938c5e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(local_14);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)FUN_00714770("Table/Book.txt",&DAT_00c0cd90);
  if (piVar1 != (int *)0x0) {
    local_114 = '\0';
    _memset(local_113,0,0xff);
    (**(code **)(*piVar1 + 8))(&local_114,0xff);
    FID_conflict__sscanf(&local_114,"%f %f %f",&local_12c,&local_128,&local_124);
    _memset(&local_114,0,0x100);
    (**(code **)(*piVar1 + 8))(&local_114,0xff);
    FID_conflict__sscanf(&local_114,"%f %f %f",&local_120,&local_11c,&local_118);
    _memset(&local_114,0,0x100);
    local_120 = local_120 * 0.017453292;
    local_11c = local_11c * 0.017453292;
    local_118 = local_118 * 0.017453292;
    (**(code **)(*piVar1 + 4))();
  }
  *(undefined4 *)(unaff_EDI + 0x1c) = local_12c;
  *(undefined4 *)(unaff_EDI + 0x20) = local_128;
  *(float *)(unaff_EDI + 0x28) = local_120;
  *(undefined4 *)(unaff_EDI + 0x24) = local_124;
  *(float *)(unaff_EDI + 0x2c) = local_11c;
  *(float *)(unaff_EDI + 0x30) = local_118;
  FUN_0057f950();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

