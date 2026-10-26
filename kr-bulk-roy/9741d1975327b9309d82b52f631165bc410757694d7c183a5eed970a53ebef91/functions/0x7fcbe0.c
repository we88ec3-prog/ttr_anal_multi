
void FUN_007fcbe0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  float *pfVar4;
  undefined4 uVar5;
  char *pcVar6;
  double dVar7;
  undefined1 local_e4 [8];
  float local_dc;
  int local_d8;
  int local_d4;
  float local_d0;
  undefined **local_cc [19];
  uint local_80;
  undefined4 local_70;
  uint local_6c;
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  float *local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092639b;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007fcb60(local_14);
  FUN_0072ee30(local_cc);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (((cVar1 != '\0') && (iVar2 = FUN_0072e2e0("Properties"), iVar2 != 0)) &&
     (iVar2 = FUN_0072e2e0("Bound"), iVar2 != 0)) {
    local_d4 = FUN_0072e360();
    iVar2 = local_d4;
    while (iVar2 != 0) {
      local_d8 = local_d4 + 0x44;
      iVar2 = FUN_007300a0(&DAT_00c0d66c);
      if (iVar2 == 0) {
        pcVar6 = (char *)0x0;
      }
      else {
        pcVar6 = (char *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          pcVar6 = *(char **)pcVar6;
        }
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      pcVar3 = pcVar6;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar6,(int)pcVar3 - (int)(pcVar6 + 1));
      local_8 = CONCAT31(local_8._1_3_,1);
      local_d0 = (float)FUN_007b6f30(local_30);
      if ((local_d0 == DAT_00fe3348) || (cVar1 = FUN_0049ae30(), cVar1 != '\0')) {
        local_dc = DAT_00fe3348;
        pfVar4 = &local_dc;
      }
      else {
        pfVar4 = &local_d0;
      }
      if (*pfVar4 == DAT_00fe3348) {
        pfVar4 = (float *)FUN_00891268(4);
        if (pfVar4 == (float *)0x0) {
          pfVar4 = (float *)0x0;
        }
        else {
          *pfVar4 = 128.0;
        }
        local_3c = 0xf;
        local_40 = 0;
        local_50[0] = local_50[0] & 0xffffff00;
        FUN_00403040(local_30,0,0xffffffff);
        local_8._0_1_ = 2;
        local_34 = pfVar4;
        uVar5 = FUN_0077e100(local_50);
        FUN_007e2910(&DAT_00fe3344,local_e4,uVar5);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (0xf < local_3c) {
          FUN_0089120c(local_50[0]);
        }
        local_3c = 0xf;
        local_40 = 0;
        local_50[0] = local_50[0] & 0xffffff00;
      }
      else {
        pfVar4 = *(float **)((int)*pfVar4 + 0x28);
      }
      iVar2 = FUN_007300a0("Value");
      if (iVar2 == 0) {
LAB_007fce19:
        local_d0 = 0.0;
      }
      else {
        pcVar6 = (char *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          pcVar6 = *(char **)pcVar6;
        }
        if (pcVar6 == (char *)0x0) goto LAB_007fce19;
        dVar7 = _atof(pcVar6);
        local_d0 = (float)dVar7;
      }
      *pfVar4 = local_d0;
      iVar2 = FUN_0072e3c0();
      local_8 = local_8 & 0xffffff00;
      local_d4 = iVar2;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
    }
  }
  local_cc[0] = TiXmlDocument::vftable;
  local_8 = 0xffffffff;
  if (0xf < local_6c) {
    local_8 = 0xffffffff;
    local_cc[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_80);
  }
  local_6c = 0xf;
  local_70 = 0;
  local_80 = local_80 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

