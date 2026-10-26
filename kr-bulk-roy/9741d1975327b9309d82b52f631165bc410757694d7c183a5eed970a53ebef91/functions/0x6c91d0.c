
void FUN_006c91d0(void)

{
  int in_ECX;
  undefined4 uStack_7c;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined1 auStack_58 [56];
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091f452;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_7c;
  ExceptionList = &local_14;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xffffff78);
  FUN_006c9750();
  (**(code **)(**(int **)(in_ECX + 0xf0) + 0x198))(0x65);
  FUN_0041f460(&DAT_00c294cc);
  puStack_10 = (undefined1 *)0x0;
  uStack_68 = 7;
  uStack_6c = 0;
  uStack_7c = (uint)uStack_7c._2_2_ << 0x10;
  FUN_004026e0(auStack_58,0,0xffffffff);
  puStack_10._0_1_ = 1;
  FUN_004026e0(&uStack_7c,0,0xffffffff);
  puStack_10 = (undefined1 *)((uint)puStack_10._1_3_ << 8);
  if (7 < uStack_68) {
    FUN_0089120c(uStack_7c);
  }
  uStack_7c = uStack_7c & 0xffff0000;
  uStack_68 = 7;
  uStack_6c = 0;
  FUN_0066eee0();
  FUN_00653570();
  FUN_006c9840();
  FUN_006c09c0(600);
  FUN_006c09c0(700);
  puStack_10 = (undefined1 *)0xffffffff;
  FUN_00757640(auStack_58);
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff80);
  return;
}

