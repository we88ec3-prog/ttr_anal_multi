
/* WARNING: Removing unreachable block (ram,0x004ba4c1) */
/* WARNING: Removing unreachable block (ram,0x004ba33b) */
/* WARNING: Removing unreachable block (ram,0x004ba1b5) */
/* WARNING: Removing unreachable block (ram,0x004ba02f) */
/* WARNING: Removing unreachable block (ram,0x004b9f6c) */
/* WARNING: Removing unreachable block (ram,0x004ba0f2) */
/* WARNING: Removing unreachable block (ram,0x004ba278) */
/* WARNING: Removing unreachable block (ram,0x004ba3fe) */
/* WARNING: Removing unreachable block (ram,0x004ba584) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9e30(void)

{
  undefined4 *unaff_ESI;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009490c6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00d6a674 = 0x4e554c4c;
  FUN_004add50(local_14);
  *unaff_ESI = Scene::CDecisionBase::vftable;
  unaff_ESI[0x17ab] = 0;
  unaff_ESI[0x17ac] = 1;
  unaff_ESI[0x17ad] = 0;
  unaff_ESI[0x17ae] = 0x168;
  unaff_ESI[0x17af] = 0;
  unaff_ESI[0x17b0] = 0;
  unaff_ESI[0x17b1] = 0;
  unaff_ESI[0x17b2] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  _eh_vector_constructor_iterator_
            (unaff_ESI + 0x17b4,0x38,10,(_func_void_void_ptr *)&LAB_004b9e20,FUN_004ba610);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 3;
  unaff_ESI[0x17b4] = 0;
  unaff_ESI[0x17b6] = 0x41c80000;
  unaff_ESI[0x17b5] = 0;
  unaff_ESI[0x17b8] = 0;
  *(undefined1 *)(unaff_ESI + 0x17b7) = 0;
  unaff_ESI[0x17b9] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x17be] = local_24;
  unaff_ESI[0x17bf] = local_20;
  unaff_ESI[0x17c0] = local_1c;
  unaff_ESI[0x17c1] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 4;
  unaff_ESI[0x17c4] = 0x41f00000;
  unaff_ESI[0x17c2] = 0;
  *(undefined1 *)(unaff_ESI + 0x17c5) = 0;
  unaff_ESI[0x17c3] = 0x40a00000;
  unaff_ESI[0x17c6] = 0;
  unaff_ESI[0x17c7] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x17cc] = local_24;
  unaff_ESI[0x17cd] = local_20;
  unaff_ESI[0x17ce] = local_1c;
  unaff_ESI[0x17cf] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 5;
  unaff_ESI[0x17d0] = 0;
  unaff_ESI[0x17d2] = 0x41f00000;
  unaff_ESI[0x17d1] = 0xc0a00000;
  *(undefined1 *)(unaff_ESI + 0x17d3) = 0;
  unaff_ESI[0x17d4] = 0;
  unaff_ESI[0x17d5] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x17da] = local_24;
  unaff_ESI[0x17db] = local_20;
  unaff_ESI[0x17dc] = local_1c;
  unaff_ESI[0x17dd] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 6;
  unaff_ESI[0x17de] = 0;
  unaff_ESI[0x17e0] = 0x420c0000;
  unaff_ESI[0x17e2] = 0;
  unaff_ESI[0x17df] = 0xc1200000;
  *(undefined1 *)(unaff_ESI + 0x17e1) = 0;
  unaff_ESI[0x17e3] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x17e8] = local_24;
  unaff_ESI[0x17e9] = local_20;
  unaff_ESI[0x17ea] = local_1c;
  unaff_ESI[0x17eb] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 7;
  unaff_ESI[0x17ee] = 0x42200000;
  unaff_ESI[0x17ec] = 0;
  *(undefined1 *)(unaff_ESI + 0x17ef) = 0;
  unaff_ESI[0x17ed] = 0xc0a00000;
  unaff_ESI[0x17f0] = 0;
  unaff_ESI[0x17f1] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x17f6] = local_24;
  unaff_ESI[0x17f7] = local_20;
  unaff_ESI[0x17f8] = local_1c;
  unaff_ESI[0x17f9] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 8;
  unaff_ESI[0x17fa] = 0;
  unaff_ESI[0x17fc] = 0x42200000;
  unaff_ESI[0x17fb] = 0xc1700000;
  *(undefined1 *)(unaff_ESI + 0x17fd) = 0;
  unaff_ESI[0x17fe] = 0;
  unaff_ESI[0x17ff] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x1804] = local_24;
  unaff_ESI[0x1805] = local_20;
  unaff_ESI[0x1806] = local_1c;
  unaff_ESI[0x1807] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 9;
  unaff_ESI[0x1808] = 0;
  unaff_ESI[0x180a] = 0x420c0000;
  unaff_ESI[0x180c] = 0;
  unaff_ESI[0x1809] = 0x41200000;
  *(undefined1 *)(unaff_ESI + 0x180b) = 0;
  unaff_ESI[0x180d] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x1812] = local_24;
  unaff_ESI[0x1813] = local_20;
  unaff_ESI[0x1814] = local_1c;
  unaff_ESI[0x1815] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._0_1_ = 10;
  unaff_ESI[0x1818] = 0x42200000;
  unaff_ESI[0x1816] = 0;
  *(undefined1 *)(unaff_ESI + 0x1819) = 0;
  unaff_ESI[0x1817] = 0x41700000;
  unaff_ESI[0x181a] = 0;
  unaff_ESI[0x181b] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x1820] = local_24;
  unaff_ESI[0x1821] = local_20;
  unaff_ESI[0x1822] = local_1c;
  unaff_ESI[0x1823] = local_18;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  unaff_ESI[0x1824] = 0;
  unaff_ESI[0x1826] = 0x42200000;
  unaff_ESI[0x1825] = 0x40a00000;
  *(undefined1 *)(unaff_ESI + 0x1827) = 0;
  unaff_ESI[0x1828] = 0;
  unaff_ESI[0x1829] = 0x3f99999a;
  FUN_004bb2b0(&local_34);
  unaff_ESI[0x182e] = local_24;
  unaff_ESI[0x182f] = local_20;
  unaff_ESI[0x1830] = local_1c;
  unaff_ESI[0x1831] = local_18;
  DAT_00fb7350 = 1;
  if ((_DAT_00fb734c & 1) == 0) {
    _DAT_00fb734c = _DAT_00fb734c | 1;
    _atexit((_func_4879 *)&DAT_00bcd0b0);
  }
  DAT_00fb7350 = 1;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

