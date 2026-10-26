
void FUN_004f9d80(void)

{
  int *piVar1;
  int iVar2;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  char local_114;
  undefined1 local_113 [255];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009221e5;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fe1a90 = 0;
  DAT_00fe1a94 = 0;
  DAT_00fe1a98 = 0;
  local_8 = 0;
  piVar1 = (int *)FUN_00714770("Table/_PositionList.txt",&DAT_00c0cd90,local_14);
  local_114 = '\0';
  _memset(local_113,0,0xff);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(&local_114,0x100);
    FID_conflict__sscanf(&local_114,"%d",&local_12c);
    iVar2 = 0;
    if (0 < local_12c) {
      do {
        _memset(&local_114,0,0x100);
        (**(code **)(*piVar1 + 8))(&local_114,0x100);
        FID_conflict__sscanf
                  (&local_114,"%f %f %f %f %f",&local_140,&local_144,&local_14c,&local_130,
                   &local_148);
        local_13c = local_140;
        local_138 = local_144;
        local_134 = local_14c;
        local_128 = local_140;
        local_118 = local_130;
        local_124 = local_144;
        local_120 = local_14c;
        local_11c = local_148;
        FUN_004f9ff0();
        iVar2 = iVar2 + 1;
      } while (iVar2 < local_12c);
    }
    (**(code **)(*piVar1 + 4))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

