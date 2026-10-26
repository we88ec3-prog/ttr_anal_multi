
void FUN_0053e230(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *in_ECX;
  undefined **local_b0 [19];
  uint local_64;
  undefined4 local_54;
  uint local_50;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923283;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = local_34[0] & 0xffffff00;
  FUN_00402a70("Field/Cluster/",0xe);
  local_8 = 0;
  pcVar2 = in_ECX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_ECX,(int)pcVar2 - (int)(in_ECX + 1));
  FUN_0072ef00(local_b0,local_34);
  local_8 = CONCAT31(local_8._1_3_,1);
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    FUN_0072e2e0("MON_CLUST");
    FUN_0072e2e0("CLUSTERSET");
    iVar3 = FUN_0072e2e0("PRELOADSET");
    if (iVar3 != 0) {
      for (piVar4 = (int *)FUN_0072e2e0("IMAGE"); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x10]
          ) {
        iVar3 = (**(code **)(*piVar4 + 0x14))();
        if (iVar3 != 0) {
          iVar3 = FUN_007300a0(&DAT_00bfb82c);
          if (iVar3 != 0) {
            puVar5 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 != (undefined4 *)0x0) {
              FUN_008917b4(puVar5);
            }
          }
          FUN_004a8680();
        }
      }
    }
  }
  local_8 = local_8 & 0xffffff00;
  local_b0[0] = TiXmlDocument::vftable;
  if (0xf < local_50) {
    FUN_0089120c(local_64);
  }
  local_50 = 0xf;
  local_54 = 0;
  local_64 = local_64 & 0xffffff00;
  FUN_0072e040();
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

