
void FUN_00687660(undefined4 param_1)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 in_ECX;
  int unaff_EDI;
  undefined1 auStack_b8 [4];
  undefined4 *local_b4;
  int local_b0;
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_98;
  uint local_94;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009485be;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_b8;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff40;
  ExceptionList = &local_14;
  *(undefined4 *)(unaff_EDI + 0x178) = param_1;
  *(undefined4 *)(unaff_EDI + 0x17c) = in_ECX;
  cVar2 = FUN_006891e0(unaff_EDI);
  if (cVar2 == '\0') {
    FUN_00688bf0(*(undefined4 *)(unaff_EDI + 0x178));
  }
  else {
    local_b4 = (undefined4 *)FUN_00891268(0x14,uVar3);
    if (local_b4 == (undefined4 *)0x0) {
      local_b4 = (undefined4 *)0x0;
    }
    else {
      *local_b4 = FoxUI::FXUIEvent::vftable;
      local_b4[1] = 0xffffffff;
      local_b4[2] = 0xffffffff;
      local_b4[3] = 0;
      local_b4[4] = 0xf437a;
    }
    FUN_007572f0(&DAT_00bed1fc);
    local_c._1_3_ = 0;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_c._0_1_ = 0;
    local_ac = 0xe6;
    FUN_005740f0(&local_ac);
    if (local_b0 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar4 = FUN_004068f0();
    local_c._0_1_ = 2;
    FUN_007574a0(uVar4);
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c._0_1_ = 4;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_c._0_1_ = 3;
    FUN_007531a0(&DAT_00f94810,local_8c,local_54,local_b4,unaff_EDI);
    local_c = CONCAT31(local_c._1_3_,2);
    FUN_00757640(local_8c);
    if (7 < local_94) {
      FUN_0089120c(local_a8);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8 = local_a8 & 0xffff0000;
    local_c = 0xffffffff;
    FUN_00757640(local_54);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_b8);
  return;
}

