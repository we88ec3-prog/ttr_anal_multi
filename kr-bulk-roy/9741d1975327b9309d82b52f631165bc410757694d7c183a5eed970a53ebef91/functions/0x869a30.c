
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00869a30(void)

{
  char cVar1;
  char local_14 [4];
  char local_10 [4];
  char local_c [4];
  undefined1 local_8 [4];
  
  _DAT_00fe37b8 = 0;
  _DAT_00fe37bc = 0;
  _DAT_00fe37c0 = 0;
  DAT_00fe37c4 = 0;
  cVar1 = FUN_00869930(0,local_8,local_14,local_c,local_10);
  if (cVar1 == '\0') {
    local_14[0] = 'G';
    local_14[1] = 'e';
    local_14[2] = 'n';
    local_14[3] = 'e';
    local_10[0] = 'r';
    local_10[1] = 'i';
    local_10[2] = 'c';
    local_10[3] = '_';
    local_c[0] = 'x';
    local_c[1] = '8';
    local_c[2] = '6';
    local_c[3] = '\0';
  }
  DAT_00fe37c0 = local_c[0];
  DAT_00fe37c0_1._0_1_ = local_c[1];
  DAT_00fe37c0_1._1_1_ = local_c[2];
  DAT_00fe37c0_1._2_1_ = local_c[3];
  DAT_00fe37bc = local_10[0];
  DAT_00fe37bc_1._0_1_ = local_10[1];
  DAT_00fe37bc_1._1_1_ = local_10[2];
  DAT_00fe37bc_1._2_1_ = local_10[3];
  DAT_00fe37b8 = local_14[0];
  DAT_00fe37b8_1._0_1_ = local_14[1];
  DAT_00fe37b8_1._1_1_ = local_14[2];
  DAT_00fe37b8_1._2_1_ = local_14[3];
  return &DAT_00fe37b8;
}

